import os
#import sys; sys.path.append("~/HHbbgg_ETH_devel/Training/python") # to load packages
import sys; sys.path.append("/afs/cern.ch/user/i/ivovtin/HHggbb/HHbbgg_ETH/Training/python") # to load packages
import training_utils as utils
import numpy as np
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
#import plotting_utils as plotting
#reload(plotting)
import postprocessing_utils as postprocessing
reload(postprocessing)

ntuples = '2017/flattrees_st_cuts'
# "%" sign allows to interpret the rest as a system command
#%env data=$utils.IO.ldata$ntuples
#files = ! ls $data | sort -t_ -k 3 -n
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts.root" in s]
diphotonJets = [s for s in files if "output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root" in s]
gJets_lowPt = [s for s in files if "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root" in s]
gJets_highPt = [s for s in files if "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root" in s]

utils.IO.add_signal(ntuples,signal,1)
utils.IO.add_background(ntuples,diphotonJets,-1)
utils.IO.add_background(ntuples,gJets_lowPt,-1)
utils.IO.add_background(ntuples,gJets_highPt,-1)


for i in range(len(utils.IO.backgroundName)):        
    print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]
for i in range(len(utils.IO.signalName)):    
    print "using signal file n."+str(i)+": "+utils.IO.signalName[i]

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#standart of input values 
branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj'.split(",")
#st values with adding pt_gg/m_gg
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass'.split(",")
#st values with adding pt_gg/m_gg, pt_jj/M_jj
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetotherDr'.split(",")

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
        
preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names)
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
clf = xgb.XGBClassifier(max_depth=4,learning_rate=0.2,n_estimators=50, min_child_weight=1e-5, nthread= 20)
#clf = xgb.XGBClassifier(base_score=0.5, colsample_bylevel=1, colsample_bytree=1,
#       gamma=0, learning_rate=0.1, max_delta_step=0, max_depth=3, min_child_weight=1e-05, missing=None, n_estimators=1000, nthread=12,
#       objective='binary:logistic', reg_alpha=0, reg_lambda=0.01,
#       scale_pos_weight=1, seed=0, silent=True, subsample=1)

import optimization_utils as optimization
reload(optimization)
#param_grid = {
#              'n_estimators': [1000,1500,2000],
#              'learning_rate': [0.1,0.2,1.],    
#              'max_depth': [3,5,8]
#              }
#1
#param_grid = {
#              'n_estimators': [1000,1500,2000],
#              'learning_rate': [0.1, 0.2,0.5,1.],    
#              'max_depth': [3,5,6,8,10],
#              'reg_alpha':[0,1e-5, 0.01, 0.05, 0.1, 1],
#              'reg_lambda':[0,1e-5, 0.01,0.05, 0.1, 1],
#              'min_child_weight':[1e-5, 1e-4, 1e-3]
#              }
#2
#param_grid = {
#              'n_estimators': [1000,1500,2000],
#              'learning_rate': [0.1, 0.2,1.],    
#              'max_depth': [3,5,8,10],
#              'reg_alpha':[0,1e-5, 0.01, 0.1, 1],
#              'reg_lambda':[0,1e-5, 0.01, 0.1, 1],
#              'min_child_weight':[1e-5, 1e-4]
#              }
#3
#param_grid = {
#              'n_estimators': [500,800,900],
#              'learning_rate': [0.1, 0.2,1.],    
#              'max_depth': [3,5,8,10],
#              'reg_alpha':[0,1e-5, 0.01, 0.1, 1],
#              'reg_lambda':[0,1e-5, 0.01, 0.1, 1]
#              }
#4
#param_grid = {
#              'n_estimators': [1000,1500,2000],
#              'learning_rate': [0.1, 0.5,1.],    
#              'max_depth': [4,6,8,10],
#              'reg_alpha':[0, 0.01, 0.1, 1],
#              'reg_lambda':[0, 0.01, 0.1, 1]
#              }
#5, 6, 7, 8, 9
param_grid = {
              'n_estimators': [1000,1500,2000],
              'learning_rate': [0.1, 0.2,1.],    
              'max_depth': [3,5,8,10],
              'reg_alpha':[0,1e-5, 0.01, 0.1, 1],
              'reg_lambda':[0,1e-5, 0.01, 0.1, 1],
              'min_child_weight':[1e-5, 1e-4]
              }
#10
#param_grid = {
#              'n_estimators': [1000,1500,2000],
#              'learning_rate': [0.1, 0.2,1.],    
#              'max_depth': [3,5,8,10]
#              }
#param_grid = {"n_estimators": [60,80],
#              "max_depth": [3,4]                                                                                                                                                   }              
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=500,nJobs=8)
#3.68 h
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10)
#5.2 h
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=30)
#7.5 h
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=4,nIter=10,nJobs=10)
#13.6 h
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=10,nJobs=10)
#+ max_depth -6  + reg_alpha' 0 + reg_lambda 0 + learning_rate 0.5
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=30,nJobs=10)
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=50,nJobs=10)
#+min_child_weight
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=100,nJobs=10)
#1 ->6 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#2 ->7 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#3 ->8 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#4 ->9 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#5 ->10 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=4,nIter=10,nJobs=10)
#6 ->11 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=10,nJobs=10)
#7 ->12 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=30,nJobs=10)
#8 ->13 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=50,nJobs=10)
#9 ->14 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#10 ->15 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=10,nJobs=10)
#9 ->16 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=30,nJobs=10)
#9 ->17 out
#optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=100,nJobs=20)
#9 ->18 out
optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=3,nIter=200,nJobs=40)
#










