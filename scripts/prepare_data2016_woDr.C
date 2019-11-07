void prepare_data2016_woDr()
{     
  for(int i=0; i<1; i++)
  {
     TString fname;
     //1 change
     if(i==0) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/DoubleEG.root";
     if(i==1) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";
     if(i==2) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root";
     //if(i==3) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root";
     if(i==3) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root";
     if(i==4) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root";
     if(i==5) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_ttHToGG_M125_13TeV_powheg_pythia8_v2.root";
     if(i==6) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root";
     if(i==7) fname ="/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"; 
     if(i==8) fname ="/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; 
     if(i==9) fname ="/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; 
   
     TFile *input = TFile::Open(fname);
     TDirectory *dir = input->GetDirectory("tagsDumper/trees");
     TTree *oldtree;
     //3 change
     if(i==0) oldtree = (TTree*)dir->Get("Data_13TeV_DoubleHTag_0");                                      //for DoubleEG.root
     if(i==1) oldtree = (TTree*)dir->Get("GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");   //for output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root
     if(i==2) oldtree = (TTree*)dir->Get("GluGluHToGG_M_125_13TeV_powheg_pythia8_13TeV_DoubleHTag_0");   //for output_GluGluHToGG_M-125_13TeV_powheg_pythia8
     //if(i==3) oldtree = (TTree*)dir->Get("VBFHToGG_M125_13TeV_amcatnlo_pythia8_13TeV_DoubleHTag_0");   //for output_VBFHToGG_M125_13TeV_amcatnlo_pythia8
     if(i==3) oldtree = (TTree*)dir->Get("VBFHToGG_M_125_13TeV_powheg_pythia8_13TeV_DoubleHTag_0");   //for output_VBFHToGG_M-125_13TeV_powheg_pythia8
     if(i==4) oldtree = (TTree*)dir->Get("VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_13TeV_DoubleHTag_0"); //for output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8
     if(i==5) oldtree = (TTree*)dir->Get("ttHToGG_M125_13TeV_powheg_pythia8_v2_13TeV_DoubleHTag_0");  //for output_ttHToGG_M125_13TeV_powheg_pythia8
     if(i==6) oldtree = (TTree*)dir->Get("bbHToGG_M_125_4FS_yb2_13TeV_amcatnlo_13TeV_DoubleHTag_0");  //for output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo
     if(i==7) oldtree = (TTree*)dir->Get("DiPhotonJetsBox_MGG_80toInf_13TeV_Sherpa_13TeV_DoubleHTag_0");                                     
     if(i==8) oldtree = (TTree*)dir->Get("GJet_Pt_20to40_DoubleEMEnriched_MGG_80toInf_TuneCUETP8M1_13TeV_Pythia8_13TeV_DoubleHTag_0");                               
     if(i==9) oldtree = (TTree*)dir->Get("GJet_Pt_40toInf_DoubleEMEnriched_MGG_80toInf_TuneCUETP8M1_13TeV_Pythia8_13TeV_DoubleHTag_0");

     oldtree->SetName("bbggSelectionTree");
     oldtree->SetTitle("bbggSelectionTree"); 
     oldtree->Print();
   
   // Deactivate all branches
   //oldtree->SetBranchStatus("*", 0);
   // Activate only four of them
   //for (auto activeBranchName : {"leadingPhoton_eta", "subleadingPhoton_eta"})
   //   oldtree->SetBranchStatus(activeBranchName, 1);
   // Create a new file + a clone of old tree in new file
   //TFile newfile("small2.root", "recreate");
     
      //2 change
   TFile *newfile; 
   if(i==0) newfile= new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/DoubleEG.root","recreate");
   if(i==1) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root","recreate");
   if(i==2) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root","recreate");
   //if(i==3) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root","recreate");
   if(i==3) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root","recreate");
   if(i==4) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root","recreate");
   if(i==5) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_ttHToGG_M125_13TeV_powheg_pythia8.root","recreate");
   if(i==6) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root","recreate");
   if(i==7) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root","recreate");
   if(i==8) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root","recreate");
   if(i==9) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root","recreate");

//   auto newtree = oldtree->CloneTree(0);
   auto newtree = oldtree->CloneTree();
   //TTree *newtree = oldtree->CopyTree(""); 
   
   newtree->Print();
   newfile->Write();
 }
}
