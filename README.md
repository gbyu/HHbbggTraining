<<<<<<< 705379043e1802258ff54e0a7ff708ab489356cc
# HbbggTraining
=======
# HHbbggTraining
## Getting the code
Fork to your directory the code here: https://github.com/ivovtin/HbbggTraining<br />
Clone it locally:<br />
git clone git@github.com:[YOURNAME]/HbbggTraining.git HbbggTraining <br />
You should create your own branch, then do pull requests when you are done. <br />

## Training, optimization of MVAs and ntuple production
- Start jupyter: <br />
cd notebooks/; <br />
jupyter notebook; <br />

The code is organized in notebooks, the programs you execute directly in the browser. They
are in the "notebooks" folder. <br />

- Training/notebooks <br />
This folder contains all the notebooks needed <br />
-- trainMVAHHbbgg.ipynb  <br />
Trains a Gradient Boost Classifier to separate signal/backgrounds. All re-weighting implemented, output saved. <br />
-- createTrees.ipynb <br />
It runs on ntuples, applies a given MVA and saves a reduced ntuples which includes the MVA scores <br />
-- optimizeClassifier.ipynb <br />
Optimize parameters of the classifier. In Training/scropts/optimizeClassifier.py there is a (probably not-updated) version
of this optimization code wich runs without using notebooks. 


- Training/python/<br />
This folder contains all the tools needed by the notebooks:
data format, train/test splitting, plotting...
These classes have to be loaded at the beginning of your notebook.

>>>>>>> First commit
