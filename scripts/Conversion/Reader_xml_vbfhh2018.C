#include "TMVA/Reader.h"

void Reader_xml_vbfhh2018(){

TString flashgg_data = "/eos/cms/store/group/phys_higgs/cmshgg/flashgg-data/Taggers/data/HHTagger/";
TString indirMVA;
TString dirOut;
TString weightFile;
TString weightFile2;

//for (TString year : {"2016","2017","2018"}){
TString year = "2018";
Float_t MVAscaling;

 if(year=="2016"){ 
   indirMVA = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/WithBTagReweight/2016/"; 
   dirOut = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/synch/2016/";
   weightFile = flashgg_data + "training_with_18_12_2019_training0.weights.xml";  //with Mjj - ETH
   weightFile2 = flashgg_data + "training_with_18_12_2019_wo_Mjj_training0.weights.xml";  //w/o Mjj - ETH
   MVAscaling=1.0;
 }

 if(year=="2017"){ 
   indirMVA = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/WithBTagReweight/2017/"; 
   dirOut = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/synch/2017/";
   weightFile = flashgg_data + "training_with_18_12_2019_training1.weights.xml";  //with Mjj - ETH
   weightFile2 = flashgg_data + "training_with_18_12_2019_wo_Mjj_training1.weights.xml";  //w/o Mjj - ETH
   MVAscaling=1.0;
 }

 if(year=="2018"){ 
   indirMVA = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/2018/"; 
   dirOut = "/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/2018/withMVA/";
   weightFile = flashgg_data + "training_with_18_12_2019_training2.weights.xml";  //with Mjj - ETH
   weightFile2 = flashgg_data + "training_with_18_12_2019_wo_Mjj_training2.weights.xml";  //w/o Mjj - ETH
   MVAscaling=1.0;
 }

//For calculation MVA transformation
//TString MVAFlatteningFileName = "cumulativeTransformation_with_extended_var_29_11_2019_year2016.root";
//TString MVAFlatteningFileName = flashgg_data + "cumulativeTransformation_20191218.root";  //with Mjj - ETH
TString MVAFlatteningFileName = flashgg_data + "cumulativeTransformation_20191812_btag_upd_" + year + ".root";  //with Mjj - ETH
TFile * MVAFlatteningFile = new TFile(MVAFlatteningFileName,"READ");
TGraph * MVAFlatteningCumulative = (TGraph*)MVAFlatteningFile->Get("cumulativeGraph"); 

TString MVAFlatteningFileName2 = flashgg_data + "cumulativeTransformation_20191812_btag_wo_Mjj_upd_" + year + ".root";  //w/o Mjj - ETH
TFile * MVAFlatteningFile2 = new TFile(MVAFlatteningFileName2,"READ");
TGraph * MVAFlatteningCumulative2 = (TGraph*)MVAFlatteningFile2->Get("cumulativeGraph"); 


//TString Sig = "output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root";
//TString Sig = "output_GluGluToHHTo2B2G_allnodes_no_unit_norm.root";
TString Sig = "output_GluGluToHHTo2B2G_all_nodes.root";
TString Bkg1 ="output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root";
TString Bkg2, Bkg3;
if(year=="2016") Bkg2 ="output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root";
if(year=="2016") Bkg3 ="output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root";
if(year=="2017" || year=="2018") Bkg2 ="output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";
if(year=="2017" || year=="2018") Bkg3 ="output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";
TString Bkg4 ="output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root";
TString Bkg5 ="output_VBFHToGG_M-125_13TeV_powheg_pythia8.root";
TString Bkg6 ="output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root";
TString Bkg7 ="output_ttHToGG_M125_13TeV_powheg_pythia8.root";
TString Bkg8 ="output_bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo.root";
TString Bkg9 ="output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root";
TString Bkg10 ="output_DiPhotonJetsBox1BJet_MGG-80toInf_13TeV-Sherpa.root";
TString Bkg11 ="output_DiPhotonJetsBox2BJets_MGG-80toInf_13TeV-Sherpa.root";
TString Data ="Data.root";

//=================================================================================================================

//for (TString fname : {Data}){
//for (TString fname : {Bkg10,Bkg11}){
//for (TString fname : {Bkg2,Bkg3,Bkg4,Bkg5,Bkg6,Bkg7,Bkg10,Bkg11,Data}){
//for (TString fname : {Sig,Bkg1,Bkg2,Bkg3,Bkg4,Bkg5,Bkg6,Bkg7,Bkg8,Bkg9,Bkg10,Bkg11,Data}){
for (TString fname : {Bkg4,Bkg5,Bkg6,Bkg7,Sig}){
 
  // create TMVA::Reader object
  TMVA::Reader *reader = new TMVA::Reader("!V:!Silent:Color,G:AnalysisType=multiclass"); //with Mjj
  TMVA::Reader *reader2 = new TMVA::Reader("!V:!Silent:Color,G:AnalysisType=multiclass"); //w/o Mjj

  // create a set of variables and declare them to the reader - the variable names must corresponds in name and type to
  // those given in the weight file(s) that you use
  Float_t var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23;
  /*
  reader->AddVariable( "absCosThetaStar_CS", &var1 );
  reader->AddVariable( "absCosTheta_bb", &var2 );
  reader->AddVariable( "absCosTheta_gg", &var3 );
  reader->AddVariable( "PhoJetMinDr", &var4 );
  reader->AddVariable( "customLeadingPhotonIDMVA", &var5 );
  reader->AddVariable( "customSubLeadingPhotonIDMVA", &var6 );
  reader->AddVariable( "leadingJet_DeepFlavour", &var7 );
  reader->AddVariable( "subleadingJet_DeepFlavour", &var8 );
  reader->AddVariable( "leadingPhotonSigOverE", &var9 );
  reader->AddVariable( "subleadingPhotonSigOverE", &var10 );
  reader->AddVariable( "sigmaMOverM", &var11 );
  reader->AddVariable( "diphotonCandidatePtOverdiHiggsM", &var12 );
  reader->AddVariable( "dijetCandidatePtOverdiHiggsM", &var13 );
  reader->AddVariable( "leadingJet_bRegNNResolution", &var14 );
  reader->AddVariable( "subleadingJet_bRegNNResolution", &var15 );
  reader->AddVariable( "sigmaMJets", &var16 );
  reader->AddVariable( "leadingPhoton_pt/CMS_hgg_mass", &var17 );
  reader->AddVariable( "subleadingPhoton_pt/CMS_hgg_mass", &var18 );
  reader->AddVariable( "leadingJet_pt/Mjj", &var19 );
  reader->AddVariable( "subleadingJet_pt/Mjj", &var20 );
  reader->AddVariable( "PhoJetOtherDr", &var21 );
  reader->AddVariable( "rho", &var22 );
  */ 
  //with Mjj
  reader->AddVariable( "Mjj", &var1 );
  reader->AddVariable( "leadingJet_DeepFlavour", &var2 );
  reader->AddVariable( "subleadingJet_DeepFlavour", &var3 );
  reader->AddVariable( "absCosThetaStar_CS", &var4 );
  reader->AddVariable( "absCosTheta_bb", &var5 );
  reader->AddVariable( "absCosTheta_gg", &var6 );
  reader->AddVariable( "diphotonCandidatePtOverdiHiggsM", &var7 );
  reader->AddVariable( "dijetCandidatePtOverdiHiggsM", &var8 );
  reader->AddVariable( "customLeadingPhotonIDMVA", &var9 );
  reader->AddVariable( "customSubLeadingPhotonIDMVA", &var10 );
  reader->AddVariable( "leadingPhotonSigOverE", &var11 );
  reader->AddVariable( "subleadingPhotonSigOverE", &var12 );
  reader->AddVariable( "sigmaMOverM", &var13 );
  reader->AddVariable( "(leadingPhoton_pt/CMS_hgg_mass)", &var14 );
  reader->AddVariable( "(subleadingPhoton_pt/CMS_hgg_mass)", &var15 );
  reader->AddVariable( "(leadingJet_pt/Mjj)", &var16 );
  reader->AddVariable( "(subleadingJet_pt/Mjj)", &var17 );
  reader->AddVariable( "rho", &var18 );
  reader->AddVariable( "(leadingJet_bRegNNResolution*1.4826)", &var19 );
  reader->AddVariable( "(subleadingJet_bRegNNResolution*1.4826)", &var20 );
  reader->AddVariable( "(sigmaMJets*1.4826)", &var21 );
  reader->AddVariable( "PhoJetMinDr", &var22 );
  reader->AddVariable( "PhoJetOtherDr", &var23 );

  //w/o Mjj
  reader2->AddVariable( "leadingJet_DeepFlavour", &var2 );
  reader2->AddVariable( "subleadingJet_DeepFlavour", &var3 );
  reader2->AddVariable( "absCosThetaStar_CS", &var4 );
  reader2->AddVariable( "absCosTheta_bb", &var5 );
  reader2->AddVariable( "absCosTheta_gg", &var6 );
  reader2->AddVariable( "diphotonCandidatePtOverdiHiggsM", &var7 );
  reader2->AddVariable( "dijetCandidatePtOverdiHiggsM", &var8 );
  reader2->AddVariable( "customLeadingPhotonIDMVA", &var9 );
  reader2->AddVariable( "customSubLeadingPhotonIDMVA", &var10 );
  reader2->AddVariable( "leadingPhotonSigOverE", &var11 );
  reader2->AddVariable( "subleadingPhotonSigOverE", &var12 );
  reader2->AddVariable( "sigmaMOverM", &var13 );
  reader2->AddVariable( "(leadingPhoton_pt/CMS_hgg_mass)", &var14 );
  reader2->AddVariable( "(subleadingPhoton_pt/CMS_hgg_mass)", &var15 );
  reader2->AddVariable( "(leadingJet_pt/Mjj)", &var16 );
  reader2->AddVariable( "(subleadingJet_pt/Mjj)", &var17 );
  reader2->AddVariable( "rho", &var18 );
  reader2->AddVariable( "(leadingJet_bRegNNResolution*1.4826)", &var19 );
  reader2->AddVariable( "(subleadingJet_bRegNNResolution*1.4826)", &var20 );
  reader2->AddVariable( "(sigmaMJets*1.4826)", &var21 );
  reader2->AddVariable( "PhoJetMinDr", &var22 );
  reader2->AddVariable( "PhoJetOtherDr", &var23 );

  // book the MVA of your choice (prior training of these methods, ie, existence of the weight files is required)
  //reader->BookMVA( "BDT", "training_with_extended_var_29_11_2019_year2016.weights.xml");
  reader->BookMVA( "BDT", weightFile);
  reader2->BookMVA( "BDT", weightFile2);

  TString fnameAll = indirMVA + fname;
  TFile *inputAll = TFile::Open(fnameAll);

  Float_t absCosThetaStar_CS, absCosTheta_bb, absCosTheta_gg, PhoJetMinDr, customLeadingPhotonIDMVA, customSubLeadingPhotonIDMVA, leadingJet_DeepFlavour, subleadingJet_DeepFlavour, leadingPhotonSigOverE, subleadingPhotonSigOverE, sigmaMOverM, diphotonCandidatePtOverdiHiggsM, dijetCandidatePtOverdiHiggsM, leadingJet_bRegNNResolution, subleadingJet_bRegNNResolution, sigmaMJets, CMS_hgg_mass, leadingPhoton_pt, subleadingPhoton_pt, Mjj, leadingJet_pt, subleadingJet_pt, PhoJetOtherDr, rho;

  TTree *resTree = (TTree*)inputAll->Get("bbggSelectionTree");
  //TTree *resTree = (TTree*)inputAll->Get("tagsDumper/trees/hh2016_13TeV_125_13TeV_DoubleHTag_0");
  //TTree *resTree = (TTree*)inputAll->Get("tagsDumper/trees/bbggSelectionTree");
  //resTree->Print();

  resTree->SetBranchAddress("absCosThetaStar_CS",&absCosThetaStar_CS);
  resTree->SetBranchAddress("absCosTheta_bb",&absCosTheta_bb);
  resTree->SetBranchAddress("absCosTheta_gg",&absCosTheta_gg);
  resTree->SetBranchAddress("PhoJetMinDr",&PhoJetMinDr);
  resTree->SetBranchAddress("customLeadingPhotonIDMVA",&customLeadingPhotonIDMVA);
  resTree->SetBranchAddress("customSubLeadingPhotonIDMVA",&customSubLeadingPhotonIDMVA);
  resTree->SetBranchAddress("leadingJet_DeepFlavour",&leadingJet_DeepFlavour);
  resTree->SetBranchAddress("subleadingJet_DeepFlavour",&subleadingJet_DeepFlavour);
  resTree->SetBranchAddress("leadingPhotonSigOverE",&leadingPhotonSigOverE);
  resTree->SetBranchAddress("subleadingPhotonSigOverE",&subleadingPhotonSigOverE);
  resTree->SetBranchAddress("sigmaMOverM",&sigmaMOverM);
  resTree->SetBranchAddress("diphotonCandidatePtOverdiHiggsM",&diphotonCandidatePtOverdiHiggsM);
  resTree->SetBranchAddress("dijetCandidatePtOverdiHiggsM",&dijetCandidatePtOverdiHiggsM);
  resTree->SetBranchAddress("leadingJet_bRegNNResolution",&leadingJet_bRegNNResolution);
  resTree->SetBranchAddress("subleadingJet_bRegNNResolution",&subleadingJet_bRegNNResolution);
  resTree->SetBranchAddress("sigmaMJets",&sigmaMJets);
  resTree->SetBranchAddress("CMS_hgg_mass",&CMS_hgg_mass);
  resTree->SetBranchAddress("leadingPhoton_pt",&leadingPhoton_pt);
  resTree->SetBranchAddress("subleadingPhoton_pt",&subleadingPhoton_pt);
  resTree->SetBranchAddress("Mjj",&Mjj);
  resTree->SetBranchAddress("leadingJet_pt",&leadingJet_pt);
  resTree->SetBranchAddress("subleadingJet_pt",&subleadingJet_pt);
  resTree->SetBranchAddress("PhoJetOtherDr",&PhoJetOtherDr);
  resTree->SetBranchAddress("rho",&rho);
  resTree->SetBranchStatus("*", 1);

  //TString fileout= dirOut + "xml_" + fname;
  TString fileout= dirOut + fname;
  TFile *target = new TFile(fileout,"RECREATE" );
  TTree *outTree=resTree->CloneTree();
  //with Mjj
  Float_t BDT_response;
  Float_t mvaScaled;
  double flatMVA;
  //w/o Mjj
  Float_t BDT_response2;
  Float_t mvaScaled2;
  double flatMVA2;
  //TBranch *xmlMVA = outTree->Branch("xmlMVA",&BDT_response,"xmlMVA/F");
  TBranch *xmlMVAtransf = outTree->Branch("MVAwithMjj",&flatMVA,"MVAwithMjj/D");
  TBranch *xmlMVAtransf2 = outTree->Branch("MVAwoMjj",&flatMVA2,"MVAwoMjj/D");

  cout<<"Start MVA calculation...."<<endl;

  TStopwatch sw;
  sw.Start();

  for (Long64_t ievt=0; ievt<resTree->GetEntries();ievt++) {

      //if( ievt==2760 || ievt==3128 || ievt== 58910 || ievt==58903 )
     //{ 
      
      resTree->GetEntry(ievt);

      if (ievt%10000 == 0){
         cout << "--- ... Processing event: " << ievt << endl;
      }
      /*
      var1 = absCosThetaStar_CS;
      var2 = absCosTheta_bb;
      var3 = absCosTheta_gg;
      var4 = PhoJetMinDr;
      var5 = customLeadingPhotonIDMVA;
      var6 = customSubLeadingPhotonIDMVA;
      var7 = leadingJet_DeepFlavour;
      var8 = subleadingJet_DeepFlavour;
      var9 = leadingPhotonSigOverE;
      var10 = subleadingPhotonSigOverE;
      var11 = sigmaMOverM;
      var12 = diphotonCandidatePtOverdiHiggsM;
      var13 = dijetCandidatePtOverdiHiggsM;
      var14 = leadingJet_bRegNNResolution;
      var15 = subleadingJet_bRegNNResolution;
      var16 = sigmaMJets;
      var17 = leadingPhoton_pt/CMS_hgg_mass;
      var18 = subleadingPhoton_pt/CMS_hgg_mass;
      var19 = leadingJet_pt/Mjj;
      var20 = subleadingJet_pt/Mjj;
      var21 = PhoJetOtherDr;
      var22 = rho;
      */
      var1 = Mjj;
      var2 = leadingJet_DeepFlavour;
      var3 = subleadingJet_DeepFlavour;  
      var4 = absCosThetaStar_CS;
      var5 = absCosTheta_bb;
      var6 = absCosTheta_gg;
      var7 = diphotonCandidatePtOverdiHiggsM;
      var8 = dijetCandidatePtOverdiHiggsM;
      var9 = customLeadingPhotonIDMVA;
      var10 = customSubLeadingPhotonIDMVA;
      var11 = leadingPhotonSigOverE;
      var12 = subleadingPhotonSigOverE;
      var13 = sigmaMOverM;
      var14 = leadingPhoton_pt/CMS_hgg_mass;
      var15 = subleadingPhoton_pt/CMS_hgg_mass;
      var16 = leadingJet_pt/Mjj;
      var17 = subleadingJet_pt/Mjj;
      var18 = rho;
      var19 = leadingJet_bRegNNResolution*1.4826;
      var20 = subleadingJet_bRegNNResolution*1.4826;
      var21 = sigmaMJets*1.4826;
      var22 = PhoJetMinDr;
      var23 = PhoJetOtherDr;

      //cout<<"rho="<<rho<<endl;
      //with Mjj 
      //retrieve the corresponding MVA output
      //cout<<"mva="<<mva<<endl;
      //BDT_response=reader->EvaluateMVA("BDT");
      BDT_response=(reader->EvaluateMulticlass("BDT"))[2];  //Signal
      //BDT_response=(reader->EvaluateMulticlass("BDT"))[0];  //background 1
      //BDT_response=(reader->EvaluateMulticlass("BDT"))[1];  //background 2
      mvaScaled = BDT_response/(BDT_response*(1.-MVAscaling)+MVAscaling);
      //flatMVA = MVAFlatteningCumulative->Eval(BDT_response);     
      flatMVA = MVAFlatteningCumulative->Eval(mvaScaled);     
      //cout<<"flatMVA="<<flatMVA<<endl; 

     
      BDT_response2=(reader2->EvaluateMulticlass("BDT"))[2];  //Signal
      mvaScaled2 = BDT_response2/(BDT_response2*(1.-MVAscaling)+MVAscaling); 
      flatMVA2 = MVAFlatteningCumulative2->Eval(mvaScaled2);     

      //xmlMVA->Fill(); 
      xmlMVAtransf->Fill(); 
      xmlMVAtransf2->Fill(); 
    //}
  }
  // get elapsed time
  sw.Stop();
  sw.Print();

  outTree->Write();
  MVAFlatteningFile->Close();
  MVAFlatteningFile2->Close();
  target->Close(); 
  delete reader;
  inputAll->Close();

  cout<<"Finish MVA calculation."<<endl;
}

//}
}



 
