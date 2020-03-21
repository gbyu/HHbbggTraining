{
  //for run use root -l -q -b compareROCs.C
  TString indir="/eos/user/i/ivovtin/www/HHbbgg/ROCs/";
  TString MVA1="MVAwoMjj";
  TString MVA2="MVAOutputTransformed";
  TString MVA3="MVAwithMjj";

  TString outdir="/eos/user/i/ivovtin/www/HHbbgg/ROCs/";  

  for (TString year : {"2016","2017","2018"}){
   TFile *_file1 = TFile::Open(outdir+"outROC"+year+MVA1+".root");
   TFile *_file2 = TFile::Open(outdir+"outROC"+year+MVA2+".root");
   TFile *_file3 = TFile::Open(outdir+"outROC"+year+MVA3+".root");

   TH1F *roc1 = (TH1F*)_file1->Get("ROCTF1");
   TH1F *roc2 = (TH1F*)_file2->Get("ROCTF1");
   TH1F *roc3 = (TH1F*)_file3->Get("ROCTF1");

   roc1->SetLineColor(kRed);
   roc1->SetTitle(" ;Background Rejection;Signal Efficiency");
   roc2->SetLineColor(kBlue);
   roc3->SetLineColor(kGreen);

   auto c1 = new TCanvas("c1","c1");
   c1->SetCanvasSize(1500, 1500);
   c1->SetWindowSize(500, 500);

   roc1->Draw();
   roc2->Draw("same");
   roc3->Draw("same");

   auto* legend = new TLegend(0.6,0.5,0.9,0.7);
   legend->AddEntry(roc1,MVA1,"l");
   legend->AddEntry(roc2,MVA2+"- our train","l");
   legend->AddEntry(roc3,MVA3,"l");
   legend->Draw();

   TFile *outfile = new TFile(outdir+"out_compareROCs"+year+".root", "RECREATE");
   c1->Write();
   outfile->Close();
   c1->SaveAs(outdir+"rocComparison"+year+".png");
  }
}
