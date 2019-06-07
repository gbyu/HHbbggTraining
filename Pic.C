#include "TFile.h"
#include "TDirectory.h"
#include "TTree.h"
#include "TChain.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TF1.h"
#include "TString.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TLine.h"

#include <iostream>

void Pic(){
   gROOT->SetStyle("Plain");
   gStyle->SetOptStat(0);
   
//   TFile *file = new TFile("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2017/DoubleEG.root");   
//   TDirectory *dir =  file->GetDirectory("tagsDumper/trees");
//   TTree* tr = (TTree*) dir->Get("Data_13TeV_DoubleHTag_0");
   TChain* tr = new TChain("tr","tr");
/*   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/reducedTree_2016/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg");             //BG
   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/reducedTree_2017/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg");             //BG
*/
//st
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg_0");             //BG1
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg");             //BG2

//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptMjj_dR_reducedTree_2017_MCbkg/Total_res_st_ptMjj_dR_transformedMVA.root/reducedTree_bkg");             //Data
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptmgg_reducedTree_2017_MCbkg/Total_res_st_ptmgg_transformedMVA.root/reducedTree_bkg");             //Data
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2017_MCbkg/Total_res_st_transformedMVA.root/reducedTree_bkg");             //Data
 
   //tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables/new_DoubleEG_2017.root/bbggSelectionTree");             //Data
   //tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables_add_ptmgg/new_DoubleEG_2017.root/bbggSelectionTree");             //Data
   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables_add_ptmgg_ptmjj_dR/new_DoubleEG_2017.root/bbggSelectionTree");             //Data



//st with add ptmgg
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptmgg_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg_0");             //BG1
//   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptmgg_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg");             //BG2
//st with add ptmjj, dR
/*   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptMjj_dR_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg_0");             //BG1
   tr->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptMjj_dR_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_bkg");             //BG2
*/
//   tr->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2017/DoubleEG.root/tagsDumper/trees/Data_13TeV_DoubleHTag_0");
//   tr->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2016/DoubleEG.root/tagsDumper/trees/Data_13TeV_DoubleHTag_0");
   
//   TFile *filemc = new TFile("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2017/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root");   
//   TDirectory *dirmc =  filemc->GetDirectory("tagsDumper/trees");
//   TTree* trmc = (TTree*) dirmc->Get("GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");

   TChain* trmc = new TChain("trmc","trmc");
/*   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/reducedTree_2016/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/reducedTree_2017/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
*/
/*   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2016/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2017/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
*/

//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptMjj_dR_reducedTree_2017_MCbkg/Total_res_st_ptMjj_dR_transformedMVA.root/reducedTree_sig");                                                                             //Signal
//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptmgg_reducedTree_2017_MCbkg/Total_res_st_ptmgg_transformedMVA.root/reducedTree_sig");                                                                             //Signal
   //trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_reducedTree_2017_MCbkg/Total_res_st_transformedMVA.root/reducedTree_sig");                                                                             //Signal
   
//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables/new_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root/bbggSelectionTree");             //Data
//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables_add_ptmgg/new_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root/bbggSelectionTree");             //Data
   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/new_flattrees2017/st_variables_add_ptmgg_ptmjj_dR/new_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root/bbggSelectionTree");             //Data


//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptmgg_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
//   trmc->Add("/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/output_files/st_ptMjj_dR_reducedTree_2017_MCbkg/Total_preselection_diffNaming_transformedMVA.root/reducedTree_sig");                                                                             //Signal
//   trmc->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2017/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root/tagsDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");
//   trmc->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2016/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root/tagsDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_DoubleHTag_0");
   
//   trmc->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2017/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_withGenInfo.root/genDiphotonDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_NoTag_0");
//   trmc->Add("/afs/cern.ch/work/l/lata/public/HH_bbyy/ForLeonid/2016/output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph_withGenInfo.root/genDiphotonDumper/trees/GluGluToHHTo2B2G_node_SM_13TeV_madgraph_13TeV_NoTag_0");
   
   double MXcuts[5] = {250,354,478,560,35000};
   double MVAcuts[4] = {0.29,0.441,0.724,1.0};   
   double MXmin, MXmax;
   TH2D *h1[12],*h2[12];
   TCanvas *cc1[12],*cc2[4];

   TLine * ln1 = new TLine(0.25,1./3.,1.,1./3.);
   TLine * ln2 = new TLine(0.25,1./3.,0.25,1.5);
   ln1->SetLineColor(kRed);
   ln2->SetLineColor(kRed);
   ln1->SetLineWidth(4);
   ln2->SetLineWidth(4);

   double xx1[3]={0.16,0.25,0.38};
   double yy1[3]={1.,0.6,0.36};
//   double xx2[3]={0.14,0.3,0.42};
//   double yy2[3]={1.4,0.7,0.4};

   double pars[3];

   pars[2] = ( xx1[0]*(yy1[2]-yy1[1]) + xx1[1]*(yy1[0]-yy1[2])+xx1[2]*(yy1[1]-yy1[0]) )/( (xx1[0]-xx1[1])*(xx1[0]-xx1[2])*(xx1[1]-xx1[2]) );
   pars[1] = (yy1[1]-yy1[0])/(xx1[1]-xx1[0]) - pars[2]*(xx1[0]+xx1[1]);
   pars[0] = yy1[0] - pars[2]*xx1[0]*xx1[0] - pars[1]*xx1[0];
   
   TF1* fun1 = new TF1("fun1","[0]+x*[1]+x*x*[2]",xx1[0],xx1[2]);
   fun1->SetParameters(pars);
   fun1->SetLineColor(kOrange+7);
   fun1->SetLineWidth(4);
   cout<<fun1->Eval(xx1[1])<<endl;
   TLine * ln3 = new TLine(xx1[2],yy1[2],1,1.+yy1[2]-xx1[2]);
   ln3->SetLineColor(kOrange+7);
   ln3->SetLineWidth(4);
   TLine * ln4 = new TLine(xx1[0],yy1[0],xx1[0],1.5);
   ln4->SetLineColor(kOrange+7);
   ln4->SetLineWidth(4);

//   TF1* fun2 = new TF1("fun2","[0]+x*[1]+x*x*[1]",xx2[0],xx2[2]);

   double Nsig_old[12],Nsig_new[12],Nbkg_old[12],Nbkg_new[12];
   
//   for(int i =0;i<4;i++){
   for(int i =0;i<1;i++){
      for(int j =0;j<3;j++){	   
	 MXmin = MXcuts[i]; MXmax = MXcuts[i+1];
	 
	 h1[3*i+j] = new TH2D(Form("h1_%d",3*i+j),Form("Data, %5.0f <= MX < %5.0f and %5.3f < MVA <= %5.3f;"
						       "p_{T}^{#gamma 2}/m_{#gamma #gamma};p_{T}^{#gamma 1}/m_{#gamma #gamma}"
						       ,MXmin,MXmax,MVAcuts[j],MVAcuts[j+1]),100,0.1,1,100,0.1,1.5);
//	 h1[3*i+j] = new TH2D(Form("h1_%d",3*i+j),Form("Background MC, %5.0f <= MX < %5.0f and %5.3f < MVA <= %5.3f;"
//						       "p_{T}^{#gamma 2}/m_{#gamma #gamma};p_{T}^{#gamma 1}/m_{#gamma #gamma}"
//						       ,MXmin,MXmax,MVAcuts[j],MVAcuts[j+1]),100,0.1,1,100,0.1,1.5);
	 h2[3*i+j] = new TH2D(Form("h2_%d",3*i+j),Form("Signal MC, %5.0f <= MX < %5.0f and %5.3f < MVA <= %5.3f;"
						       "p_{T}^{#gamma 2}/m_{#gamma #gamma};p_{T}^{#gamma 1}/m_{#gamma #gamma}",
						       MXmin,MXmax,MVAcuts[j],MVAcuts[j+1]),100,0.1,1,100,0.1,1.5);
/*
	 h1[3*i+j] = new TH2D(Form("h1_%d",3*i+j),Form("Data, %5.3f < MVA <= %5.3f;"
						       "p_{T}^{#gamma 2}/m_{#gamma #gamma};p_{T}^{#gamma 1}/m_{#gamma #gamma}"
						       ,MVAcuts[j],MVAcuts[j+1]),100,0.1,1,100,0.1,1.5);
	 h2[3*i+j] = new TH2D(Form("h2_%d",3*i+j),Form("Signal MC,  %5.3f < MVA <= %5.3f;"
						       "p_{T}^{#gamma 2}/m_{#gamma #gamma};p_{T}^{#gamma 1}/m_{#gamma #gamma}",
						       MVAcuts[j],MVAcuts[j+1]),100,0.1,1,100,0.1,1.5);
*/	 
	 cc1[3*i+j] = new TCanvas(Form("cc1_%d",3*i+j),Form("cc_%d",3*i+j),1500,900);
	 cc1[3*i+j]->Divide(2,1);
	 cc1[3*i+j]->cd(1); gPad->SetRightMargin(0.13);
//	 tr->Draw(Form("leadingPhoton_pt/CMS_hgg_mass: subleadingPhoton_pt/CMS_hgg_mass >> h1_%d",3*i+j),
//		  Form("MX < %f && MX>= %f && HHbbggMVA > %f && HHbbggMVA <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");   
//	 tr->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h1_%d",3*i+j),
//		  Form("MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MVAcuts[j],MVAcuts[j+1]),"colz");   
//	 tr->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h1_%d",3*i+j),
//		  Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");   
//	 tr->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h1_%d",3*i+j),
//		  Form("weight2*(MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f)",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");   
	 tr->Draw(Form("leadingPhoton_pt/CMS_hgg_mass: subleadingPhoton_pt/CMS_hgg_mass >> h1_%d",3*i+j),
		  Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");   
	 ln1->Draw();
	 ln2->Draw();
//	 ln3->Draw();
//	 ln4->Draw();
//	 fun1->Draw("same");
      
	 cc1[3*i+j]->cd(2); gPad->SetRightMargin(0.13);
//	 trmc->Draw(Form("leadingPhoton_pt/CMS_hgg_mass: subleadingPhoton_pt/CMS_hgg_mass >> h2_%d",3*i+j),
//		    Form("MX < %f && MX>= %f && HHbbggMVA > %f && HHbbggMVA <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");
//	 trmc->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h2_%d",3*i+j),
//		    Form("MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MVAcuts[j],MVAcuts[j+1]),"colz");
//	 trmc->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h2_%d",3*i+j),
//		    Form("(MX < %f && MX>= %f) && MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");
//	 trmc->Draw(Form("leadingPhotonptOverCMShggmass: subleadingPhotonptOverCMShggmass >> h2_%d",3*i+j),
//		    Form("weight2*(MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f)",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");
	 trmc->Draw(Form("leadingPhoton_pt/CMS_hgg_mass: subleadingPhoton_pt/CMS_hgg_mass >> h2_%d",3*i+j),
		    Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1]),"colz");
	 ln1->Draw();
	 ln2->Draw();
//	 ln3->Draw();
//	       ln4->Draw();
//	 fun1->Draw("same");
//	 cc1[3*i+j]->SaveAs(Form("/eos/user/l/lkardapo/www/tmp/2/WithMVAcut_pt1_vs_pt2_%d_%d.png",i,j));
	 cc1[3*i+j]->SaveAs(Form("pic_plots/WithMVAcut_pt1_vs_pt2_%d_%d.png",i,j));
         
         /*
	 cout<<"Sig_new"<<i<<"_"<<j<<" = "
	   <<( Nsig_new[3*i+j] = trmc->GetEntries(Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f && (leadingPhotonptOverCMShggmass >"
						   " (%f + %f*subleadingPhotonptOverCMShggmass + %f*(subleadingPhotonptOverCMShggmass)*(subleadingPhotonptOverCMShggmass)) "
						   "|| (subleadingPhotonptOverCMShggmass > 0.38) ) && subleadingPhotonptOverCMShggmass > 0.16"
						   ,MXmax,MXmin,MVAcuts[j],MVAcuts[j+1],pars[0],pars[1],pars[2])) ) << endl;
	 cout<<"Bkg_new"<<"_"<<j<<i<<" = "
	   <<( Nbkg_new[3*i+j] = tr->GetEntries(Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f && (leadingPhotonptOverCMShggmass >"
						 " (%f + %f*subleadingPhotonptOverCMShggmass + %f*(subleadingPhotonptOverCMShggmass)*(subleadingPhotonptOverCMShggmass)) "
						 "|| (subleadingPhotonptOverCMShggmass > 0.38)) && subleadingPhotonptOverCMShggmass > 0.16"
						 ,MXmax,MXmin,MVAcuts[j],MVAcuts[j+1],pars[0],pars[1],pars[2])) ) << endl;      
	 
	 cout<<"Sig_old"<<"_"<<j<<i<<" = "
	   <<( Nsig_old[3*i+j] = trmc->GetEntries(Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f && leadingPhotonptOverCMShggmass > 1./3."
						   " && subleadingPhotonptOverCMShggmass > 0.25",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1])) ) << endl;
	 
	 cout<<"Bkg_old"<<"_"<<j<<i<<" = "
	   <<( Nbkg_old[3*i+j] = tr->GetEntries(Form("MX < %f && MX>= %f && MVAOutputTransformed > %f && MVAOutputTransformed <= %f && leadingPhotonptOverCMShggmass > 1./3."
						 " && subleadingPhotonptOverCMShggmass > 0.25",MXmax,MXmin,MVAcuts[j],MVAcuts[j+1])) ) << endl;
	 */
	 
      }
      
   }
/*
   for(int j=0; j<3; j++){
      cout<<" j = "<<j<<endl;
      for(int i=0; i<4; i++) {	   
	printf("%5.0f > MX > %5.0f  S_new/S_old = %5.2f  B_new/B_old = %5.2f \n",MXcuts[i+1],MXcuts[i],Nsig_new[3*i+j]/Nsig_old[3*i+j],Nbkg_new[3*i+j]/Nbkg_old[3*i+j]);
      }
      
   }
*/
   
}
