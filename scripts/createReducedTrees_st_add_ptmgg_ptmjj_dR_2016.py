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

ntuples = 'flattrees_2016_withdR'
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
#
signal = [s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph" in s]
diphotonJets = [s for s in files if "output_DiPhotonJetsBox_" in s]
gJets_lowPt = [s for s in files if "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8" in s]
gJets_highPt = [s for s in files if "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8" in s]
ggH = [s for s in files if "output_GluGluHToGG_" in s]
vbf = [s for s in files if "output_VBFHToGG_M-125_13TeV_powheg_pythia8" in s]
VH = [s for s in files if "output_VHToGG_" in s]
bbH = [s for s in files if "output_bbHToGG_M-125_4FS_yb2" in s] #is this correct?
#bbH = [s for s in files if "output_bbHToGG_M-125_4FS_ybyt" in s] #second file in 2016 year
ttH = [s for s in files if "output_ttHToGG_" in s]
#vbf2 = [s for s in files if "output_VBFHToGG_M125_13TeV_amcatnlo_pythia8_st_cuts" in s]
ggJets_lowPt2 = [s for s in files if "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8" in s]
gJets_highPt2 = [s for s in files if "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8" in s]

Data= [s for s in files if "DoubleEG" in s]

utils.IO.add_signal(ntuples,signal,1)
print diphotonJets
utils.IO.add_background(ntuples,diphotonJets,-1)
utils.IO.add_background(ntuples,gJets_lowPt,-2)
utils.IO.add_background(ntuples,gJets_highPt,-2)
utils.IO.add_background(ntuples,ggH,-3)
utils.IO.add_background(ntuples,vbf,-4)
utils.IO.add_background(ntuples,VH,-5)
utils.IO.add_background(ntuples,bbH,-6)
utils.IO.add_background(ntuples,ttH,-7)
#utils.IO.add_background(ntuples,vbf2,-8)
utils.IO.add_background(ntuples,gJets_lowPt,-8)
utils.IO.add_background(ntuples,gJets_highPt,-9)

nBkg = len(utils.IO.backgroundName)
print nBkg

utils.IO.add_data(ntuples,Data,-10)

#add all nodes
nodes = []
#for i in range(2,14):
#    nodes.append([s for s in files if "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2016"+str(i) in s])
##    nodes.append([s for s in files if "GluGluToHHTo2B2G_node_"+str(i) in s])
for i in range(len(utils.IO.backgroundName),len(utils.IO.backgroundName)+len(nodes)):
    utils.IO.add_background(ntuples,nodes[i-nBkg],-i) 
    

for i in range(len(utils.IO.backgroundName)):        
    print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]
for i in range(len(utils.IO.signalName)):    
    print "using signal file n."+str(i)+": "+utils.IO.signalName[i]
print "using data file: "+ utils.IO.dataName[0]


#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#all the branches you want to save in new trees
#st values with adding pt_gg/m_gg, pt_jj/M_jj
#branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetotherDr'.split(",")
branch_names = 'absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,PhoJetMinDr,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingJet_DeepCSV,subleadingJet_DeepCSV,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,noexpand:sigmaMJets/Mjj,noexpand:leadingPhoton_pt/CMS_hgg_mass,noexpand:subleadingPhoton_pt/CMS_hgg_mass,noexpand:leadingJet_pt/Mjj,noexpand:subleadingJet_pt/Mjj,PhoJetotherDr,Mjj'.split(",")

branch_names = [c.strip() for c in branch_names]
print branch_names

import pandas as pd  
import root_pandas as rpd

# no need to shuffle here, we just count events
preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names,shuffle=False)
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.set_variables(branch_names)

X_data,y_data,weights_data = preprocessing.set_data("bbggSelectionTree",branch_names)
X_data,y_data,weights_data = preprocessing.clean_signal_events_single_dataset(X_data,y_data,weights_data)

#bbggTrees have by default signal and CR events, let's be sure that we clean it
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.clean_signal_events(X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig)


# load the model from disk
from sklearn.externals import joblib
###########
#st with add ptMgg+ptMjj+dR
##2016
#loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2016/st_ptmgg_ptmjj_dR/simlple_Test_binary_st.pkl'))
loaded_model = joblib.load(os.path.expanduser('/eos/user/i/ivovtin/HHggbb/HHbbggTraining/Training/output_files/2016/st_MC_Bkg_ptmgg_ptmjj_dR_with_Mjj/simlple_Test_binary_st.pkl'))

print len(utils.IO.backgroundName)
bkg = []
for i in range(0,len(utils.IO.backgroundName)-1): 
    print "bkg n:"+str(i)
    print X_bkg[y_bkg ==-i-1]
    bkg.append(X_bkg[y_bkg ==-i-1])

