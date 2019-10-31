#!/bin/bash
cd /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_0/src/
#cmsenv
eval `scramv1 runtime -sh`
echo "CMSSW: "$CMSSW_BASE
#Run your program
cd /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/Training/scripts/
ipython trainMVAHHbbgg_st.py
