from ROOT import *

gStyle.SetOptStat(0)
gStyle.SetOptTitle(0);
#c1 = TCanvas('c1','c1')
#pad1 = TPad('pad1','This is pad1',0.02,0.52,0.48,0.98,21)
#pad1.Draw()
#pad1.cd()
#pad1.SetGrid()
#pad1.SetLogy()

path1="/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/2017/flattrees_st_cuts/"
path2="/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/"
path3="/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/"

#_file0 = TFile.Open(path+"DoubleEG_preselection.root");
#_file1 = TFile.Open(path+"GJet_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_preselection.root");
#_file2 = TFile.Open(path+"DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_preselection.root");

_file0 = TFile.Open(path1+"DoubleEG_2017_st_cuts.root");
#_file1 = TFile.Open(path1+"output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root");
_file2 = TFile.Open(path1+"output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts.root");
#_file2 = TFile.Open(path1+"output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts_reweight_Mjj.root");
#_file1 = TFile.Open(path2+"GJet_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_preselection.root");
#_file2 = TFile.Open(path2+"DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_st_cuts_preselection.root");
bkg_1_tree = TChain("bbggSelectionTree")
#bkg_1_tree.Add(path1+"output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root")
#bkg_1_tree.Add(path1+"output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts.root")
#bkg_1_tree.Add(path1+"output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_reweight.root")
#bkg_1_tree.Add(path1+"output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_reweight.root")
bkg_1_tree.Add(path3+"output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_reweight.root")
bkg_1_tree.Add(path3+"output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8_st_cuts_reweight.root")

#data_tree =  _file0.Get("reducedTree");
#bkg_1_tree =  _file1.Get("reducedTree");
#bkg_2_tree =  _file2.Get("reducedTree");

data_tree =  _file0.Get("bbggSelectionTree");
#bkg_1_tree =  _file1.Get("bbggSelectionTree");
bkg_2_tree =  _file2.Get("bbggSelectionTree");
#bkg_1_tree =  _file1.Get("reducedTree");
#bkg_2_tree =  _file2.Get("reducedTree");

#data_tree.Print()
#print event.branchName

#Cut = "weight*(customSubLeadingPhotonIDMVA>-0.9 && customSubLeadingPhotonIDMVA<0 )"
#Cut = "weight*(customSubLeadingPhotonIDMVA<0 || customSubLeadingPhotonIDMVA>0)"
#Cut = "weight*(customSubLeadingPhotonIDMVA>-0.9 && customSubLeadingPhotonIDMVA<1)"
Cut = "weight"
#Cut2 = "weight2"
Cut2 = "weight"
#Cut = "(customSubLeadingPhotonIDMVA>-0.9 && customSubLeadingPhotonIDMVA<1)"
cut = TCut(Cut)
cut2 = TCut(Cut2)
#data_tree.Draw("customSubLeadingPhotonIDMVA>>h_data(100,-1,1)");
#bkg_1_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_1(100,-1,1)");
#bkg_2_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_2(100,-1,1)");
data_tree.Draw("customSubLeadingPhotonIDMVA>>h_data(100,-1,1)");
#bkg_1_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_1(100,-1,1)");
bkg_1_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_1(100,-1,1)",cut);
#bkg_2_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_2(100,-1,1)",cut);
bkg_2_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_2(100,-1,1)",cut2);
#bkg_2_tree.Draw("customSubLeadingPhotonIDMVA>>h_bkg_2(100,-1,1)");

h_data.SetMarkerStyle(20)
h_data.GetXaxis().SetTitle("customSubLeadingPhotonIDMVA")
h_data.SetMarkerSize(0.8)
h_data.SetMarkerColor(1)
h_data.SetLineColor(1)
h_data.SetLineWidth(2)


h_bkg_1.SetFillColor(kRed);
h_bkg_1.SetLineColor(kRed);

h_bkg_2.SetFillColor(kBlue);
h_bkg_2.SetLineColor(kBlue);

#h_bkg_1.Scale(154.470414989*5)
h_bkg_1.Scale(154.470414989*0.341669929917*3*0.377953917933)
h_bkg_2.Scale(154.470414989*0.341669929917*0.377953917933)
#h_bkg_1.Scale(154.470414989)
#h_bkg_2.Scale(154.470414989)

hs = THStack("hs","");
hs.Add(h_bkg_1);
hs.Add(h_bkg_2);

gJetInt=h_bkg_1.Integral()
diphoInt=h_bkg_2.Integral()
dataInt=h_data.Integral()

print "gJet integral: "+str(gJetInt)
print "diphoton integral: "+str(diphoInt)
print "data integral: "+str(dataInt)

print "ratio data/MC: "+str(dataInt/(gJetInt+diphoInt)) 

legend = TLegend(0.6,0.7,0.9,0.9);
textFont = 43
textSize = 16
legend.SetFillStyle(0)
legend.SetLineWidth(0)
legend.SetBorderSize(0)
legend.SetTextFont(textFont)
legend.SetTextSize(textSize)
legend.AddEntry(h_bkg_1,"j#gamma+jets","f")
legend.AddEntry(h_bkg_2,"#gamma#gamma+jets","f")
legend.AddEntry(h_data,"Data","ep")


#h_bkg_1.Print();
h_data.GetYaxis().SetRangeUser(0.0,250000)
  
h_data.Draw("p");
hs.Draw("samehist");
h_data.Draw("epsame");
gPad.RedrawAxis();
legend.Draw("same")
c1.Update()

#c1.SaveAs("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/dataMC.pdf")
c1.SaveAs("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/dataMC.root")
c1.SaveAs("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/dataMC.png")

#scale factor to match data
#h_bkg_1.Scale(0.111939862956)
#h_bkg_2.Scale(0.111939862956)

#hs.Fit("expo")
#f1 = TF1("f1","expo")
#f1.SetLineColor(kBlack)
#h_data.Fit(f1)
#h_bkg_1.Add(h_bkg_2)
#f2 = TF1("f2","expo")
#f2.SetLineColor(kRed)
#h_bkg_1.Fit(f2)

#h_data.Draw("p");
#h_bkg_1.Draw("samehist")
#h_bkg_1.Draw("sameep")

#f2.Draw("same")
#h_data.Draw("epsame");

#c1.SaveAs("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/dataMC_Mgg_MVA_rescaled_fit.root")
#c1.SaveAs("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/dataMC_Mgg_MVA_rescaled_fit.png")



