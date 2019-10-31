#!/bin/bash
#cd /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_0/src/
cd /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_9_4_9/src/
#cmsenv
eval `scramv1 runtime -sh`
echo "CMSSW: "$CMSSW_BASE
cd /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/scripts/
#python settings
source /afs/cern.ch/user/i/ivovtin/ipbus-firmware/ipbb-0.3.5/env.sh
