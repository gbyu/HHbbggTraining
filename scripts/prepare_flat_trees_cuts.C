void prepare_flat_trees_cuts()
{ 
  for(int i=0; i<4; i++)
  {
    int tag=2016;    
    TString dir_in = "/afs/cern.ch/user/i/ivovtin/workarea/Hggbb/legacy_branch_flattrees/2016/";
    TString dir_out = "/afs/cern.ch/user/i/ivovtin/workarea/Hggbb/legacy_branch_flattrees/flattrees_legacy_cuts_2016/";

    TString fname;
     //1 change
     if(i==0) fname ="output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";
     if(i==1) fname ="output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"; 
     if(i==2 && tag==2016) fname ="output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; 
     if(i==3 && tag==2016) fname ="output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; 
     if(i==2 && tag==2017) fname ="output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";
     if(i==3 && tag==2017) fname ="output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";
   
     TFile *input = TFile::Open(dir_in + fname);
     TDirectory *dir = input->GetDirectory("tagsDumper/trees");
     TTree *oldtree;
     oldtree = (TTree*)dir->Get("bbggtrees");                                

     oldtree->SetName("bbggSelectionTree");
     oldtree->SetTitle("bbggSelectionTree"); 
     oldtree->Print();
     
     //2 change
     TFile *newfile; 
     if(i==0) newfile = new TFile(dir_out + "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root","recreate");
     if(i==1) newfile = new TFile(dir_out + "output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root","recreate");
     if(i==2 && tag==2016) newfile = new TFile(dir_out + "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root","recreate");
     if(i==3 && tag==2016) newfile = new TFile(dir_out + "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root","recreate");
     if(i==2 && tag==2017) newfile = new TFile(dir_out + "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root","recreate");
     if(i==3 && tag==2017) newfile = new TFile(dir_out + "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root","recreate");

//Standart cuts   
//TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4"); 
//
//Standart cuts + pt/Mjj>1/4   
TTree *newtree = oldtree->CopyTree("leadingPhoton_pt/CMS_hgg_mass>1/3 && subleadingPhoton_pt/CMS_hgg_mass>1/4 && leadingJet_pt>25 && subleadingJet_pt>25 && CMS_hgg_mass>100 && CMS_hgg_mass<180 && Mjj>70 && Mjj<190 && PhoJetMinDr>0.4 && leadingJet_DeepCSV>0 && subleadingJet_DeepCSV>0 && leadingPhoton_eta>-2.5 && leadingPhoton_eta<2.5 && subleadingPhoton_eta>-2.5 && subleadingPhoton_eta<2.5 && leadingJet_eta>-2.4 && leadingJet_eta<2.4 && subleadingJet_eta>-2.4 && subleadingJet_eta<2.4  && leadingJet_pt/Mjj>1/4 && subleadingJet_pt/Mjj>1/4"); 

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
   Float_t PhoJetOtherDr=0;
   
   TBranch *brPhoJetOtherDr = newtree->Branch("PhoJetOtherDr",&PhoJetOtherDr,"PhoJetOtherDr/F"); 
   Long64_t nentriesS = newtree->GetEntries(); 
   for (Long64_t i=0; i<nentriesS; i++) 
   { 
     Float_t dR1=0, dR2=0, dR3=0, dR4=0;
     Float_t x1=0, x2=0, x3=0, x4=0;
     Float_t y1=0, y2=0, y3=0, y4=0;
     PhoJetOtherDr=0; 
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
     if( dR1>=(mindRS-0.0001) && dR1<=(mindRS+0.0001) ){/*cout<<"dR1"<<endl;*/ PhoJetOtherDr=dR4;}
     if( dR2>=(mindRS-0.0001) && dR2<=(mindRS+0.0001) ){/*cout<<"dR2"<<endl;*/ PhoJetOtherDr=dR3;}
     if( dR3>=(mindRS-0.0001) && dR3<=(mindRS+0.0001) ){/*cout<<"dR3"<<endl;*/ PhoJetOtherDr=dR2;} 
     if( dR4>=(mindRS-0.0001) && dR4<=(mindRS+0.0001) ){/*cout<<"dR4"<<endl;*/ PhoJetOtherDr=dR1;}
     //dRotherS->Fill();      
     brPhoJetOtherDr->Fill(); 
     //cout<<dR1<<"\t"<<dR2<<"\t"<<dR3<<"\t"<<dR4<<"\t"<<"mindR="<<mindRS<<"\t"<<"dRS="<<dRS<<endl;
   }   
//================================================================================   
   
   newtree->Print();
   newfile->Write();
 }
}
