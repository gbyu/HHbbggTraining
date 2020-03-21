{
  //Calculate ROCs - root -l -q ROC.C 
  TString MVA="MVAwoMjj";
  //TString MVA="MVAwithMjj";
  //TString MVA="MVAOutputTransformed";
  bool beff=1;
  int n=100;
  int min=0; 
  int max=1;
  
  TString cut=""; 

  TString indir="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/synch/";
  TString Sig="output_GluGluToHHTo2B2G_allnodes_no_unit_norm.root";
  TString DiPh="output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root";
  TString GJet1, GJet2;
  TString outdir="/eos/user/i/ivovtin/www/HHbbgg/ROCs/"; 
   
  gSystem->Exec("cp /eos/user/i/ivovtin/www/tmp/index.php "+outdir);

  for (TString year : {"2016","2017","2018"}){

  if(year=="2016"){GJet1 = "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; GJet2 = "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"; }
  else{ GJet1 = "output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"; GJet2 = "output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root";}

  //Open Signal File
  TFile *_file0 = TFile::Open(indir+year+"/"+Sig);
  //Open Bckg file for class 1  
  TFile *_file1 = TFile::Open(indir+year+"/"+DiPh);
  //Open Bckg files for class 2  
  TFile *_file2 = TFile::Open(indir+year+"/"+GJet1);
  TFile *_file3 = TFile::Open(indir+year+"/"+GJet2);

  TTree *t_sig = (TTree*)_file0->Get("bbggSelectionTree");
  TTree *t_bkg1 = (TTree*)_file1->Get("bbggSelectionTree");
  TTree *t_bkg2 = (TTree*)_file2->Get("bbggSelectionTree");
  TTree *t_bkg3 = (TTree*)_file3->Get("bbggSelectionTree");

  TH1F* histoSig = new TH1F("histoSig", ";"+MVA+";",int(n), float(min), float(max));
  TH1F* histoBkg1 = new TH1F("histoBkg1", ";"+MVA+";",int(n), float(min), float(max));
  TH1F* histoBkg2 = new TH1F("histoBkg2", ";"+MVA+";",int(n), float(min), float(max));
  TH1F* histoBkg3 = new TH1F("histoBkg3", ";"+MVA+";",int(n), float(min), float(max));

  t_sig->Draw(MVA+">>histoSig", cut, "goff");
  t_bkg1->Draw(MVA+">>histoBkg1", cut, "goff");
  t_bkg2->Draw(MVA+">>histoBkg2", cut, "goff");
  t_bkg3->Draw(MVA+">>histoBkg3", cut, "goff");

  TH1F* histoBkg = (TH1F*) histoBkg1->Clone("histo");
  histoBkg->Add(histoBkg2);
  histoBkg->Add(histoBkg3);
  
  TH1F* eff_sig = new TH1F("eff_sig", ";"+MVA+";Signal Efficiency", int(n), float(min), float(max));
  TH1F* rej_bac = new TH1F("rej_bac", ";"+MVA+";Background Rejection (1-Eff)", int(n), float(min), float(max));
  
  TGraph *ROC = new TGraph();
  ROC->SetName("ROC");
  //ROC->GetXaxis()->SetTitle("Background Rejection (1-Eff)");  
  ROC->GetXaxis()->SetTitle("Background Rejection");  
  ROC->GetYaxis()->SetTitle("Signal Efficiency");
     
  histoSig->Sumw2();
  histoBkg->Sumw2();
  
  float tot_sig = histoSig->Integral();
  float tot_bkg = histoBkg->Integral();
  histoSig->Scale(1./tot_sig);
  histoBkg->Scale(1./tot_bkg);

  float tst; 
  float var_step = (float(max) - float(min))/float(n);

  float sEff, bRej;

  for (int i = 0; i <= n; i++){
     cout<<n<<endl;    
     tst = float(min) + i*var_step;
    
     sEff = histoSig->Integral(i+1, int(n)+1);     
     bRej = histoBkg->Integral(1, i+1); 
     if(beff==1) bRej = histoBkg->Integral(i+1, int(n)+1);
  
     eff_sig->SetBinContent(i+1, sEff);
     rej_bac->SetBinContent(i+1, bRej);
     //ROC->SetPoint(i, sEff, bRej);        
     ROC->SetPoint(i, bRej, sEff);        
  }
  //make a TF1 from the TGraph::Eval function
  TF1 *feval = new TF1("ROCTF1",[&](double*x, double *p){ return ROC->Eval(x[0]); }, 0, 1, 0);
  
  TFile *outfile = new TFile(outdir+"outROC"+year+MVA+".root", "RECREATE");
  eff_sig->Write();
  rej_bac->Write();
  ROC->Write();
  histoSig->Write();
  histoBkg->Write();
  feval->Write();
  outfile->Close();
  }

}

