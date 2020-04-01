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

ntuples = 'legacy_branch_flattrees/flattrees_2016_withdR'
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
#
bbH = [s for s in files if "output_bbHToGG_M-125_4FS_yb2" in s]
#bbH = [s for s in files if "output_VBFHHTo2B2G_CV_1_C2V_1_C3_1_13TeV-madgraph" in s]

utils.IO.add_background(ntuples,bbH,-3)

nBkg = len(utils.IO.backgroundName)
print nBkg


#add all nodes
nodes = []
for i in range(len(utils.IO.backgroundName),len(utils.IO.backgroundName)+len(nodes)):
    utils.IO.add_background(ntuples,nodes[i-nBkg],-i) 
    
for i in range(len(utils.IO.backgroundName)):        
    print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]

#st values with adding pt_gg/m_gg, pt_jj/M_jj
#DeepJet
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepFlavour,subleadingJet_DeepFlavour,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,sigmaMJets,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetOtherDr,rho'.split(",")
branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepFlavour,subleadingJet_DeepFlavour,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,sigmaMJets,Mjj,rho'.split(",")


branch_names = [c.strip() for c in branch_names]
print branch_names

import pandas as pd  
import root_pandas as rpd

# no need to shuffle here, we just count events
preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names,shuffle=False)
#X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.set_variables(branch_names)

for i in range(utils.IO.nBkg):
        if i ==0:
            y_bkg = utils.IO.background_df[i][['proc']]
            w_bkg = utils.IO.background_df[i][['weight']]
            #print w_bkg
            for j in range(len(branch_names)):
                if j == 0:
                    X_bkg = utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_bkg = np.concatenate([X_bkg,utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
        else:
            y_bkg = np.concatenate((y_bkg,utils.IO.background_df[i][['proc']]))
            w_bkg = np.concatenate((w_bkg,utils.IO.background_df[i][['weight']]))
            for j in range(len(branch_names)):
                if j == 0:
                    X_bkg_2 = utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_bkg_2 = np.concatenate([X_bkg_2,utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
            X_bkg=np.concatenate((X_bkg,X_bkg_2))


X_bkg=np.round(X_bkg,5)

# load the model from disk
from sklearn.externals import joblib
###########
#st with add ptMgg+ptMjj+dR
#loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2017/dev_legecy_runII_ext_rho_rew/simlple_Test_binary_st.pkl'))
loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2016/dev_legecy_runII_Mjj_woMjjcut_v2/simlple_Test_binary_st.pkl'))

print len(utils.IO.backgroundName)
print y_bkg
#bkg = []
#for i in range(0,len(utils.IO.backgroundName)-1): 
#    print "bkg n:"+str(i)
#    print X_bkg[y_bkg ==-i-1]
#    bkg.append(X_bkg[y_bkg ==-i-1])

#compute the MVA
#Y_pred_bkg = []
#for i in range(0,len(utils.IO.backgroundName)-1):  
#    print i
#    Y_pred_bkg.append(loaded_model.predict_proba(bkg[i])[:,loaded_model.n_classes_-1].astype(np.float64))

Y_pred_bkg = loaded_model.predict_proba(X_bkg)[:,loaded_model.n_classes_-1].astype(np.float64)
print Y_pred_bkg



#Adding additional variables needed
import os
#st + pt/mgg, OR + ptMjj+dR
#additionalCut_names = 'MX,Mjj,CMS_hgg_mass'.split(",")
additionalCut_names = 'MX,CMS_hgg_mass'.split(",")
#st + pt/mgg+pt/mjj+dR 
outTag = 'Hggbb/legacy_branch_flattrees/'
#outTag = 'Hggbb'
outDir=os.path.expanduser("/afs/cern.ch/work/i/ivovtin/"+outTag)
if not os.path.exists(outDir):
    os.mkdir(outDir)
    

bkg_count_df = rpd.read_root(utils.IO.backgroundName[0],"bbggSelectionTree", columns = branch_names+additionalCut_names)
preprocessing.define_process_weight(bkg_count_df,utils.IO.bkgProc[0],utils.IO.backgroundName[0])

nTot,dictVar = postprocessing.stackFeatures(bkg_count_df,branch_names+additionalCut_names)


processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[0].split("/")[len(utils.IO.backgroundName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_bkg)

processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[0].split("/")[len(utils.IO.backgroundName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
treeName = "reducedTree_bkg_"+str(11)
#treeName = "reducedTree_sig"

postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_bkg,nameTree=treeName)


#from subprocess import call
#print "cd "+os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag
#os.system('hadd '+ os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+'Total_preselection_diffNaming.root '+ os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+'*diffNaming.root')


        



