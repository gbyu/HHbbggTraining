#Optimize a dense network with Bayesian optimization
base_dir = "/eos/user/i/ivovtin/HHggbb/HHbbgg_ETH_devel/Training/2017/flattrees_st_cuts/"

#Usual setup: Loading pandas DataFrames, creating training and testing dataset
import uproot
import numpy as np
import pandas as pd
import h5py
import torch
import torch.nn as nn
import time

# fix random seed for reproducibility
seed = 7
np.random.seed(seed)

treename = 'bbggSelectionTree'
filename = {}
upfile = {}
params = {}
df = {}

filename['VV'] = base_dir+'output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts.root'
filename['bkg'] = base_dir+'output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root'

VARS = ['absCosThetaStar_CS','PhoJetMinDr'] # choose which vars to use (2d)
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj'.split(",")
#
upfile['VV'] = uproot.open(filename['VV'])
params['VV'] = upfile['VV'][treename].arrays(VARS)
upfile['bkg'] = uproot.open(filename['bkg'])
params['bkg'] = upfile['bkg'][treename].arrays(VARS)

df['VV'] = pd.DataFrame(params['VV'],columns=VARS)
df['bkg'] = pd.DataFrame(params['bkg'],columns=VARS)

# cut out undefined variables VARS[0] and VARS[1] > -999
df['VV']= df['VV'][(df['VV'][VARS[0]] > -999) & (df['VV'][VARS[1]] > -999)]
df['bkg']= df['bkg'][(df['bkg'][VARS[0]] > -999) & (df['bkg'][VARS[1]] > -999)] 

# add isSignal variable
df['VV']['isSignal'] = np.ones(len(df['VV'])) 
df['bkg']['isSignal'] = np.zeros(len(df['bkg'])) 

df_all = pd.concat([df['VV'],df['bkg']])
dataset = df_all.values

NDIM = len(VARS)

X = dataset[:,0:NDIM]
Y = dataset[:,NDIM]

from sklearn.model_selection import train_test_split
#X_train_val, X_test, Y_train_val, Y_test = train_test_split(X, Y, test_size=0.1, random_state=7)
#X_train, X_val, Y_train, Y_val = train_test_split(X_train_val, Y_train_val, test_size=0.2, random_state=7)
X_train_val, X_test, Y_train_val, Y_test = train_test_split(X, Y, test_size=0.5, random_state=7)
X_train, X_val, Y_train, Y_val = train_test_split(X_train_val, Y_train_val, test_size=0.5, random_state=7)

# preprocessing: standard scalar
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler().fit(X_train_val)
X_test = scaler.transform(X_test)
X_train = scaler.transform(X_train)
X_val = scaler.transform(X_val)

# Dataset and DataLoader
from torch.utils.data import Dataset, DataLoader

class HiggsDataset(Dataset):
  def __init__(self, xdata, label):
      self.xdata = torch.from_numpy(xdata).float()
      self.label = torch.from_numpy(label).float()

  def __len__(self):
      return len(self.xdata)

  def __getitem__(self, idx):
      return self.xdata[idx], self.label[idx]
    
train_data = HiggsDataset(X_train, Y_train)
train_loader = DataLoader(dataset=train_data, batch_size=1024, shuffle=True)

# Get validation data ready
val_data = torch.from_numpy(X_val).float()
val_label = torch.from_numpy(Y_val).float()



#Visualize the improvement
#Let's see how Bayesian optimization improves the accuracy

from skopt import gp_minimize
from skopt.space import Real, Integer
from skopt.utils import use_named_args

