# HHbbggTraining
Talk about training: https://indico.cern.ch/event/847922/contributions/3619131/attachments/1934199/3204616/ovtin_HHbbgg.pdf <br /> 

## Getting the code
Fork to your directory the code here: https://github.com/ivovtin/HbbggTraining<br />
Clone it locally:<br />
git clone https://github.com/[YOURNAME]/HHbbggTraining <br />
You should create your own branch, then do pull requests when you are done. <br />

## Training, optimization of MVAs and ntuple production
- Start jupyter: <br />
cd notebooks/ <br />
jupyter notebook <br />

The code is organized in notebooks, the programs you execute directly in the browser. They
are in the "notebooks" folder. <br />

- HHbbggTraining/notebooks <br />
This folder contains all the notebooks needed <br />
-- trainMVAHHbbgg.ipynb  <br />
Trains a Gradient Boost Classifier to separate signal/backgrounds. <br />
-- createReducedTrees2.ipynb <br />
It runs on ntuples, applies a given MVA and saves a reduced ntuples which includes the MVA scores <br />
-- optimizeClassifier.ipynb <br />
Optimize parameters of the classifier. In Training/scropts/optimizeClassifier.py there is a (probably not-updated) version
of this optimization code wich runs without using notebooks. 


- HHbbggTraining/python/<br />
This folder contains all the tools needed by the notebooks: data format, train/test splitting, plotting... 
These classes have to be loaded at the beginning of your notebook.

- HHbbggTraining/scripts/<br />
  In this directory realized code for training, optimization and add MVA score to main tree in MC/Data samples which you can use on lxplus. <br />
  1. prepare_data2016_cuts.C and prepare_data2017_cuts.C <br />
  The preparation Root-trees with cuts and variable PhoJetOtherDr for training. Rename tagsDumper/trees to bbggSelectionTree.

  2. trainMVAHHbbgg_st.py, trainMVAHHbbgg_ptmgg.py and trainMVAHHbbgg_ptmgg_ptmjj_dR.py <br />
  Training with different set input of variables.

  3. optimizeClassifier.py <br />
  Optimization of parameters of MVA. RandomizedSearchCV using.

  4. createReducedTrees_st_2016.py, createReducedTrees_st_add_ptmgg_2016.py and createReducedTrees_st_add_ptmgg_ptmjj_dR_2016.py (same for 2017) <br />
  It runs on ntuples, applies a given MVA and saves a reduced ntuples which includes the MVA scores.

  5. transformMVAOutput.py <br />
   Computes the cumulative of MVA output distribution for SM signal and uses that to transform the MVA output. It saves it in a new branch called MVAOutputTransformed in a new file in the same directory of the input file. <br />
   Example:
   python transformMVAOutput.py -i result.root 

  6. prepare_data2016.C and prepare_data2017.C <br />
  The preparation Root-trees without cuts but with variable PhoJetOtherDr for training. Rename tagsDumper/trees to bbggSelectionTree. 
  
  7. add_branch_res.C <br />
  Adding new branch with MVAOutputTransformed to input Trees.

  Another scripts: <br />

  - draw_input_var.C <br />
  Get distribution input variables use in training.

  - ROC_plots.py <br />
  Draw ROCs curves from .dat files.

  - train_condor.sub, optim_condor.sub and reduce_condor.sub <br />
  Training, optimization parameters of the classifier and create reduce trees with lxplus on HTCondor.



