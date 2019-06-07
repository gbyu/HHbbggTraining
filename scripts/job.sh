#!/bin/bash
cd /afs/cern.ch/user/i/ivovtin/HHggbb/HHbbgg_ETH/Training/scripts/
#python settings
source /afs/cern.ch/user/i/ivovtin/ipbus-firmware/ipbb-0.3.5/env.sh
#Run your program
#ipython optimizeClassifier.py >> res.dat
ipython optimizeClassifier.py