def build_custom_model(num_hiddens=2, initial_node=50, 
                          dropout=0.5):
  
    modules = []
    modules.append(nn.Linear(NDIM, initial_node))
    modules.append(nn.ReLU())
      
    for i in range(num_hiddens):
      previous_dim = max(1,int(round(initial_node/np.power(2,i))))
      next_dim = max(1,int(round(initial_node/np.power(2,i+1))))
      modules.append(nn.Linear(previous_dim, next_dim))
      modules.append(nn.Dropout(p=dropout, inplace=True))
      modules.append(nn.ReLU())
      
    # Last layer has output size 1
    latest_dim = max(1,int(round(initial_node/np.power(2,num_hiddens))))
    modules.append(nn.Linear(latest_dim,1))
    modules.append(nn.Sigmoid())
    model = nn.Sequential(*modules)
    return model

#def train(model, learning_rate = 1e-3):
def train(model, learning_rate = 1e-1):
  
    losses, val_losses = [], []
    min_loss, stale_epochs = 100., 0
    # Use Binary Cross Entropy as our loss function.
    loss_fn = torch.nn.BCELoss()
    
    # Optimize the model parameters using the Adam optimizer.
    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
    for t in xrange(500):
      batch_loss = []

      for x_train, y_train in train_loader:

          # Forward pass: make a prediction for each x event in batch b.
          y_pred = model(x_train)

          # Get the labels.
          label = y_train
          y = label.view_as(y_pred)  # reshape label data to the shape of y_pred

          # Compute and print loss.
          loss = loss_fn(y_pred, y)
          batch_loss.append(loss.item())

          # Before the backward pass, use the optimizer object to zero all of the
          # gradients for the variables it will update (which are the learnable
          # weights of the model). This is because by default, gradients are
          # accumulated in buffers( i.e, not overwritten) whenever .backward()
          # is called. Checkout docs of torch.autograd.backward for more details.
          optimizer.zero_grad()

          # Backward pass: compute gradient of the loss with respect to model
          # parameters
          loss.backward()

          # Calling the step function on an Optimizer makes an update to its
          # parameters
          optimizer.step()

      # Let's look at the validation set.

      # Torch keeps track of each operation performed on a Tensor, so that it can take the gradient later.
      # We don't need to store this information when looking at validation data, so turn it off with
      # torch.no_grad().
      with torch.no_grad():

          # Forward pass on validation set.
          output = model(val_data)

          # Get labels and compute loss again
          val_y = val_label.view_as(output)
          val_loss = loss_fn(output, val_y)
          
      this_loss = np.mean(batch_loss)
      losses.append(this_loss)
      this_val_loss = val_loss.item()
      val_losses.append(this_val_loss)

      # Monitor the loss function to prevent overtraining.
      if stale_epochs > 20:
          break

      if this_val_loss < min_loss:
          min_loss = this_val_loss
          stale_epochs = 0
      else:
          stale_epochs += 1

      # Return the best validation loss as the figure of merit
    return min(val_losses)

space  = [Integer(1, 3, name='hidden_layers'),
          Integer(5, 100, name='initial_nodes'),
          Real(0.0,0.9,name='dropout'),
          Real(10**-5, 10**-1, "log-uniform", name='learning_rate'),
          ]

@use_named_args(space)
def objective(**X):
    print("New configuration: {}".format(X))

    model = build_custom_model(num_hiddens=X['hidden_layers'], initial_node=X['initial_nodes'], 
                      dropout=X['dropout'])

    fom = train(model, learning_rate=X['learning_rate'])                                                  #*train model
    
    return fom

begt = time.time()
#res_gp = gp_minimize(objective, space, n_calls=10, n_random_starts=5, random_state=3, verbose=True)
res_gp = gp_minimize(objective, space, n_calls=3, n_random_starts=2, random_state=1, verbose=True)
print("Finish optimization in {}s".format(time.time()-begt))

print("Best parameters: \
\nbest_hidden_layers = {} \
\nbest_initial_nodes = {} \
\nbest_dropout = {} \
\nbest_learning_rate = {}".format(res_gp.x[0],
                                 res_gp.x[1],
                                 res_gp.x[2],
                                 res_gp.x[3]))

