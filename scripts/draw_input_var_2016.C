void draw_input_var_2016()
{  
   //gROOT->SetStyle("Plain");
   gStyle->SetOptStat(0);
   //gStyle->SetLineWidth(1);
   gStyle->SetOptTitle(0);
   gStyle->SetLabelSize(0.05,"xyz");
   gStyle->SetTitleSize(0.06,"xyz"); // size of axis title font
   //gStyle->SetLabelOffset(1.2,"xy");
   //gStyle->SetTitleOffset(0.8,"xy");
   gStyle->SetTitleOffset(0.8,"x");
   gStyle->SetTitleOffset(1.3,"y");
   gStyle->SetCanvasBorderMode(0); 
   gStyle->SetCanvasBorderSize(0); 
   gStyle->SetPadBottomMargin(0.12); //margins... 
   gStyle->SetPadTopMargin(0.10); 
   //gStyle->SetPadTopMargin(0.05); 
   //gStyle->SetPadLeftMargin(0.1); 
   gStyle->SetPadLeftMargin(0.15); 
   //gStyle->SetPadRightMargin(0.02);
   gStyle->SetPadRightMargin(0.05);

   //TCanvas *c1 = new TCanvas("c1","с1",0,0,1024,640);
   TCanvas *c1 = new TCanvas("c1","с1",0,0,1024,400);
   //c1->SetFillStyle(4000);
   c1->Divide(4,4);
   //c1->Divide(3,1);
   c1->cd(1); 
   //gPad->SetGrid();
   
   //MC Signal
   TChain* EventTree1 = new TChain("EventTree1","EventTree1");
   //EventTree1->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts.root/bbggSelectionTree");     
   EventTree1->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts_ptMjj/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_st_cuts.root/bbggSelectionTree");     


   //DiPhoton - 1 class bkg
   TChain* EventTree2 = new TChain("EventTree2","EventTree2");
   //EventTree2->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root/bbggSelectionTree");     
   EventTree2->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts_ptMjj/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root/bbggSelectionTree");     

   //GJets - 2 class bkg
   TChain* EventTree3 = new TChain("EventTree3","EventTree3");
   //EventTree3->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_st_cuts.root/bbggSelectionTree");                                                                             
   //EventTree3->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_st_cuts.root/bbggSelectionTree");                                                                             
   EventTree3->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts_ptMjj/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_st_cuts.root/bbggSelectionTree");                                                                             
   EventTree3->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2016/flattrees_st_cuts_ptMjj/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_st_cuts.root/bbggSelectionTree");                                                                             

   //Data
   TChain* EventTree4 = new TChain("EventTree4","EventTree4");
   //EventTree4->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2017/flattrees_st_cuts/DoubleEG_2017_st_cuts.root/bbggSelectionTree");     
   //EventTree4->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2017/flattrees_st_cuts_ptMjj/DoubleEG_2017_st_cuts.root/bbggSelectionTree");     
/*  
   //=====================================================================================
   //1
   TH1F *h1 = new TH1F("h1","h1",30,0,1);
   TH1F *h2 = new TH1F("h2","h2",30,0,1);
   TH1F *h3 = new TH1F("h3","h3",30,0,1);
   h1->GetXaxis()->SetTitle("|cos(#theta^{*}_{CS})|");
   h1->GetYaxis()->SetTitle("Events");   
   h1->SetLineColor(kBlue);
   h1->SetLineWidth(1);
   h1->SetFillStyle(3005);
   h1->SetFillColor(kBlue);
   h2->SetLineColor(kGreen);
   h2->SetLineWidth(1);
   h2->SetFillStyle(3005);
   h2->SetFillColor(kGreen);
   h3->SetLineColor(kRed);
   h3->SetLineWidth(1);
   h3->SetFillStyle(3005);
   h3->SetFillColor(kRed);
   EventTree1->Draw("absCosThetaStar_CS >> h1","","norm");           //MC Signal      
   EventTree2->Draw("absCosThetaStar_CS >> h2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("absCosThetaStar_CS >> h3","","norm");           //GJets - 2 class bkg   
   h1->GetXaxis()->SetRangeUser(0.,1.);
   h1->GetYaxis()->SetRangeUser(0.,0.25);
   h1->Draw("hist");
   h2->Draw("hist,same");
   h3->Draw("hist,same");
   TLegend *legend = new TLegend(0.60,0.60,0.75,0.88);
   legend->AddEntry(h1,"Signal","f");
   legend->AddEntry(h2,"#gamma#gamma+Jets","f");
   legend->AddEntry(h3,"j#gamma+Jets","f");
   legend->Draw();
   //============================================================================
   //2
   c1->cd(2); 
   TH1F *hcosbb1 = new TH1F("hcosbb1","hcosbb1",60,0,1);
   TH1F *hcosbb2 = new TH1F("hcosbb2","hcosbb2",60,0,1);
   TH1F *hcosbb3 = new TH1F("hcosbb3","hcosbb3",60,0,1);
   hcosbb1->GetXaxis()->SetTitle("|cos(#theta_{bb})|");
   hcosbb1->GetYaxis()->SetTitle("Events");   
   hcosbb1->SetLineColor(kBlue);
   hcosbb1->SetLineWidth(1);
   hcosbb1->SetFillStyle(3005);
   hcosbb1->SetFillColor(kBlue);
   hcosbb2->SetLineColor(kGreen);
   hcosbb2->SetLineWidth(1);
   hcosbb2->SetFillStyle(3005);
   hcosbb2->SetFillColor(kGreen);
   hcosbb3->SetLineColor(kRed);
   hcosbb3->SetLineWidth(1);
   hcosbb3->SetFillStyle(3005);
   hcosbb3->SetFillColor(kRed);
   TLegend *lhcosbb = new TLegend(0.60,0.60,0.75,0.88);
   lhcosbb->AddEntry(hcosbb1,"Signal","f");
   lhcosbb->AddEntry(hcosbb2,"#gamma#gamma+Jets","f");
   lhcosbb->AddEntry(hcosbb3,"j#gamma+Jets","f");   
   EventTree1->Draw("absCosTheta_bb >> hcosbb1","","norm");           //MC Signal      
   EventTree2->Draw("absCosTheta_bb >> hcosbb2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("absCosTheta_bb >> hcosbb3","","norm");           //GJets - 2 class bkg   
   hcosbb1->GetXaxis()->SetRangeUser(0.,1.);
   hcosbb1->GetYaxis()->SetRangeUser(0.,0.04);
   hcosbb1->Draw("hist");
   hcosbb2->Draw("hist,same");
   hcosbb3->Draw("hist,same");
   lhcosbb->Draw();
   //=====================================================================================
   //3
   c1->cd(3);
   TH1F *hcosgg1 = new TH1F("hcosgg1","hcosgg1",60,0,1);
   TH1F *hcosgg2 = new TH1F("hcosgg2","hcosgg2",60,0,1);
   TH1F *hcosgg3 = new TH1F("hcosgg3","hcosgg3",60,0,1);
   hcosgg1->GetXaxis()->SetTitle("|cos(#theta_{#gamma#gamma})|");
   hcosgg1->GetYaxis()->SetTitle("Events");   
   hcosgg1->SetLineColor(kBlue);
   hcosgg1->SetLineWidth(1);
   hcosgg1->SetFillStyle(3005);
   hcosgg1->SetFillColor(kBlue);
   hcosgg2->SetLineColor(kGreen);
   hcosgg2->SetLineWidth(1);
   hcosgg2->SetFillStyle(3005);
   hcosgg2->SetFillColor(kGreen);
   hcosgg3->SetLineColor(kRed);
   hcosgg3->SetLineWidth(1);
   hcosgg3->SetFillStyle(3005);
   hcosgg3->SetFillColor(kRed);
   TLegend *lhcosgg = new TLegend(0.60,0.60,0.75,0.88);
   lhcosgg->AddEntry(hcosgg1,"Signal","f");
   lhcosgg->AddEntry(hcosgg2,"#gamma#gamma+Jets","f");
   lhcosgg->AddEntry(hcosgg3,"j#gamma+Jets","f");
   EventTree1->Draw("absCosTheta_gg >> hcosgg1","","norm");           //MC Signal      
   EventTree2->Draw("absCosTheta_gg >> hcosgg2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("absCosTheta_gg >> hcosgg3","","norm");           //GJets - 2 class bkg   
   hcosgg1->GetXaxis()->SetRangeUser(0.,1.);
   hcosgg1->GetYaxis()->SetRangeUser(0.,0.025);
   hcosgg1->Draw("hist");
   hcosgg2->Draw("hist,same");
   hcosgg3->Draw("hist,same");
   lhcosgg->Draw();

   //=====================================================================================
   //4
   c1->cd(4);
   TH1F *hPhoJetMinDr1 = new TH1F("hPhoJetMinDr1","hPhoJetMinDr1",60,0,6);
   TH1F *hPhoJetMinDr2 = new TH1F("hPhoJetMinDr2","hPhoJetMinDr2",60,0,6);
   TH1F *hPhoJetMinDr3 = new TH1F("hPhoJetMinDr3","hPhoJetMinDr3",60,0,6);
   hPhoJetMinDr1->GetXaxis()->SetTitle("PhoJetMinDr");
   hPhoJetMinDr1->GetYaxis()->SetTitle("Events");   
   hPhoJetMinDr1->SetLineColor(kBlue);
   hPhoJetMinDr1->SetLineWidth(1);
   hPhoJetMinDr1->SetFillStyle(3005);
   hPhoJetMinDr1->SetFillColor(kBlue);
   hPhoJetMinDr2->SetLineColor(kGreen);
   hPhoJetMinDr2->SetLineWidth(1);
   hPhoJetMinDr2->SetFillStyle(3005);
   hPhoJetMinDr2->SetFillColor(kGreen);
   hPhoJetMinDr3->SetLineColor(kRed);
   hPhoJetMinDr3->SetLineWidth(1);
   hPhoJetMinDr3->SetFillStyle(3005);
   hPhoJetMinDr3->SetFillColor(kRed);
   TLegend *lhPhoJetMinDr = new TLegend(0.60,0.60,0.75,0.88);
   lhPhoJetMinDr->AddEntry(hPhoJetMinDr1,"Signal","f");
   lhPhoJetMinDr->AddEntry(hPhoJetMinDr2,"#gamma#gamma+Jets","f");
   lhPhoJetMinDr->AddEntry(hPhoJetMinDr3,"j#gamma+Jets","f");
   EventTree1->Draw("PhoJetMinDr >> hPhoJetMinDr1","","norm");           //MC Signal      
   EventTree2->Draw("PhoJetMinDr >> hPhoJetMinDr2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("PhoJetMinDr >> hPhoJetMinDr3","","norm");           //GJets - 2 class bkg   
   hPhoJetMinDr1->GetXaxis()->SetRangeUser(0.,6.);
   hPhoJetMinDr1->GetYaxis()->SetRangeUser(0.,0.08);
   hPhoJetMinDr1->Draw("hist");
   hPhoJetMinDr2->Draw("hist,same");
   hPhoJetMinDr3->Draw("hist,same");
   lhPhoJetMinDr->Draw();

   //==========================================================================
   //5
   c1->cd(5);
   TH1F *hcustomLeadingPhotonIDMVA1 = new TH1F("hcustomLeadingPhotonIDMVA1","hcustomLeadingPhotonIDMVA1",60,-1,1);
   TH1F *hcustomLeadingPhotonIDMVA2 = new TH1F("hcustomLeadingPhotonIDMVA2","hcustomLeadingPhotonIDMVA2",60,-1,1);
   TH1F *hcustomLeadingPhotonIDMVA3 = new TH1F("hcustomLeadingPhotonIDMVA3","hcustomLeadingPhotonIDMVA3",60,-1,1);
   hcustomLeadingPhotonIDMVA1->GetXaxis()->SetTitle("Custom Leading Photon ID MVA");
   hcustomLeadingPhotonIDMVA1->GetYaxis()->SetTitle("Events");   
   hcustomLeadingPhotonIDMVA1->SetLineColor(kBlue);
   hcustomLeadingPhotonIDMVA1->SetLineWidth(1);
   hcustomLeadingPhotonIDMVA1->SetFillStyle(3005);
   hcustomLeadingPhotonIDMVA1->SetFillColor(kBlue);
   hcustomLeadingPhotonIDMVA2->SetLineColor(kGreen);
   hcustomLeadingPhotonIDMVA2->SetLineWidth(1);
   hcustomLeadingPhotonIDMVA2->SetFillStyle(3005);
   hcustomLeadingPhotonIDMVA2->SetFillColor(kGreen);
   hcustomLeadingPhotonIDMVA3->SetLineColor(kRed);
   hcustomLeadingPhotonIDMVA3->SetLineWidth(1);
   hcustomLeadingPhotonIDMVA3->SetFillStyle(3005);
   hcustomLeadingPhotonIDMVA3->SetFillColor(kRed);
   TLegend *lhcustomLeadingPhotonIDMVA = new TLegend(0.60,0.60,0.75,0.88);
   lhcustomLeadingPhotonIDMVA->AddEntry(hcustomLeadingPhotonIDMVA1,"Signal","f");
   lhcustomLeadingPhotonIDMVA->AddEntry(hcustomLeadingPhotonIDMVA2,"#gamma#gamma+Jets","f");
   lhcustomLeadingPhotonIDMVA->AddEntry(hcustomLeadingPhotonIDMVA3,"j#gamma+Jets","f");
   EventTree1->Draw("customLeadingPhotonIDMVA >> hcustomLeadingPhotonIDMVA1","","norm");           //MC Signal      
   EventTree2->Draw("customLeadingPhotonIDMVA >> hcustomLeadingPhotonIDMVA2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("customLeadingPhotonIDMVA >> hcustomLeadingPhotonIDMVA3","","norm");           //GJets - 2 class bkg   
   hcustomLeadingPhotonIDMVA1->GetXaxis()->SetRangeUser(-1.,1.);
   hcustomLeadingPhotonIDMVA1->GetYaxis()->SetRangeUser(0.,0.40);
   hcustomLeadingPhotonIDMVA1->Draw("hist");
   hcustomLeadingPhotonIDMVA2->Draw("hist,same");
   hcustomLeadingPhotonIDMVA3->Draw("hist,same");
   lhcustomLeadingPhotonIDMVA->Draw();

   //==========================================================================
   //6
   c1->cd(6);
   TH1F *hcustomSubLeadingPhotonIDMVA1 = new TH1F("hcustomSubLeadingPhotonIDMVA1","hcustomSubLeadingPhotonIDMVA1",60,-1,1);
   TH1F *hcustomSubLeadingPhotonIDMVA2 = new TH1F("hcustomSubLeadingPhotonIDMVA2","hcustomSubLeadingPhotonIDMVA2",60,-1,1);
   TH1F *hcustomSubLeadingPhotonIDMVA3 = new TH1F("hcustomSubLeadingPhotonIDMVA3","hcustomSubLeadingPhotonIDMVA3",60,-1,1);
   hcustomSubLeadingPhotonIDMVA1->GetXaxis()->SetTitle("Custom SubLeading Photon ID MVA");
   hcustomSubLeadingPhotonIDMVA1->GetYaxis()->SetTitle("Events");   
   hcustomSubLeadingPhotonIDMVA1->SetLineColor(kBlue);
   hcustomSubLeadingPhotonIDMVA1->SetLineWidth(1);
   hcustomSubLeadingPhotonIDMVA1->SetFillStyle(3005);
   hcustomSubLeadingPhotonIDMVA1->SetFillColor(kBlue);
   hcustomSubLeadingPhotonIDMVA2->SetLineColor(kGreen);
   hcustomSubLeadingPhotonIDMVA2->SetLineWidth(1);
   hcustomSubLeadingPhotonIDMVA2->SetFillStyle(3005);
   hcustomSubLeadingPhotonIDMVA2->SetFillColor(kGreen);
   hcustomSubLeadingPhotonIDMVA3->SetLineColor(kRed);
   hcustomSubLeadingPhotonIDMVA3->SetLineWidth(1);
   hcustomSubLeadingPhotonIDMVA3->SetFillStyle(3005);
   hcustomSubLeadingPhotonIDMVA3->SetFillColor(kRed);
   TLegend *lhcustomSubLeadingPhotonIDMVA = new TLegend(0.60,0.60,0.75,0.88);
   lhcustomSubLeadingPhotonIDMVA->AddEntry(hcustomSubLeadingPhotonIDMVA1,"Signal","f");
   lhcustomSubLeadingPhotonIDMVA->AddEntry(hcustomSubLeadingPhotonIDMVA2,"#gamma#gamma+Jets","f");
   lhcustomSubLeadingPhotonIDMVA->AddEntry(hcustomSubLeadingPhotonIDMVA3,"j#gamma+Jets","f");
   EventTree1->Draw("customSubLeadingPhotonIDMVA >> hcustomSubLeadingPhotonIDMVA1","","norm");           //MC Signal      
   EventTree2->Draw("customSubLeadingPhotonIDMVA >> hcustomSubLeadingPhotonIDMVA2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("customSubLeadingPhotonIDMVA >> hcustomSubLeadingPhotonIDMVA3","","norm");           //GJets - 2 class bkg   
   hcustomSubLeadingPhotonIDMVA1->GetXaxis()->SetRangeUser(-1.,1.);
   hcustomSubLeadingPhotonIDMVA1->GetYaxis()->SetRangeUser(0.,0.30);
   hcustomSubLeadingPhotonIDMVA1->Draw("hist");
   hcustomSubLeadingPhotonIDMVA2->Draw("hist,same");
   hcustomSubLeadingPhotonIDMVA3->Draw("hist,same");
   lhcustomSubLeadingPhotonIDMVA->Draw();

   //==========================================================================
   //7
   c1->cd(7);
   TH1F *hleadingJet_DeepCSV1 = new TH1F("hleadingJet_DeepCSV1","hleadingJet_DeepCSV1",60,0,1);
   TH1F *hleadingJet_DeepCSV2 = new TH1F("hleadingJet_DeepCSV2","hleadingJet_DeepCSV2",60,0,1);
   TH1F *hleadingJet_DeepCSV3 = new TH1F("hleadingJet_DeepCSV3","hleadingJet_DeepCSV3",60,0,1);
   hleadingJet_DeepCSV1->GetXaxis()->SetTitle("Deep CSV leading Jet");
   hleadingJet_DeepCSV1->GetYaxis()->SetTitle("Events");   
   hleadingJet_DeepCSV1->SetLineColor(kBlue);
   hleadingJet_DeepCSV1->SetLineWidth(1);
   hleadingJet_DeepCSV1->SetFillStyle(3005);
   hleadingJet_DeepCSV1->SetFillColor(kBlue);
   hleadingJet_DeepCSV2->SetLineColor(kGreen);
   hleadingJet_DeepCSV2->SetLineWidth(1);
   hleadingJet_DeepCSV2->SetFillStyle(3005);
   hleadingJet_DeepCSV2->SetFillColor(kGreen);
   hleadingJet_DeepCSV3->SetLineColor(kRed);
   hleadingJet_DeepCSV3->SetLineWidth(1);
   hleadingJet_DeepCSV3->SetFillStyle(3005);
   hleadingJet_DeepCSV3->SetFillColor(kRed);
   TLegend *lhleadingJet_DeepCSV = new TLegend(0.60,0.60,0.75,0.88);
   lhleadingJet_DeepCSV->AddEntry(hleadingJet_DeepCSV1,"Signal","f");
   lhleadingJet_DeepCSV->AddEntry(hleadingJet_DeepCSV2,"#gamma#gamma+Jets","f");
   lhleadingJet_DeepCSV->AddEntry(hleadingJet_DeepCSV3,"j#gamma+Jets","f");
   EventTree1->Draw("leadingJet_DeepCSV >> hleadingJet_DeepCSV1","","norm");           //MC Signal      
   EventTree2->Draw("leadingJet_DeepCSV >> hleadingJet_DeepCSV2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("leadingJet_DeepCSV >> hleadingJet_DeepCSV3","","norm");           //GJets - 2 class bkg   
   hleadingJet_DeepCSV1->GetXaxis()->SetRangeUser(0.,1.);
   hleadingJet_DeepCSV1->GetYaxis()->SetRangeUser(0.,0.40);
   hleadingJet_DeepCSV1->Draw("hist");
   hleadingJet_DeepCSV2->Draw("hist,same");
   hleadingJet_DeepCSV3->Draw("hist,same");
   lhleadingJet_DeepCSV->Draw();

   //==========================================================================
   //8
   c1->cd(8);
   TH1F *hsubleadingJet_DeepCSV1 = new TH1F("hsubleadingJet_DeepCSV1","hsubleadingJet_DeepCSV1",60,0,1);
   TH1F *hsubleadingJet_DeepCSV2 = new TH1F("hsubleadingJet_DeepCSV2","hsubleadingJet_DeepCSV2",60,0,1);
   TH1F *hsubleadingJet_DeepCSV3 = new TH1F("hsubleadingJet_DeepCSV3","hsubleadingJet_DeepCSV3",60,0,1);
   hsubleadingJet_DeepCSV1->GetXaxis()->SetTitle("Deep CSV subleading Jet");
   hsubleadingJet_DeepCSV1->GetYaxis()->SetTitle("Events");   
   hsubleadingJet_DeepCSV1->SetLineColor(kBlue);
   hsubleadingJet_DeepCSV1->SetLineWidth(1);
   hsubleadingJet_DeepCSV1->SetFillStyle(3005);
   hsubleadingJet_DeepCSV1->SetFillColor(kBlue);
   hsubleadingJet_DeepCSV2->SetLineColor(kGreen);
   hsubleadingJet_DeepCSV2->SetLineWidth(1);
   hsubleadingJet_DeepCSV2->SetFillStyle(3005);
   hsubleadingJet_DeepCSV2->SetFillColor(kGreen);
   hsubleadingJet_DeepCSV3->SetLineColor(kRed);
   hsubleadingJet_DeepCSV3->SetLineWidth(1);
   hsubleadingJet_DeepCSV3->SetFillStyle(3005);
   hsubleadingJet_DeepCSV3->SetFillColor(kRed);
   TLegend *lhsubleadingJet_DeepCSV = new TLegend(0.60,0.60,0.75,0.88);
   lhsubleadingJet_DeepCSV->AddEntry(hsubleadingJet_DeepCSV1,"Signal","f");
   lhsubleadingJet_DeepCSV->AddEntry(hsubleadingJet_DeepCSV2,"#gamma#gamma+Jets","f");
   lhsubleadingJet_DeepCSV->AddEntry(hsubleadingJet_DeepCSV3,"j#gamma+Jets","f");
   EventTree1->Draw("subleadingJet_DeepCSV >> hsubleadingJet_DeepCSV1","","norm");           //MC Signal      
   EventTree2->Draw("subleadingJet_DeepCSV >> hsubleadingJet_DeepCSV2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("subleadingJet_DeepCSV >> hsubleadingJet_DeepCSV3","","norm");           //GJets - 2 class bkg   
   hsubleadingJet_DeepCSV1->GetXaxis()->SetRangeUser(0.,1.);
   hsubleadingJet_DeepCSV1->GetYaxis()->SetRangeUser(0.,0.40);
   hsubleadingJet_DeepCSV1->Draw("hist");
   hsubleadingJet_DeepCSV2->Draw("hist,same");
   hsubleadingJet_DeepCSV3->Draw("hist,same");
   lhsubleadingJet_DeepCSV->Draw();

   //==========================================================================
   //9
   c1->cd(9);
   TH1F *hleadingPhotonSigOverE1 = new TH1F("hleadingPhotonSigOverE1","hleadingPhotonSigOverE1",60,0,0.1);
   TH1F *hleadingPhotonSigOverE2 = new TH1F("hleadingPhotonSigOverE2","hleadingPhotonSigOverE2",60,0,0.1);
   TH1F *hleadingPhotonSigOverE3 = new TH1F("hleadingPhotonSigOverE3","hleadingPhotonSigOverE3",60,0,0.1);
   hleadingPhotonSigOverE1->GetXaxis()->SetTitle("Leading Photon #sigma_{E}/E");
   hleadingPhotonSigOverE1->GetYaxis()->SetTitle("Events");   
   hleadingPhotonSigOverE1->SetLineColor(kBlue);
   hleadingPhotonSigOverE1->SetLineWidth(1);
   hleadingPhotonSigOverE1->SetFillStyle(3005);
   hleadingPhotonSigOverE1->SetFillColor(kBlue);
   hleadingPhotonSigOverE2->SetLineColor(kGreen);
   hleadingPhotonSigOverE2->SetLineWidth(1);
   hleadingPhotonSigOverE2->SetFillStyle(3005);
   hleadingPhotonSigOverE2->SetFillColor(kGreen);
   hleadingPhotonSigOverE3->SetLineColor(kRed);
   hleadingPhotonSigOverE3->SetLineWidth(1);
   hleadingPhotonSigOverE3->SetFillStyle(3005);
   hleadingPhotonSigOverE3->SetFillColor(kRed);
   TLegend *lhleadingPhotonSigOverE = new TLegend(0.60,0.60,0.75,0.88);
   lhleadingPhotonSigOverE->AddEntry(hleadingPhotonSigOverE1,"Signal","f");
   lhleadingPhotonSigOverE->AddEntry(hleadingPhotonSigOverE2,"#gamma#gamma+Jets","f");
   lhleadingPhotonSigOverE->AddEntry(hleadingPhotonSigOverE3,"j#gamma+Jets","f");
   EventTree1->Draw("leadingPhotonSigOverE >> hleadingPhotonSigOverE1","","norm");           //MC Signal      
   EventTree2->Draw("leadingPhotonSigOverE >> hleadingPhotonSigOverE2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("leadingPhotonSigOverE >> hleadingPhotonSigOverE3","","norm");           //GJets - 2 class bkg   
   hleadingPhotonSigOverE1->GetXaxis()->SetRangeUser(0.,0.1);
   hleadingPhotonSigOverE1->GetYaxis()->SetRangeUser(0.,0.55);
   hleadingPhotonSigOverE1->Draw("hist");
   hleadingPhotonSigOverE2->Draw("hist,same");
   hleadingPhotonSigOverE3->Draw("hist,same");
   lhleadingPhotonSigOverE->Draw();

   //==========================================================================
   //10
   c1->cd(10);
   TH1F *hsubleadingPhotonSigOverE1 = new TH1F("hsubleadingPhotonSigOverE1","hsubleadingPhotonSigOverE1",60,0,0.1);
   TH1F *hsubleadingPhotonSigOverE2 = new TH1F("hsubleadingPhotonSigOverE2","hsubleadingPhotonSigOverE2",60,0,0.1);
   TH1F *hsubleadingPhotonSigOverE3 = new TH1F("hsubleadingPhotonSigOverE3","hsubleadingPhotonSigOverE3",60,0,0.1);
   hsubleadingPhotonSigOverE1->GetXaxis()->SetTitle("Subleading Photon #sigma_{E}/E");
   hsubleadingPhotonSigOverE1->GetYaxis()->SetTitle("Events");   
   hsubleadingPhotonSigOverE1->SetLineColor(kBlue);
   hsubleadingPhotonSigOverE1->SetLineWidth(1);
   hsubleadingPhotonSigOverE1->SetFillStyle(3005);
   hsubleadingPhotonSigOverE1->SetFillColor(kBlue);
   hsubleadingPhotonSigOverE2->SetLineColor(kGreen);
   hsubleadingPhotonSigOverE2->SetLineWidth(1);
   hsubleadingPhotonSigOverE2->SetFillStyle(3005);
   hsubleadingPhotonSigOverE2->SetFillColor(kGreen);
   hsubleadingPhotonSigOverE3->SetLineColor(kRed);
   hsubleadingPhotonSigOverE3->SetLineWidth(1);
   hsubleadingPhotonSigOverE3->SetFillStyle(3005);
   hsubleadingPhotonSigOverE3->SetFillColor(kRed);
   TLegend *lhsubleadingPhotonSigOverE = new TLegend(0.60,0.60,0.75,0.88);
   lhsubleadingPhotonSigOverE->AddEntry(hsubleadingPhotonSigOverE1,"Signal","f");
   lhsubleadingPhotonSigOverE->AddEntry(hsubleadingPhotonSigOverE2,"#gamma#gamma+Jets","f");
   lhsubleadingPhotonSigOverE->AddEntry(hsubleadingPhotonSigOverE3,"j#gamma+Jets","f");
   EventTree1->Draw("subleadingPhotonSigOverE >> hsubleadingPhotonSigOverE1","","norm");           //MC Signal      
   EventTree2->Draw("subleadingPhotonSigOverE >> hsubleadingPhotonSigOverE2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("subleadingPhotonSigOverE >> hsubleadingPhotonSigOverE3","","norm");           //GJets - 2 class bkg   
   hsubleadingPhotonSigOverE1->GetXaxis()->SetRangeUser(0.,0.1);
   hsubleadingPhotonSigOverE1->GetYaxis()->SetRangeUser(0.,0.40);
   hsubleadingPhotonSigOverE1->Draw("hist");
   hsubleadingPhotonSigOverE2->Draw("hist,same");
   hsubleadingPhotonSigOverE3->Draw("hist,same");
   lhsubleadingPhotonSigOverE->Draw();

   //==========================================================================
   //11
   c1->cd(11);
   TH1F *hdiphotonCandidatePtOverdiHiggsM1 = new TH1F("hdiphotonCandidatePtOverdiHiggsM1","hdiphotonCandidatePtOverdiHiggsM1",80,0,1.2);
   TH1F *hdiphotonCandidatePtOverdiHiggsM2 = new TH1F("hdiphotonCandidatePtOverdiHiggsM2","hdiphotonCandidatePtOverdiHiggsM2",80,0,1.2);
   TH1F *hdiphotonCandidatePtOverdiHiggsM3 = new TH1F("hdiphotonCandidatePtOverdiHiggsM3","hdiphotonCandidatePtOverdiHiggsM3",80,0,1.2);
   hdiphotonCandidatePtOverdiHiggsM1->GetXaxis()->SetTitle("p_{T(#gamma#gamma)}/M(jj#gamma#gamma)");
   hdiphotonCandidatePtOverdiHiggsM1->GetYaxis()->SetTitle("Events");   
   hdiphotonCandidatePtOverdiHiggsM1->SetLineColor(kBlue);
   hdiphotonCandidatePtOverdiHiggsM1->SetLineWidth(1);
   hdiphotonCandidatePtOverdiHiggsM1->SetFillStyle(3005);
   hdiphotonCandidatePtOverdiHiggsM1->SetFillColor(kBlue);
   hdiphotonCandidatePtOverdiHiggsM2->SetLineColor(kGreen);
   hdiphotonCandidatePtOverdiHiggsM2->SetLineWidth(1);
   hdiphotonCandidatePtOverdiHiggsM2->SetFillStyle(3005);
   hdiphotonCandidatePtOverdiHiggsM2->SetFillColor(kGreen);
   hdiphotonCandidatePtOverdiHiggsM3->SetLineColor(kRed);
   hdiphotonCandidatePtOverdiHiggsM3->SetLineWidth(1);
   hdiphotonCandidatePtOverdiHiggsM3->SetFillStyle(3005);
   hdiphotonCandidatePtOverdiHiggsM3->SetFillColor(kRed);
   TLegend *lhdiphotonCandidatePtOverdiHiggsM = new TLegend(0.60,0.60,0.75,0.88);
   lhdiphotonCandidatePtOverdiHiggsM->AddEntry(hdiphotonCandidatePtOverdiHiggsM1,"Signal","f");
   lhdiphotonCandidatePtOverdiHiggsM->AddEntry(hdiphotonCandidatePtOverdiHiggsM2,"#gamma#gamma+Jets","f");
   lhdiphotonCandidatePtOverdiHiggsM->AddEntry(hdiphotonCandidatePtOverdiHiggsM3,"j#gamma+Jets","f");
   EventTree1->Draw("diphotonCandidatePtOverdiHiggsM >> hdiphotonCandidatePtOverdiHiggsM1","","norm");           //MC Signal      
   EventTree2->Draw("diphotonCandidatePtOverdiHiggsM >> hdiphotonCandidatePtOverdiHiggsM2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("diphotonCandidatePtOverdiHiggsM >> hdiphotonCandidatePtOverdiHiggsM3","","norm");           //GJets - 2 class bkg   
   hdiphotonCandidatePtOverdiHiggsM1->GetXaxis()->SetRangeUser(0.,1.2);
   hdiphotonCandidatePtOverdiHiggsM1->GetYaxis()->SetRangeUser(0.,0.06);
   hdiphotonCandidatePtOverdiHiggsM1->Draw("hist");
   hdiphotonCandidatePtOverdiHiggsM2->Draw("hist,same");
   hdiphotonCandidatePtOverdiHiggsM3->Draw("hist,same");
   lhdiphotonCandidatePtOverdiHiggsM->Draw();

   //==========================================================================
   //12
   c1->cd(12);
   TH1F *hdijetCandidatePtOverdiHiggsM1 = new TH1F("hdijetCandidatePtOverdiHiggsM1","hdijetCandidatePtOverdiHiggsM1",80,0,1.2);
   TH1F *hdijetCandidatePtOverdiHiggsM2 = new TH1F("hdijetCandidatePtOverdiHiggsM2","hdijetCandidatePtOverdiHiggsM2",80,0,1.2);
   TH1F *hdijetCandidatePtOverdiHiggsM3 = new TH1F("hdijetCandidatePtOverdiHiggsM3","hdijetCandidatePtOverdiHiggsM3",80,0,1.2);
   hdijetCandidatePtOverdiHiggsM1->GetXaxis()->SetTitle("p_{T(jj)}/M(jj#gamma#gamma)");
   hdijetCandidatePtOverdiHiggsM1->GetYaxis()->SetTitle("Events");   
   hdijetCandidatePtOverdiHiggsM1->SetLineColor(kBlue);
   hdijetCandidatePtOverdiHiggsM1->SetLineWidth(1);
   hdijetCandidatePtOverdiHiggsM1->SetFillStyle(3005);
   hdijetCandidatePtOverdiHiggsM1->SetFillColor(kBlue);
   hdijetCandidatePtOverdiHiggsM2->SetLineColor(kGreen);
   hdijetCandidatePtOverdiHiggsM2->SetLineWidth(1);
   hdijetCandidatePtOverdiHiggsM2->SetFillStyle(3005);
   hdijetCandidatePtOverdiHiggsM2->SetFillColor(kGreen);
   hdijetCandidatePtOverdiHiggsM3->SetLineColor(kRed);
   hdijetCandidatePtOverdiHiggsM3->SetLineWidth(1);
   hdijetCandidatePtOverdiHiggsM3->SetFillStyle(3005);
   hdijetCandidatePtOverdiHiggsM3->SetFillColor(kRed);
   TLegend *lhdijetCandidatePtOverdiHiggsM = new TLegend(0.60,0.60,0.75,0.88);
   lhdijetCandidatePtOverdiHiggsM->AddEntry(hdijetCandidatePtOverdiHiggsM1,"Signal","f");
   lhdijetCandidatePtOverdiHiggsM->AddEntry(hdijetCandidatePtOverdiHiggsM2,"#gamma#gamma+Jets","f");
   lhdijetCandidatePtOverdiHiggsM->AddEntry(hdijetCandidatePtOverdiHiggsM3,"j#gamma+Jets","f");
   EventTree1->Draw("dijetCandidatePtOverdiHiggsM >> hdijetCandidatePtOverdiHiggsM1","","norm");           //MC Signal      
   EventTree2->Draw("dijetCandidatePtOverdiHiggsM >> hdijetCandidatePtOverdiHiggsM2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("dijetCandidatePtOverdiHiggsM >> hdijetCandidatePtOverdiHiggsM3","","norm");           //GJets - 2 class bkg   
   hdijetCandidatePtOverdiHiggsM1->GetXaxis()->SetRangeUser(0.,1.2);
   hdijetCandidatePtOverdiHiggsM1->GetYaxis()->SetRangeUser(0.,0.06);
   hdijetCandidatePtOverdiHiggsM1->Draw("hist");
   hdijetCandidatePtOverdiHiggsM2->Draw("hist,same");
   hdijetCandidatePtOverdiHiggsM3->Draw("hist,same");
   lhdijetCandidatePtOverdiHiggsM->Draw();

   //==========================================================================
   //13
   c1->cd(13);
   TH1F *hleadingJet_bRegNNResolution1 = new TH1F("hleadingJet_bRegNNResolution1","hleadingJet_bRegNNResolution1",80,0,0.3);
   TH1F *hleadingJet_bRegNNResolution2 = new TH1F("hleadingJet_bRegNNResolution2","hleadingJet_bRegNNResolution2",80,0,0.3);
   TH1F *hleadingJet_bRegNNResolution3 = new TH1F("hleadingJet_bRegNNResolution3","hleadingJet_bRegNNResolution3",80,0,0.3);
   hleadingJet_bRegNNResolution1->GetXaxis()->SetTitle("Leading Jet bRegNNResolution");
   hleadingJet_bRegNNResolution1->GetYaxis()->SetTitle("Events");   
   hleadingJet_bRegNNResolution1->SetLineColor(kBlue);
   hleadingJet_bRegNNResolution1->SetLineWidth(1);
   hleadingJet_bRegNNResolution1->SetFillStyle(3005);
   hleadingJet_bRegNNResolution1->SetFillColor(kBlue);
   hleadingJet_bRegNNResolution2->SetLineColor(kGreen);
   hleadingJet_bRegNNResolution2->SetLineWidth(1);
   hleadingJet_bRegNNResolution2->SetFillStyle(3005);
   hleadingJet_bRegNNResolution2->SetFillColor(kGreen);
   hleadingJet_bRegNNResolution3->SetLineColor(kRed);
   hleadingJet_bRegNNResolution3->SetLineWidth(1);
   hleadingJet_bRegNNResolution3->SetFillStyle(3005);
   hleadingJet_bRegNNResolution3->SetFillColor(kRed);
   TLegend *lhleadingJet_bRegNNResolution = new TLegend(0.60,0.60,0.75,0.88);
   lhleadingJet_bRegNNResolution->AddEntry(hleadingJet_bRegNNResolution1,"Signal","f");
   lhleadingJet_bRegNNResolution->AddEntry(hleadingJet_bRegNNResolution2,"#gamma#gamma+Jets","f");
   lhleadingJet_bRegNNResolution->AddEntry(hleadingJet_bRegNNResolution3,"j#gamma+Jets","f");
   EventTree1->Draw("leadingJet_bRegNNResolution >> hleadingJet_bRegNNResolution1","","norm");           //MC Signal      
   EventTree2->Draw("leadingJet_bRegNNResolution >> hleadingJet_bRegNNResolution2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("leadingJet_bRegNNResolution >> hleadingJet_bRegNNResolution3","","norm");           //GJets - 2 class bkg   
   hleadingJet_bRegNNResolution1->GetXaxis()->SetRangeUser(0.,0.3);
   hleadingJet_bRegNNResolution1->GetYaxis()->SetRangeUser(0.,0.07);
   hleadingJet_bRegNNResolution1->Draw("hist");
   hleadingJet_bRegNNResolution2->Draw("hist,same");
   hleadingJet_bRegNNResolution3->Draw("hist,same");
   lhleadingJet_bRegNNResolution->Draw();

   //==========================================================================
   //14
   c1->cd(14);
   TH1F *hsubleadingJet_bRegNNResolution1 = new TH1F("hsubleadingJet_bRegNNResolution1","hsubleadingJet_bRegNNResolution1",80,0,0.4);
   TH1F *hsubleadingJet_bRegNNResolution2 = new TH1F("hsubleadingJet_bRegNNResolution2","hsubleadingJet_bRegNNResolution2",80,0,0.4);
   TH1F *hsubleadingJet_bRegNNResolution3 = new TH1F("hsubleadingJet_bRegNNResolution3","hsubleadingJet_bRegNNResolution3",80,0,0.4);
   hsubleadingJet_bRegNNResolution1->GetXaxis()->SetTitle("Subleading Jet bRegNNResolution");
   hsubleadingJet_bRegNNResolution1->GetYaxis()->SetTitle("Events");   
   hsubleadingJet_bRegNNResolution1->SetLineColor(kBlue);
   hsubleadingJet_bRegNNResolution1->SetLineWidth(1);
   hsubleadingJet_bRegNNResolution1->SetFillStyle(3005);
   hsubleadingJet_bRegNNResolution1->SetFillColor(kBlue);
   hsubleadingJet_bRegNNResolution2->SetLineColor(kGreen);
   hsubleadingJet_bRegNNResolution2->SetLineWidth(1);
   hsubleadingJet_bRegNNResolution2->SetFillStyle(3005);
   hsubleadingJet_bRegNNResolution2->SetFillColor(kGreen);
   hsubleadingJet_bRegNNResolution3->SetLineColor(kRed);
   hsubleadingJet_bRegNNResolution3->SetLineWidth(1);
   hsubleadingJet_bRegNNResolution3->SetFillStyle(3005);
   hsubleadingJet_bRegNNResolution3->SetFillColor(kRed);
   TLegend *lhsubleadingJet_bRegNNResolution = new TLegend(0.60,0.60,0.75,0.88);
   lhsubleadingJet_bRegNNResolution->AddEntry(hsubleadingJet_bRegNNResolution1,"Signal","f");
   lhsubleadingJet_bRegNNResolution->AddEntry(hsubleadingJet_bRegNNResolution2,"#gamma#gamma+Jets","f");
   lhsubleadingJet_bRegNNResolution->AddEntry(hsubleadingJet_bRegNNResolution3,"j#gamma+Jets","f");
   EventTree1->Draw("subleadingJet_bRegNNResolution >> hsubleadingJet_bRegNNResolution1","","norm");           //MC Signal      
   EventTree2->Draw("subleadingJet_bRegNNResolution >> hsubleadingJet_bRegNNResolution2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("subleadingJet_bRegNNResolution >> hsubleadingJet_bRegNNResolution3","","norm");           //GJets - 2 class bkg   
   hsubleadingJet_bRegNNResolution1->GetXaxis()->SetRangeUser(0.,0.4);
   hsubleadingJet_bRegNNResolution1->GetYaxis()->SetRangeUser(0.,0.042);
   hsubleadingJet_bRegNNResolution1->Draw("hist");
   hsubleadingJet_bRegNNResolution2->Draw("hist,same");
   hsubleadingJet_bRegNNResolution3->Draw("hist,same");
   lhsubleadingJet_bRegNNResolution->Draw();

   //==========================================================================
   //15
   c1->cd(15);
   TH1F *hsigmaMOverM1 = new TH1F("hsigmaMOverM1","hsigmaMOverM1",60,0,0.1);
   TH1F *hsigmaMOverM2 = new TH1F("hsigmaMOverM2","hsigmaMOverM2",60,0,0.1);
   TH1F *hsigmaMOverM3 = new TH1F("hsigmaMOverM3","hsigmaMOverM3",60,0,0.1);
   hsigmaMOverM1->GetXaxis()->SetTitle("#sigma_{M}/M");
   hsigmaMOverM1->GetYaxis()->SetTitle("Events");   
   hsigmaMOverM1->SetLineColor(kBlue);
   hsigmaMOverM1->SetLineWidth(1);
   hsigmaMOverM1->SetFillStyle(3005);
   hsigmaMOverM1->SetFillColor(kBlue);
   hsigmaMOverM2->SetLineColor(kGreen);
   hsigmaMOverM2->SetLineWidth(1);
   hsigmaMOverM2->SetFillStyle(3005);
   hsigmaMOverM2->SetFillColor(kGreen);
   hsigmaMOverM3->SetLineColor(kRed);
   hsigmaMOverM3->SetLineWidth(1);
   hsigmaMOverM3->SetFillStyle(3005);
   hsigmaMOverM3->SetFillColor(kRed);
   TLegend *lhsigmaMOverM = new TLegend(0.60,0.60,0.75,0.88);
   lhsigmaMOverM->AddEntry(hsigmaMOverM1,"Signal","f");
   lhsigmaMOverM->AddEntry(hsigmaMOverM2,"#gamma#gamma+Jets","f");
   lhsigmaMOverM->AddEntry(hsigmaMOverM3,"j#gamma+Jets","f");
   EventTree1->Draw("sigmaMOverM >> hsigmaMOverM1","","norm");           //MC Signal      
   EventTree2->Draw("sigmaMOverM >> hsigmaMOverM2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("sigmaMOverM >> hsigmaMOverM3","","norm");           //GJets - 2 class bkg   
   hsigmaMOverM1->GetXaxis()->SetRangeUser(0.,0.1);
   hsigmaMOverM1->GetYaxis()->SetRangeUser(0.,0.30);
   hsigmaMOverM1->Draw("hist");
   hsigmaMOverM2->Draw("hist,same");
   hsigmaMOverM3->Draw("hist,same");
   lhsigmaMOverM->Draw();

   //==========================================================================
   //16
   c1->cd(16);
   TH1F *hsigmaMJetsMjj1 = new TH1F("hsigmaMJetsMjj1","hsigmaMJetsMjj1",80,0,0.003);
   TH1F *hsigmaMJetsMjj2 = new TH1F("hsigmaMJetsMjj2","hsigmaMJetsMjj2",80,0,0.003);
   TH1F *hsigmaMJetsMjj3 = new TH1F("hsigmaMJetsMjj3","hsigmaMJetsMjj3",80,0,0.003);
   hsigmaMJetsMjj1->GetXaxis()->SetTitle("#sigma_{M_{jj}}/M_{jj}");
   hsigmaMJetsMjj1->GetYaxis()->SetTitle("Events");   
   hsigmaMJetsMjj1->SetLineColor(kBlue);
   hsigmaMJetsMjj1->SetLineWidth(1);
   hsigmaMJetsMjj1->SetFillStyle(3005);
   hsigmaMJetsMjj1->SetFillColor(kBlue);
   hsigmaMJetsMjj2->SetLineColor(kGreen);
   hsigmaMJetsMjj2->SetLineWidth(1);
   hsigmaMJetsMjj2->SetFillStyle(3005);
   hsigmaMJetsMjj2->SetFillColor(kGreen);
   hsigmaMJetsMjj3->SetLineColor(kRed);
   hsigmaMJetsMjj3->SetLineWidth(1);
   hsigmaMJetsMjj3->SetFillStyle(3005);
   hsigmaMJetsMjj3->SetFillColor(kRed);
   TLegend *lhsigmaMJetsMjj = new TLegend(0.60,0.60,0.75,0.88);
   lhsigmaMJetsMjj->AddEntry(hsigmaMJetsMjj1,"Signal","f");
   lhsigmaMJetsMjj->AddEntry(hsigmaMJetsMjj2,"#gamma#gamma+Jets","f");
   lhsigmaMJetsMjj->AddEntry(hsigmaMJetsMjj3,"j#gamma+Jets","f");
   EventTree1->Draw("sigmaMJets/Mjj >> hsigmaMJetsMjj1","","norm");           //MC Signal      
   EventTree2->Draw("sigmaMJets/Mjj >> hsigmaMJetsMjj2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("sigmaMJets/Mjj >> hsigmaMJetsMjj3","","norm");           //GJets - 2 class bkg   
   hsigmaMJetsMjj1->GetXaxis()->SetRangeUser(0.,0.003);
   hsigmaMJetsMjj1->GetYaxis()->SetRangeUser(0.,0.065);
   hsigmaMJetsMjj1->Draw("hist");
   hsigmaMJetsMjj2->Draw("hist,same");
   hsigmaMJetsMjj3->Draw("hist,same");
   lhsigmaMJetsMjj->Draw();
*/
/*   //==========================================================================
   //17
   c1->cd(1);
   TH1F *hleadingPhoton_ptCMS_hgg_mass1 = new TH1F("hleadingPhoton_ptCMS_hgg_mass1","hleadingPhoton_ptCMS_hgg_mass1",80,0,5.);
   TH1F *hleadingPhoton_ptCMS_hgg_mass2 = new TH1F("hleadingPhoton_ptCMS_hgg_mass2","hleadingPhoton_ptCMS_hgg_mass2",80,0,5.);
   TH1F *hleadingPhoton_ptCMS_hgg_mass3 = new TH1F("hleadingPhoton_ptCMS_hgg_mass3","hleadingPhoton_ptCMS_hgg_mass3",80,0,5.);
   hleadingPhoton_ptCMS_hgg_mass1->GetXaxis()->SetTitle("p_{T(#gamma1)}/M(#gamma#gamma)");
   hleadingPhoton_ptCMS_hgg_mass1->GetYaxis()->SetTitle("Events");   
   hleadingPhoton_ptCMS_hgg_mass1->SetLineColor(kBlue);
   hleadingPhoton_ptCMS_hgg_mass1->SetLineWidth(1);
   hleadingPhoton_ptCMS_hgg_mass1->SetFillStyle(3005);
   hleadingPhoton_ptCMS_hgg_mass1->SetFillColor(kBlue);
   hleadingPhoton_ptCMS_hgg_mass2->SetLineColor(kGreen);
   hleadingPhoton_ptCMS_hgg_mass2->SetLineWidth(1);
   hleadingPhoton_ptCMS_hgg_mass2->SetFillStyle(3005);
   hleadingPhoton_ptCMS_hgg_mass2->SetFillColor(kGreen);
   hleadingPhoton_ptCMS_hgg_mass3->SetLineColor(kRed);
   hleadingPhoton_ptCMS_hgg_mass3->SetLineWidth(1);
   hleadingPhoton_ptCMS_hgg_mass3->SetFillStyle(3005);
   hleadingPhoton_ptCMS_hgg_mass3->SetFillColor(kRed);
   TLegend *lhleadingPhoton_ptCMS_hgg_mass = new TLegend(0.60,0.60,0.75,0.88);
   lhleadingPhoton_ptCMS_hgg_mass->AddEntry(hleadingPhoton_ptCMS_hgg_mass1,"Signal","f");
   lhleadingPhoton_ptCMS_hgg_mass->AddEntry(hleadingPhoton_ptCMS_hgg_mass2,"#gamma#gamma+Jets","f");
   lhleadingPhoton_ptCMS_hgg_mass->AddEntry(hleadingPhoton_ptCMS_hgg_mass3,"j#gamma+Jets","f");
   EventTree1->Draw("leadingPhoton_pt/CMS_hgg_mass >> hleadingPhoton_ptCMS_hgg_mass1","","norm");           //MC Signal      
   EventTree2->Draw("leadingPhoton_pt/CMS_hgg_mass >> hleadingPhoton_ptCMS_hgg_mass2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("leadingPhoton_pt/CMS_hgg_mass >> hleadingPhoton_ptCMS_hgg_mass3","","norm");           //GJets - 2 class bkg   
   hleadingPhoton_ptCMS_hgg_mass1->GetXaxis()->SetRangeUser(0.,6.0);
   hleadingPhoton_ptCMS_hgg_mass1->GetYaxis()->SetRangeUser(0.,0.20);
   hleadingPhoton_ptCMS_hgg_mass1->Draw("hist");
   hleadingPhoton_ptCMS_hgg_mass2->Draw("hist,same");
   hleadingPhoton_ptCMS_hgg_mass3->Draw("hist,same");
   lhleadingPhoton_ptCMS_hgg_mass->Draw();

   //==========================================================================
   //18
   c1->cd(2);
   TH1F *hsubleadingPhoton_ptCMS_hgg_mass1 = new TH1F("hsubleadingPhoton_ptCMS_hgg_mass1","hsubleadingPhoton_ptCMS_hgg_mass1",80,0,5.);
   TH1F *hsubleadingPhoton_ptCMS_hgg_mass2 = new TH1F("hsubleadingPhoton_ptCMS_hgg_mass2","hsubleadingPhoton_ptCMS_hgg_mass2",80,0,5.);
   TH1F *hsubleadingPhoton_ptCMS_hgg_mass3 = new TH1F("hsubleadingPhoton_ptCMS_hgg_mass3","hsubleadingPhoton_ptCMS_hgg_mass3",80,0,5.);
   hsubleadingPhoton_ptCMS_hgg_mass1->GetXaxis()->SetTitle("p_{T(#gamma2)}/M(#gamma#gamma)");
   hsubleadingPhoton_ptCMS_hgg_mass1->GetYaxis()->SetTitle("Events");   
   hsubleadingPhoton_ptCMS_hgg_mass1->SetLineColor(kBlue);
   hsubleadingPhoton_ptCMS_hgg_mass1->SetLineWidth(1);
   hsubleadingPhoton_ptCMS_hgg_mass1->SetFillStyle(3005);
   hsubleadingPhoton_ptCMS_hgg_mass1->SetFillColor(kBlue);
   hsubleadingPhoton_ptCMS_hgg_mass2->SetLineColor(kGreen);
   hsubleadingPhoton_ptCMS_hgg_mass2->SetLineWidth(1);
   hsubleadingPhoton_ptCMS_hgg_mass2->SetFillStyle(3005);
   hsubleadingPhoton_ptCMS_hgg_mass2->SetFillColor(kGreen);
   hsubleadingPhoton_ptCMS_hgg_mass3->SetLineColor(kRed);
   hsubleadingPhoton_ptCMS_hgg_mass3->SetLineWidth(1);
   hsubleadingPhoton_ptCMS_hgg_mass3->SetFillStyle(3005);
   hsubleadingPhoton_ptCMS_hgg_mass3->SetFillColor(kRed);
   TLegend *lhsubleadingPhoton_ptCMS_hgg_mass = new TLegend(0.60,0.60,0.75,0.88);
   lhsubleadingPhoton_ptCMS_hgg_mass->AddEntry(hsubleadingPhoton_ptCMS_hgg_mass1,"Signal","f");
   lhsubleadingPhoton_ptCMS_hgg_mass->AddEntry(hsubleadingPhoton_ptCMS_hgg_mass2,"#gamma#gamma+Jets","f");
   lhsubleadingPhoton_ptCMS_hgg_mass->AddEntry(hsubleadingPhoton_ptCMS_hgg_mass3,"j#gamma+Jets","f");
   EventTree1->Draw("subleadingPhoton_pt/CMS_hgg_mass >> hsubleadingPhoton_ptCMS_hgg_mass1","","norm");           //MC Signal      
   EventTree2->Draw("subleadingPhoton_pt/CMS_hgg_mass >> hsubleadingPhoton_ptCMS_hgg_mass2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("subleadingPhoton_pt/CMS_hgg_mass >> hsubleadingPhoton_ptCMS_hgg_mass3","","norm");           //GJets - 2 class bkg   
   hsubleadingPhoton_ptCMS_hgg_mass1->GetXaxis()->SetRangeUser(0.,3.0);
   hsubleadingPhoton_ptCMS_hgg_mass1->GetYaxis()->SetRangeUser(0.,0.40);
   hsubleadingPhoton_ptCMS_hgg_mass1->Draw("hist");
   hsubleadingPhoton_ptCMS_hgg_mass2->Draw("hist,same");
   hsubleadingPhoton_ptCMS_hgg_mass3->Draw("hist,same");
   lhsubleadingPhoton_ptCMS_hgg_mass->Draw();
*/
   //==========================================================================
   //19
   c1->cd(1);
   TH1F *hleadingJet_ptMjj1 = new TH1F("hleadingJet_ptMjj1","hleadingJet_ptMjj1",80,0,5.);
   TH1F *hleadingJet_ptMjj2 = new TH1F("hleadingJet_ptMjj2","hleadingJet_ptMjj2",80,0,5.);
   TH1F *hleadingJet_ptMjj3 = new TH1F("hleadingJet_ptMjj3","hleadingJet_ptMjj3",80,0,5.);
   hleadingJet_ptMjj1->GetXaxis()->SetTitle("p_{T(j1)}/M(jj)");
   hleadingJet_ptMjj1->GetYaxis()->SetTitle("Events");   
   hleadingJet_ptMjj1->SetLineColor(kBlue);
   hleadingJet_ptMjj1->SetLineWidth(1);
   hleadingJet_ptMjj1->SetFillStyle(3005);
   hleadingJet_ptMjj1->SetFillColor(kBlue);
   hleadingJet_ptMjj2->SetLineColor(kGreen);
   hleadingJet_ptMjj2->SetLineWidth(1);
   hleadingJet_ptMjj2->SetFillStyle(3005);
   hleadingJet_ptMjj2->SetFillColor(kGreen);
   hleadingJet_ptMjj3->SetLineColor(kRed);
   hleadingJet_ptMjj3->SetLineWidth(1);
   hleadingJet_ptMjj3->SetFillStyle(3005);
   hleadingJet_ptMjj3->SetFillColor(kRed);
   TLegend *lhleadingJet_ptMjj = new TLegend(0.60,0.60,0.75,0.88);
   lhleadingJet_ptMjj->AddEntry(hleadingJet_ptMjj1,"Signal","f");
   lhleadingJet_ptMjj->AddEntry(hleadingJet_ptMjj2,"#gamma#gamma+Jets","f");
   lhleadingJet_ptMjj->AddEntry(hleadingJet_ptMjj3,"j#gamma+Jets","f");
   EventTree1->Draw("leadingJet_pt/Mjj >> hleadingJet_ptMjj1","","norm");           //MC Signal      
   EventTree2->Draw("leadingJet_pt/Mjj >> hleadingJet_ptMjj2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("leadingJet_pt/Mjj >> hleadingJet_ptMjj3","","norm");           //GJets - 2 class bkg   
   hleadingJet_ptMjj1->GetXaxis()->SetRangeUser(0.,5.0);
   hleadingJet_ptMjj1->GetYaxis()->SetRangeUser(0.,0.15);
   hleadingJet_ptMjj1->Draw("hist");
   hleadingJet_ptMjj2->Draw("hist,same");
   hleadingJet_ptMjj3->Draw("hist,same");
   lhleadingJet_ptMjj->Draw();

   //==========================================================================
   //20
   c1->cd(2);
   TH1F *hsubleadingJet_ptMjj1 = new TH1F("hsubleadingJet_ptMjj1","hsubleadingJet_ptMjj1",80,0,5.);
   TH1F *hsubleadingJet_ptMjj2 = new TH1F("hsubleadingJet_ptMjj2","hsubleadingJet_ptMjj2",80,0,5.);
   TH1F *hsubleadingJet_ptMjj3 = new TH1F("hsubleadingJet_ptMjj3","hsubleadingJet_ptMjj3",80,0,5.);
   hsubleadingJet_ptMjj1->GetXaxis()->SetTitle("p_{T(j2)}/M(jj)");
   hsubleadingJet_ptMjj1->GetYaxis()->SetTitle("Events");   
   hsubleadingJet_ptMjj1->SetLineColor(kBlue);
   hsubleadingJet_ptMjj1->SetLineWidth(1);
   hsubleadingJet_ptMjj1->SetFillStyle(3005);
   hsubleadingJet_ptMjj1->SetFillColor(kBlue);
   hsubleadingJet_ptMjj2->SetLineColor(kGreen);
   hsubleadingJet_ptMjj2->SetLineWidth(1);
   hsubleadingJet_ptMjj2->SetFillStyle(3005);
   hsubleadingJet_ptMjj2->SetFillColor(kGreen);
   hsubleadingJet_ptMjj3->SetLineColor(kRed);
   hsubleadingJet_ptMjj3->SetLineWidth(1);
   hsubleadingJet_ptMjj3->SetFillStyle(3005);
   hsubleadingJet_ptMjj3->SetFillColor(kRed);
   TLegend *lhsubleadingJet_ptMjj = new TLegend(0.60,0.60,0.75,0.88);
   lhsubleadingJet_ptMjj->AddEntry(hsubleadingJet_ptMjj1,"Signal","f");
   lhsubleadingJet_ptMjj->AddEntry(hsubleadingJet_ptMjj2,"#gamma#gamma+Jets","f");
   lhsubleadingJet_ptMjj->AddEntry(hsubleadingJet_ptMjj3,"j#gamma+Jets","f");
   EventTree1->Draw("subleadingJet_pt/Mjj >> hsubleadingJet_ptMjj1","","norm");           //MC Signal      
   EventTree2->Draw("subleadingJet_pt/Mjj >> hsubleadingJet_ptMjj2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("subleadingJet_pt/Mjj >> hsubleadingJet_ptMjj3","","norm");           //GJets - 2 class bkg   
   hsubleadingJet_ptMjj1->GetXaxis()->SetRangeUser(0.,2.0);
   hsubleadingJet_ptMjj1->GetYaxis()->SetRangeUser(0.,0.33);
   hsubleadingJet_ptMjj1->Draw("hist");
   hsubleadingJet_ptMjj2->Draw("hist,same");
   hsubleadingJet_ptMjj3->Draw("hist,same");
   lhsubleadingJet_ptMjj->Draw();


   //==========================================================================
   //21
   c1->cd(3);
   TH1F *hPhoJetotherDr1 = new TH1F("hPhoJetotherDr1","hPhoJetotherDr1",80,0,6.);
   TH1F *hPhoJetotherDr2 = new TH1F("hPhoJetotherDr2","hPhoJetotherDr2",80,0,6.);
   TH1F *hPhoJetotherDr3 = new TH1F("hPhoJetotherDr3","hPhoJetotherDr3",80,0,6.);
   hPhoJetotherDr1->GetXaxis()->SetTitle("PhoJetotherDr");
   hPhoJetotherDr1->GetYaxis()->SetTitle("Events");   
   hPhoJetotherDr1->SetLineColor(kBlue);
   hPhoJetotherDr1->SetLineWidth(1);
   hPhoJetotherDr1->SetFillStyle(3005);
   hPhoJetotherDr1->SetFillColor(kBlue);
   hPhoJetotherDr2->SetLineColor(kGreen);
   hPhoJetotherDr2->SetLineWidth(1);
   hPhoJetotherDr2->SetFillStyle(3005);
   hPhoJetotherDr2->SetFillColor(kGreen);
   hPhoJetotherDr3->SetLineColor(kRed);
   hPhoJetotherDr3->SetLineWidth(1);
   hPhoJetotherDr3->SetFillStyle(3005);
   hPhoJetotherDr3->SetFillColor(kRed);
   TLegend *lhPhoJetotherDr = new TLegend(0.60,0.60,0.75,0.88);
   lhPhoJetotherDr->AddEntry(hPhoJetotherDr1,"Signal","f");
   lhPhoJetotherDr->AddEntry(hPhoJetotherDr2,"#gamma#gamma+Jets","f");
   lhPhoJetotherDr->AddEntry(hPhoJetotherDr3,"j#gamma+Jets","f");
   EventTree1->Draw("PhoJetotherDr >> hPhoJetotherDr1","","norm");           //MC Signal      
   EventTree2->Draw("PhoJetotherDr >> hPhoJetotherDr2","","norm");           //DiPhoton - 1 class bkg  
   EventTree3->Draw("PhoJetotherDr >> hPhoJetotherDr3","","norm");           //GJets - 2 class bkg   
   hPhoJetotherDr1->GetXaxis()->SetRangeUser(0.,6.0);
   hPhoJetotherDr1->GetYaxis()->SetRangeUser(0.,0.06);
   hPhoJetotherDr1->Draw("hist");
   hPhoJetotherDr2->Draw("hist,same");
   hPhoJetotherDr3->Draw("hist,same");
   lhPhoJetotherDr->Draw();

   c1->cd();
}
