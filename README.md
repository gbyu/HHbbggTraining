# HHbbggTraining
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
Trains a Gradient Boost Classifier to separate signal/backgrounds. All re-weighting implemented, output saved. <br />
-- createTrees.ipynb <br />
It runs on ntuples, applies a given MVA and saves a reduced ntuples which includes the MVA scores <br />
-- optimizeClassifier.ipynb <br />
Optimize parameters of the classifier. In Training/scropts/optimizeClassifier.py there is a (probably not-updated) version
of this optimization code wich runs without using notebooks. 


- HHbbggTraining/python/<br />
This folder contains all the tools needed by the notebooks:
data format, train/test splitting, plotting...
These classes have to be loaded at the beginning of your notebook.

- HHbbggTraining/scripts/<br />
- prepare_data.C <br />
The preparation Root-trees with cuts.
- draw_input_var.C <br />
Get distribution input variables use in training.
- ROC_plots.py <br />
Draw ROCs curves from .dat files.
- transformMVAOutput.py <br />
   Computes the cumulative of MVA output distribution for SM signal and uses that to transform the MVA output. It saves it in a new branch called MVAOutputTransformed in a new file in the same directory of the input file called Total_preselection_diffNaming_transformedMVA.root
   Example:
   python transformMVAOutput.py -i Total_preselection_diffNaming.root 

- add_branch_res.C <br />
  Adding new branch with MVAOutputTransformed to input Trees.

- job.sh <br />
Optimize parameters of the classifier with lxplus on HTCondor.

- trainMVAHHbbgg_v2.py <br />
Training for lxplus.