#compute the MVA
Y_pred_sig = loaded_model.predict_proba(X_sig)[:,loaded_model.n_classes_-1].astype(np.float64)
print Y_pred_sig 
Y_pred_bkg = []
for i in range(0,len(utils.IO.backgroundName)-1):  
    print i
    Y_pred_bkg.append(loaded_model.predict_proba(bkg[i])[:,loaded_model.n_classes_-1].astype(np.float64))

Y_pred_data = loaded_model.predict_proba(X_data)[:,loaded_model.n_classes_-1].astype(np.float64)
print Y_pred_data 

#Adding additional variables needed
import os
#st + pt/mgg, OR + ptMjj+dR
#additionalCut_names = 'MX,Mjj,CMS_hgg_mass'.split(",")
additionalCut_names = 'MX,CMS_hgg_mass'.split(",")
#st + pt/mgg+pt/mjj+dR 
outTag = 'Hggbb/reduceTree_2016_mjj/reduceTree_st_variables_add_ptmgg_ptmjj_dR_mjj'
#outTag = 'Hggbb'
outDir=os.path.expanduser("/afs/cern.ch/work/i/ivovtin/"+outTag)
if not os.path.exists(outDir):
    os.mkdir(outDir)
    
    
#Save Signal
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


# do gJets not in the loop since they have two samples for one process
bkg_1_count_df = rpd.read_root(utils.IO.backgroundName[1],"bbggSelectionTree", columns = branch_names+additionalCut_names)
preprocessing.define_process_weight(bkg_1_count_df,utils.IO.bkgProc[1],utils.IO.backgroundName[1])

nTot,dictVar = postprocessing.stackFeatures(bkg_1_count_df,branch_names+additionalCut_names)
print nTot.shape

bkg_2_count_df = rpd.read_root(utils.IO.backgroundName[2],"bbggSelectionTree", columns = branch_names+additionalCut_names)
preprocessing.define_process_weight(bkg_2_count_df,utils.IO.bkgProc[2],utils.IO.backgroundName[2])

nTot_2,dictVar = postprocessing.stackFeatures(bkg_2_count_df,branch_names+additionalCut_names)

nTot_3 = np.concatenate((nTot,nTot_2))
print nTot_3.shape

processPath=(os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[1].split("/")[len(utils.IO.backgroundName[1].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root").replace("_Pt-20to40","")
postprocessing.saveTree(processPath,dictVar,nTot_3,Y_pred_bkg[1])

processPath=(os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[1].split("/")[len(utils.IO.backgroundName[1].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root").replace("_Pt-20to40","")
postprocessing.saveTree(processPath,dictVar,nTot_3,Y_pred_bkg[1],nameTree="reducedTree_bkg_2")


#Bkgs in the loop - diphotJets and another
for iProcess in range(0,len(utils.IO.backgroundName)):
    ##gJets which are two samples for one process are skipped  !not skipped
    iSample=iProcess
    if iProcess == 1 or iProcess ==2:
            continue
    if iProcess > 2:
        iSample = iProcess-1
    
    print "Processing sample: "+str(iProcess)
    bkg_count_df = rpd.read_root(utils.IO.backgroundName[iProcess],"bbggSelectionTree", columns = branch_names+additionalCut_names)
    preprocessing.define_process_weight(bkg_count_df,utils.IO.bkgProc[iProcess],utils.IO.backgroundName[iProcess])

    nTot,dictVar = postprocessing.stackFeatures(bkg_count_df,branch_names+additionalCut_names)

    processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[iProcess].split("/")[len(utils.IO.backgroundName[8].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
    postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_bkg[iSample])    

    processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.backgroundName[iProcess].split("/")[len(utils.IO.backgroundName[8].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
    if "GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0"in processPath:
        treeName = "reducedTree_sig_node_"+str(iProcess-6)
    else:
        treeName = "reducedTree_bkg_"+str(iProcess)
    
    postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_bkg[iSample],nameTree=treeName) 
    
    
#save Data
data_count_df = rpd.read_root(utils.IO.dataName[0],"bbggSelectionTree", columns = branch_names+additionalCut_names)

nTot,dictVar = postprocessing.stackFeatures(data_count_df,branch_names+additionalCut_names,isData=1)

#save preselection data
processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.dataName[0].split("/")[len(utils.IO.dataName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_data)

processPath=os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+utils.IO.dataName[0].split("/")[len(utils.IO.dataName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
postprocessing.saveTree(processPath,dictVar,nTot,Y_pred_data,nameTree="reducedTree_bkg")


#from subprocess import call
#call(["hadd","daje.root *diffNaming.root"])
print "cd "+os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag
os.system('hadd '+ os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+'Total_preselection_diffNaming.root '+ os.path.expanduser('/afs/cern.ch/work/i/ivovtin/')+outTag+'/'+'*diffNaming.root')


        



