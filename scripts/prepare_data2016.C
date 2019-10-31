void prepare_data2016()
{     
  for(int i=10; i<11; i++)
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
     if(i==10) fname = "/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016/output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root";
   
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
     if(i==10) oldtree = (TTree*)dir->Get("bbHToGG_M_125_4FS_ybyt_13TeV_amcatnlo_13TeV_DoubleHTag_0");

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
   if(i==10) newfile = new TFile("/afs/cern.ch/work/i/ivovtin/public/Hggbb/flattrees_2016_withdR/output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root","recreate");

//   auto newtree = oldtree->CloneTree(0);
   auto newtree = oldtree->CloneTree();
   //TTree *newtree = oldtree->CopyTree(""); 

   float  pheta1S, pheta2S, jeta1S, jeta2S, phphi1S, phphi2S, jphi1S, jphi2S, mindRS;
   newtree->SetBranchAddress("leadingPhoton_eta",&pheta1S);
   newtree->SetBranchAddress("subleadingPhoton_eta",&pheta2S);
   newtree->SetBranchAddress("leadingJet_eta",&jeta1S);
   newtree->SetBranchAddress("subleadingJet_eta",&jeta2S);
   newtree->SetBranchAddress("leadingPhoton_phi",&phphi1S);
   newtree->SetBranchAddress("subleadingPhoton_phi",&phphi2S);
   newtree->SetBranchAddress("leadingJet_phi",&jphi1S);
   newtree->SetBranchAddress("subleadingJet_phi",&jphi2S); 
   newtree->SetBranchAddress("PhoJetMinDr",&mindRS); 
   Float_t PhoJetotherDr=0;
   
   TBranch *brPhoJetotherDr = newtree->Branch("PhoJetotherDr",&PhoJetotherDr,"PhoJetotherDr/F"); 
   Long64_t nentriesS = newtree->GetEntries(); 
   for (Long64_t i=0; i<nentriesS; i++) 
   { 
     Float_t dR1=0, dR2=0, dR3=0, dR4=0;
     Float_t x1=0, x2=0, x3=0, x4=0;
     Float_t y1=0, y2=0, y3=0, y4=0;
     PhoJetotherDr=0; 
     newtree->GetEntry(i); 
     //cout<<"-----------------"<<endl;
     //cout<<"eta1ph="<<pheta1S<<"\t"<<"eta2ph="<<pheta2S<<"\t"<<"eta1j="<<jeta1S<<"\t"<<"eta2j="<<jeta2S<<"\t"<<"phi1ph="<<phphi1S<<"\t"<<"phi2ph="<<phphi2S<<"\t"<<"phi1j="<<jphi1S<<"\t"<<"phi2j="<<jphi2S<<endl;
     x1=(pheta1S-jeta1S); 
     y1=(phphi1S-jphi1S); 
     x2=(pheta1S-jeta2S); 
     y2=(phphi1S-jphi2S); 
     x3=(pheta2S-jeta1S); 
     y3=(phphi2S-jphi1S); 
     x4=(pheta2S-jeta2S); 
     y4=(phphi2S-jphi2S); 
     //cout<<"1==="<<x1<<"\t"<<x2<<"\t"<<x3<<"\t"<<x4<<endl;
     //cout<<y1<<"\t"<<y2<<"\t"<<y3<<"\t"<<y4<<endl;
     dR1=sqrt(pow(x1,2)+pow(acos(cos(y1)),2));
     dR2=sqrt(pow(x2,2)+pow(acos(cos(y2)),2));
     dR3=sqrt(pow(x3,2)+pow(acos(cos(y3)),2));
     dR4=sqrt(pow(x4,2)+pow(acos(cos(y4)),2));
     //cout<<dR1<<"\t"<<dR2<<"\t"<<dR3<<"\t"<<dR4<<endl;
     if( dR1>=(mindRS-0.0001) && dR1<=(mindRS+0.0001) ){/*cout<<"dR1"<<endl;*/ PhoJetotherDr=dR4;}
     if( dR2>=(mindRS-0.0001) && dR2<=(mindRS+0.0001) ){/*cout<<"dR2"<<endl;*/ PhoJetotherDr=dR3;}
     if( dR3>=(mindRS-0.0001) && dR3<=(mindRS+0.0001) ){/*cout<<"dR3"<<endl;*/ PhoJetotherDr=dR2;} 
     if( dR4>=(mindRS-0.0001) && dR4<=(mindRS+0.0001) ){/*cout<<"dR4"<<endl;*/ PhoJetotherDr=dR1;}
     //dRotherS->Fill();      
     brPhoJetotherDr->Fill(); 
     //cout<<dR1<<"\t"<<dR2<<"\t"<<dR3<<"\t"<<dR4<<"\t"<<"mindR="<<mindRS<<"\t"<<"dRS="<<dRS<<endl;
   }   
//================================================================================   
   
   newtree->Print();
   newfile->Write();
 }
}
