#import FWCore.ParameterSet.Config as cms
from time import time,ctime
import sys,os
from tree_convert_pkl2xml import tree_to_tmva, BDTxgboost, BDTsklearn
import sklearn
from collections import OrderedDict
#print('The scikit-learn version is {}.'.format(sklearn.__version__))
import pandas
#print('The pandas version is {}.'.format(pandas.__version__))
import cPickle as pickle
#print('The pickle version is {}.'.format(pickle.__version__))
import numpy as np
import xgboost as xgb
#print('The xgb version is {}.'.format(xgb.__version__))
import subprocess
from sklearn.externals import joblib
from itertools import izip
from optparse import OptionParser, make_option
from  pprint import pprint

#features = ['Jet_pt','Jet_eta','rho','Jet_mt','Jet_leadTrackPt','Jet_leptonPtRel','Jet_leptonDeltaR','Jet_neHEF','Jet_neEmEF','Jet_vtxPt','Jet_vtxMass','Jet_vtx3dL','Jet_vtxNtrk','Jet_vtx3deL','Jet_energyRing_dR0_em_Jet_e','Jet_energyRing_dR1_em_Jet_e','Jet_energyRing_dR2_em_Jet_e','Jet_energyRing_dR3_em_Jet_e','Jet_energyRing_dR4_em_Jet_e','Jet_energyRing_dR0_neut_Jet_e','Jet_energyRing_dR1_neut_Jet_e','Jet_energyRing_dR2_neut_Jet_e','Jet_energyRing_dR3_neut_Jet_e','Jet_energyRing_dR4_neut_Jet_e','Jet_energyRing_dR0_ch_Jet_e','Jet_energyRing_dR1_ch_Jet_e','Jet_energyRing_dR2_ch_Jet_e','Jet_energyRing_dR3_ch_Jet_e','Jet_energyRing_dR4_ch_Jet_e','Jet_energyRing_dR0_mu_Jet_e','Jet_energyRing_dR1_mu_Jet_e','Jet_energyRing_dR2_mu_Jet_e','Jet_energyRing_dR3_mu_Jet_e','Jet_energyRing_dR4_mu_Jet_e','Jet_numDaughters_pt03']

features = ['leadingJet_pt','leadingJet_eta','leadingJet_mass','leadingJet_e','leadingJet_phi','leadingJet_DeepFlavour','leadingJet_bRegNNCorr','subleadingJet_pt','subleadingJet_eta','subleadingJet_mass','subleadingJet_e','subleadingJet_phi','subleadingJet_DeepFlavour','subleadingJet_bRegNNCorr','ttH_MET','ttH_phiMET','MjjReg_phi12','MjjReg_phi1M','MjjReg_phi2M','rho','nvtx','ttH_sumET']

#target=['Jet_mcPt/Jet_pt']
#target=['Mjj']
target=['mbbnu/mjj']

#this is just for testing if you want to check on one event, be careful, you have to put the correct variables
new_dict = OrderedDict([('leadingJet_bDis',0.9889938831329346),('subleadingJet_bDis',0.0648464784026146),('leadingPhotonSigOverE',0.005494383163750172),('subleadingPhotonSigOverE',0.0067262412048876286),('sigmaMOverMDecorr',0.006000000052154064),('PhoJetMinDr',1.1405941247940063)])

def main(options,args):

    inputFile = options.inFile
    outputFile = inputFile.split('/')[-1].replace('.pkl','.weights.xml')
    #outputFile = inputFile.split('/')[-1].replace('.xgb','.weights.xml')

    #loaded_model = joblib.load(fileOpen)
    #result = loaded_model.score(X_test, Y_test)
    #print(result)

    result=-20
    fileOpen = None
    try:
        fileOpen = open(inputFile, 'rb')
    except IOError as e:
        print('Couldnt open or write to file (%s).' % e)
    else:
        print ('file opened')
        print inputFile
        try:
            #pkldata = pickle.load(fileOpen)
            #result = pkldata.score(X_test, Y_test)
	    #print(result)
            pkldata = joblib.load(fileOpen)
            print pkldata
        except :
            print('Oops!',sys.exc_info()[0],'occured.')
        else:
            print ('pkl loaded')

            bdt = BDTxgboost(pkldata, features, target)
            bdt.to_tmva(outputFile)
            print "xml file is created with name : ", outputFile

            if options.test:#this is just for testing if you want to check on one event uncomment here
                proba = pkldata.predict_proba([[ new_dict[feature] for feature in features]])
                print "proba= ",proba
                result = proba[:,1][0]
                print ('predict BDT to one event',result)
                

                test_eval = bdt.eval([ new_dict[feature] for feature in features])
                print "test_eval = ", test_eval

            fileOpen.close()
    return result

if __name__ == "__main__":
    parser = OptionParser(option_list=[
            make_option("-i", "--infile",
                        action="store", type="string", dest="inFile",
                        default="",
                        help="input file",
                        ),
            make_option("-t", "--test",
                        action="store_true", dest="test",
                        default=False,
                        help="test on one event",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT

    main(options,args)
