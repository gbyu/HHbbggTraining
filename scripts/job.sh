#!/bin/bash
cd /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_13/src/
#cmsenv
eval `scramv1 runtime -sh`
echo "CMSSW: "$CMSSW_BASE
#Run your program
#ipython /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/scripts/optimizeClassifier.py
ipython /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/scripts/ROCsdraw.py
