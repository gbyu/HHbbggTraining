void prepare_data()
{     
      //1 change
//   TString fname = "/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2017/DoubleEG.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2017/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_ttHToGG_M125_13TeV_powheg_pythia8.root";
   TString fname = "/home/ovtin/cernbox/HHggbb/flattrees_2017/output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root";

//   TString fname = "/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/DoubleEG.root";
//   TString fname = "/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";

   //MC bkg
//   TString fname ="/home/ovtin/cernbox/HHggbb/flattrees_2017/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"; 
//   TString fname ="/home/ovtin/cernbox/HHggbb/flattrees_2017/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"; 
//   TString fname ="/home/ovtin/cernbox/HHggbb/flattrees_2017/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"; 
   
   
   //TString fname = "/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/output_ttHToGG_M125_13TeV_powheg_pythia8_v2.root";
   TFile *input = TFile::Open(fname);
   TDirectory *dir = input->GetDirectory("tagsDumper/trees");
     //3 change
   //TTree *oldtree = (TTree*)dir->Get("Data_13TeV_DoubleHTag_0");                                      //for DoubleEG.root
//   TTree *oldtree = (TTree*)dir->Get("GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");   //for output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root
//   TTree *oldtree = (TTree*)dir->Get("GluGluHToGG_M_125_13TeV_powheg_pythia8_13TeV_DoubleHTag_0");   //for output_GluGluHToGG_M-125_13TeV_powheg_pythia8
//   TTree *oldtree = (TTree*)dir->Get("VBFHToGG_M125_13TeV_amcatnlo_pythia8_13TeV_DoubleHTag_0");   //for output_VBFHToGG_M125_13TeV_amcatnlo_pythia8
//   TTree *oldtree = (TTree*)dir->Get("VBFHToGG_M_125_13TeV_powheg_pythia8_13TeV_DoubleHTag_0");   //for output_VBFHToGG_M-125_13TeV_powheg_pythia8
//   TTree *oldtree = (TTree*)dir->Get("VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_13TeV_DoubleHTag_0"); //for output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8
//   TTree *oldtree = (TTree*)dir->Get("ttHToGG_M125_13TeV_powheg_pythia8_13TeV_DoubleHTag_0");  //for output_ttHToGG_M125_13TeV_powheg_pythia8
   TTree *oldtree = (TTree*)dir->Get("bbHToGG_M_125_4FS_yb2_13TeV_amcatnlo_13TeV_DoubleHTag_0");  //for output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo
//   TTree *oldtree = (TTree*)dir->Get("DiPhotonJetsBox_MGG_80toInf_13TeV_Sherpa_13TeV_DoubleHTag_0");                                     
//   TTree *oldtree = (TTree*)dir->Get("GJet_Pt_20to40_DoubleEMEnriched_MGG_80toInf_TuneCP5_13TeV_Pythia8_13TeV_DoubleHTag_0");                                     
//   TTree *oldtree = (TTree*)dir->Get("GJet_Pt_40toInf_DoubleEMEnriched_MGG_80toInf_TuneCP5_13TeV_Pythia8_13TeV_DoubleHTag_0");                                     

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
//   TFile *newfile = new TFile("DoubleEG_2017_st_cuts.root","recreate");
//   TFile *newfile = new TFile("DoubleEG_2017_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("DoubleEG_2017_MXcut.root","recreate");
//   TFile *newfile = new TFile("DoubleEG_2017_ptMjj_MX_cut.root","recreate");

//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_GluGluHToGG_M-125_13TeV_powheg_pythia8_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_VBFHToGG_M125_13TeV_amcatnlo_pythia8_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_VBFHToGG_M-125_13TeV_powheg_pythia8_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_ttHToGG_M125_13TeV_powheg_pythia8_st_cuts.root","recreate");
//   TFile *newfile = new TFile("output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root","recreate");

   //pt/Mjj cut
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_GluGluHToGG_M-125_13TeV_powheg_pythia8_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_VBFHToGG_M125_13TeV_amcatnlo_pythia8_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_VBFHToGG_M-125_13TeV_powheg_pythia8_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_ttHToGG_M125_13TeV_powheg_pythia8_st_cuts_ptMjj.root","recreate");
   TFile *newfile = new TFile("output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo_ptMjj.root","recreate");


//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts_MXcut.root","recreate");
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts_ptMjj.root","recreate");
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts_ptMjj_MXcut.root","recreate");   
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2017_MXcut.root","recreate");
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2017_ptMjj_MX_cut.root","recreate");

//    TFile *newfile = new TFile("DoubleEG_2016_MXcut.root","recreate");
//    TFile *newfile = new TFile("DoubleEG_2016_ptMjj_MX_cut.root","recreate");
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2016_MXcut.root","recreate");
//   TFile *newfile = new TFile("output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_2016_ptMjj_MX_cut.root","recreate");


//    TFile *newfile = new TFile("output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root","recreate");
//    TFile *newfile = new TFile("output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts_MXcut.root","recreate");
//    TFile *newfile = new TFile("output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts_ptMjj.root","recreate");
//    TFile *newfile = new TFile("output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts_ptMjj_MXcut.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_MXcut.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_ptMjj.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_ptMjj_MXcut.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_MXcut.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_ptMjj.root","recreate");
//    TFile *newfile = new TFile("output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_ptMjj_MXcut.root","recreate");

//   auto newtree = oldtree->CloneTree(0);
//   auto newtree = oldtree->CloneTree();
//st cut   
/*
TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4"); 
*/
//st cut + pt/Mjj>1/4   

  TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4  && leadingJet_pt/Mjj>1/4 && subleadingJet_pt/Mjj>1/4"); 

//==================================
//with MX cuts
//st cut   
// TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4 && MX>=250 && MX<354"); 
//st cut + pt/Mjj>1/4   
//  TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4  && leadingJet_pt/Mjj>1/4 && subleadingJet_pt/Mjj>1/4 && MX>=250 && MX<354"); 



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
   
   //TTree *t2S = new TTree("t2S","t2S");
   //newtree->Branch("PhoJetotherDr",&PhoJetotherDr,"PhoJetotherDr/F"); 
   //newtree->AddFriend(t2S, "t2S" );
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
