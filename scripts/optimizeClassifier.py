import os
#import sys; sys.path.append("~/HHbbgg_ETH_devel/Training/python") # to load packages
import sys; sys.path.append("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/python") # to load packages
import training_utils as utils
import numpy as np
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import plotting_utils as plotting
reload(plotting)
import postprocessing_utils as postprocessing
reload(postprocessing)

ntuples = '2016'
# "%" sign allows to interpret the rest as a system command
#%env data=$utils.IO.ldata$ntuples
#files = ! ls $data | sort -t_ -k 3 -n
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
#signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2016_ptmjj.root" in s]
#bkgr = [s for s in files if "DoubleEG_2016_ptmjj.root" in s]
signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2016.root" in s]
bkgr = [s for s in files if "DoubleEG_2016.root" in s]

utils.IO.add_signal(ntuples,signal,1)
utils.IO.add_background(ntuples,bkgr,-1)

ntuples = '2017'
# "%" sign allows to interpret the rest as a system command
#%env data=$utils.IO.ldata$ntuples
#files = ! ls $data | sort -t_ -k 3 -n
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
#signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2017_ptmjj.root" in s]
#bkgr = [s for s in files if "DoubleEG_2017_ptmjj.root" in s]
signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2017.root" in s]
bkgr = [s for s in files if "DoubleEG_2017.root" in s]
utils.IO.add_signal(ntuples,signal,-1)
utils.IO.add_background(ntuples,bkgr,-1)


for i in range(len(utils.IO.backgroundName)):        
    print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]
for i in range(len(utils.IO.signalName)):    
    print "using signal file n."+str(i)+": "+utils.IO.signalName[i]

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#standart of input values 
branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,noexpand:leadingJet_bRegNNResolution/leadingJet_pt,noexpand:subleadingJet_bRegNNResolution/subleadingJet_pt,noexpand:sigmaMJets/Mjj,rho'.split(",")
#st values with adding pt_gg/m_gg
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,noexpand:leadingJet_bRegNNResolution/leadingJet_pt,noexpand:subleadingJet_bRegNNResolution/subleadingJet_pt,noexpand:sigmaMJets/Mjj,rho,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass'.split(",")
#st values with adding pt_gg/m_gg, pt_jj/M_jj
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,noexpand:leadingJet_bRegNNResolution/leadingJet_pt,noexpand:subleadingJet_bRegNNResolution/subleadingJet_pt,noexpand:sigmaMJets/Mjj,rho,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetotherDr'.split(",")

branch_names = [c.strip() for c in branch_names]
#branch_names = (b.replace(" ", "_") for b in branch_names)
#branch_names = list(b.replace("-", "_") for b in branch_names)
print branch_names

import pandas as pd
import root_pandas as rpd
from root_numpy import root2array, list_trees

#print list_trees('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root')
for i in range(len(utils.IO.backgroundName)):        
    print list_trees(utils.IO.backgroundName[i])
        
preprocessing.set_signals("GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0",branch_names,True)
preprocessing.set_backgrounds("Data_13TeV_DoubleHTag_0",branch_names,True) 
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.set_variables(branch_names)

#relative weighting between components of one class is kept, all classes normalized to the same
#weights_sig=preprocessing.weight_signal_with_resolution(weights_sig,y_sig)
weights_bkg,weights_sig=preprocessing.normalize_process_weights(weights_bkg,y_bkg,weights_sig,y_sig)

X_bkg,y_bkg,weights_bkg = preprocessing.randomize(X_bkg,y_bkg,weights_bkg)
X_sig,y_sig,weights_sig = preprocessing.randomize(X_sig,y_sig,weights_sig)

print X_bkg.shape
print y_bkg.shape
#bbggTrees have by default signal and CR events, let's be sure that we clean it
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.clean_signal_events(X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig)
print X_bkg.shape
print y_bkg.shape

y_total_train = preprocessing.get_total_training_sample(y_sig,y_bkg).ravel()
X_total_train = preprocessing.get_total_training_sample(X_sig,X_bkg)

y_total_test = preprocessing.get_total_test_sample(y_sig,y_bkg).ravel()
X_total_test = preprocessing.get_total_test_sample(X_sig,X_bkg)

w_total_train = preprocessing.get_total_training_sample(weights_sig,weights_bkg).ravel()
w_total_test = preprocessing.get_total_test_sample(weights_sig,weights_bkg).ravel()

import xgboost as xgb
clf = xgb.XGBClassifier(max_depth=5,learning_rate=0.1,n_estimators=50, min_child_weight=1e-5, nthread= 12)

import optimization_utils as optimization
reload(optimization)
param_grid = {"n_estimators": [500,1000,1500,2000],
              "max_depth": [3, 4, 5, 6, 8, 10],                                                                                                                                                                                                
              'learning_rate': [0.01, 0.05, 0.1],    
              'reg_alpha':[0.01, 0.1, 1],
              'reg_lambda':[0.01, 0.1, 1]
              }
#param_grid = {"n_estimators": [500,1000,1500,2000],
#              "max_depth": [5, 10, #15],                                                                                                                                                                                                
#              'learning_rate': [0.1, 0.2, 1.],    
#              'reg_alpha':[1e-5, 1e-2, 0.1, 1, 100],
#              'reg_lambda':[1e-5, 1e-2, 0.1, 1, 100]
#              }
#param_grid = {"n_estimators": [60,80],
#              "max_depth": [3,4]                                                                                                                                                                                                
#              }              
#utils.optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=500)
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nJobs=5)
optimization.optimize_parameters_gridCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nJobs=4)


# In[ ]:



