import os
import sys; sys.path.append("/afs/cern.ch/user/i/ivovtin/HHggbb/HHbbggTraining/python") # to load packages
import training_utils as utils
import numpy as np
import root_pandas as rpd
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import plotting_utils as plotting
reload(plotting)
import optimization_utils as optimization
reload(optimization)
import postprocessing_utils as postprocessing
reload(postprocessing)

reload(utils)
reload(preprocessing)
reload(plotting)
reload(optimization)
reload(postprocessing)

ntuples = 'legacy_branch_flattrees/flattrees_2018_withdR'
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
#
#signal = [s for s in files if "output_GluGluToHHTo2B2G_allnodes_2016_no_unit_norm" in s]
signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root" in s]


utils.IO.add_signal(ntuples,signal,1)
#utils.IO.add_background(ntuples,gJets_lowPt,-8)
#utils.IO.add_background(ntuples,gJets_highPt,-9)

nodes = []

for i in range(len(utils.IO.signalName)):    
    print "using signal file n."+str(i)+": "+utils.IO.signalName[i]

#DeepJet
branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepFlavour,subleadingJet_DeepFlavour,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,sigmaMJets,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetOtherDr,rho'.split(",")
#DeepJet + Mjj
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepFlavour,subleadingJet_DeepFlavour,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,sigmaMJets,Mjj,rho'.split(",")


branch_names = [c.strip() for c in branch_names]
print branch_names

import pandas as pd  
import root_pandas as rpd

# no need to shuffle here, we just count events
preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names,shuffle=False)

for i in range(utils.IO.nSig):
        if i ==0:
            y_sig = utils.IO.signal_df[i][['proc']]
            w_sig = utils.IO.signal_df[i][['weight']]
            print w_sig
            for j in range(len(branch_names)):
                if j == 0:
                    X_sig = utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_sig = np.concatenate([X_sig,utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
        else:
            y_sig = np.concatenate((y_sig,utils.IO.signal_df[i][['proc']]))
            w_sig = np.concatenate((w_sig,utils.IO.signal_df[i][['weight']]))
            #print w_sig
            for j in range(len(branch_names)):
                if j == 0:
                    X_sig_2 = utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_sig_2 = np.concatenate([X_sig_2,utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
            X_sig=np.concatenate((X_sig,X_sig_2))

X_sig=np.round(X_sig,5)


# load the model from disk
from sklearn.externals import joblib
###########
#st with add ptMgg+ptMjj+dR
loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2018/dev_legecy_runII_ext_rho_rew/simlple_Test_binary_st.pkl'))
#loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2017/dev_legecy_runII_ext_rho_rew_v4/simlple_Test_binary_st.pkl'))
#loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2016/dev_legecy_runII_Mjj_woMjjcut_v2/simlple_Test_binary_st.pkl'))


#compute the MVA
Y_pred_sig = loaded_model.predict_proba(X_sig)[:,loaded_model.n_classes_-1].astype(np.float64)
print Y_pred_sig 

#Adding additional variables needed
import os
#st + pt/mgg, OR + ptMjj+dR
#additionalCut_names = 'MX,Mjj,CMS_hgg_mass,benchmark_reweight_SM'.split(",")
additionalCut_names = 'MX,Mjj,CMS_hgg_mass'.split(",")
#additionalCut_names = 'MX,CMS_hgg_mass'.split(",")
#st + pt/mgg+pt/mjj+dR 
#outTag = 'Hggbb/legacy_branch_flattrees/reduceTree_st_ptmgg_ptmjj_dR_2016'
outTag = 'Hggbb/legacy_branch_flattrees/'
#outTag = 'Hggbb'
outDir=os.path.expanduser("/afs/cern.ch/work/i/ivovtin/"+outTag)
if not os.path.exists(outDir):
    os.mkdir(outDir)
    
    
#Save Signal
#sig_count_df = rpd.read_root(utils.IO.signalName[0],"tagsDumper/trees/GluGluToHHTo2B2G_13TeV_DoubleHTag_0", columns = branch_names+additionalCut_names)
sig_count_df = rpd.read_root(utils.IO.signalName[0],"bbggSelectionTree", columns = branch_names+additionalCut_names)
preprocessing.define_process_weight(sig_count_df,utils.IO.sigProc[0],utils.IO.signalName[0])

#nTot is a multidim vector with all additional variables, dictVar is a dictionary associating a name of the variable
#to a position in the vector
nTot,dictVar = postprocessing.stackFeatures(sig_count_df,branch_names+additionalCut_names)
print "Y_pred"
print Y_pred_sig.shape

processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.signalName[0].split("/")[len(utils.IO.signalName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_sig)

processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.signalName[0].split("/")[len(utils.IO.signalName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_sig,nameTree="reducedTree_sig")
