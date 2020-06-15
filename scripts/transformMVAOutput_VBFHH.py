import sys, types, os
from optparse import OptionParser, make_option
from  pprint import pprint
from array import array

# -----------------------------------------------------------------------------------------------------------
def main(options,args):

    ## setTDRStyle()
    ROOT.gStyle.SetOptStat(0)
    
    #indir='/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/2018/'    
    indirSig=options.indirSig    
    indir=options.indir    
    ##fin = ROOT.TFile.Open(options.file)
    fin = ROOT.TFile.Open(indirSig+"output_VBFHHTo2B2G_CV_1_C2V_1_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root")
    tree = fin.Get("bbggSelectionTree")
    fin2 = ROOT.TFile.Open(indirSig+"output_VBFHHTo2B2G_C2V01.root ")
    tree2 = fin2.Get("reducedTree_sig")

    for nameTagPos,s in enumerate(options.file.split("/")):
        print nameTagPos, s
        if "outfil" in s:
            nameTagPos += 1 
            break

    print nameTagPos
    name = options.file.split("/")[nameTagPos]


    fout = ROOT.TFile.Open("cumulativeTransformation_"+name,"recreate")

    nbins = 10000
    xlow = 0.
    xup = 1.
    histoMVA = ROOT.TH1F("histoMVA","histoMVA",nbins,xlow,xup)
    tree.Draw("MVAOutput_vbf_ggf>>histoMVA",ROOT.TCut("weight"))
    #tree.Draw("MVAOutput_vbf_ggf>>histoMVA")
    histoMVA2 = ROOT.TH1F("histoMVA2","histoMVA2",nbins,xlow,xup)
    tree2.Draw("MVAOutput_vbf_gg>>histoMVA2",ROOT.TCut("weight"))
    #tree.Draw("MVAOutput_vbf_gg>>histoMVA2")

    cumulativeHisto = histoMVA.GetCumulative()
    cumulativeHisto.Scale(1./histoMVA.Integral())
    cumulativeGraph = ROOT.TGraph(cumulativeHisto)
    cumulativeGraph.SetTitle("cumulativeGraph")
    cumulativeGraph.SetName("cumulativeGraph")

    cumulativeHisto2 = histoMVA2.GetCumulative()
    cumulativeHisto2.Scale(1./histoMVA2.Integral())
    cumulativeGraph2 = ROOT.TGraph(cumulativeHisto2)
    cumulativeGraph2.SetTitle("cumulativeGraph2")
    cumulativeGraph2.SetName("cumulativeGraph2")

    evalCumulatives = ROOT.TH1F("eval","eval",nbins/10,0,1)
    evalCumulatives2 = ROOT.TH1F("eval2","eval2",nbins/10,0,1)

    x , y = array( 'd' ), array( 'd' )
    step = (xup-xlow)/nbins
    for i in range(1,10000):
        xvalue = ROOT.TH1.GetRandom(histoMVA)
        xvalue2 = ROOT.TH1.GetRandom(histoMVA2)
        evalCumulatives.Fill(cumulativeGraph.Eval(xvalue))
        evalCumulatives2.Fill(cumulativeGraph2.Eval(xvalue2))
    evalCumulatives.Sumw2()
    evalCumulatives2.Sumw2()
    evalCumulatives.Scale(1./evalCumulatives.Integral())
    evalCumulatives2.Scale(1./evalCumulatives2.Integral())
    evalCumulatives.GetYaxis().SetRangeUser(0,2./evalCumulatives.GetNbinsX())
    evalCumulatives2.GetYaxis().SetRangeUser(0,2./evalCumulatives2.GetNbinsX())

    c = ROOT.TCanvas()
    histoMVA.SetLineColor(ROOT.kRed)
    histoMVA2.SetLineColor(ROOT.kRed)
    histoMVA.Draw()
    histoMVA2.Draw()


    print name
    '''
    formats = [".png",".pdf"]

    for format in formats:
        c.SaveAs(name+"_func"+format)

    cumulativeGraph.Draw("AP")
    for format in formats:
        c.SaveAs(name+"_cum"+format)

    evalCumulatives.Draw("EP")
    for format in formats:
        c.SaveAs(name+"_evalx"+format)
    '''

    cumulativeGraph.Write()
    cumulativeGraph2.Write()
    fout.Write()
    fout.Close()

    fin.cd()

    processes = [
        "bbggSelectionTree",
       ]

    #fin = ROOT.TFile.Open(options.file)
    fin = ROOT.TFile.Open(indir+options.file)
    print fin
 
    #os.system('mkdir ' + indir + 'transformedMVA') 
    ##fTransformed = ROOT.TFile.Open(options.file.replace(".root","")+"_transformedMVA.root","recreate")
    fTransformed = ROOT.TFile.Open(options.outdir+options.file,"recreate")
    print fTransformed


    for proc in processes:
        print proc
        tree = fin.Get(proc)
        if proc=="bbggSelectionTree":
          chain = ROOT.TChain("bbggSelectionTree")
    
        #chain.Add(options.file)
        chain.Add(indir+options.file)
        copyTree = chain.CopyTree("")
        copyTree.SetName(proc)
        copyTree.SetTitle(proc)

        transfMVA = array( 'f', [ 0. ] )
        transfMVA2 = array( 'f', [ 0. ] )
        transfBranch = copyTree.Branch("MVAOutputTransformed_vbf_ggf",transfMVA,"MVAOutputTransformed_vbf_ggf/F");
        transfBranch2 = copyTree.Branch("MVAOutputTransformed_vbf_gg",transfMVA2,"MVAOutputTransformed_vbf_gg/F");
        dummyList = []
        
        entry = ROOT.TTree.GetEntries
        
        for i,event in enumerate(copyTree):
            if i>ROOT.TTree.GetEntries:break
#            if i>tree.GetEntries():break
            #mva = event.MVAOutput
            mva = event.MVAOutput_vbf_ggf
            transfMVA[0] = cumulativeGraph.Eval(mva)
            transfBranch.Fill()
            mva2 = event.MVAOutput_vbf_gg
            transfMVA2[0] = cumulativeGraph2.Eval(mva2)
            transfBranch2.Fill()
    
    
    fTransformed.Write()
    fTransformed.Close()

        
if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-i", "--infile",
                        action="store", type="string", dest="file",
                        default="",
                        help="input file",
                        ),
            ]
                          )

    parser.add_option('-s', '--indirSig', dest='indirSig', help='Input Signal dir name. [String]')
    parser.add_option('-d', '--indir', dest='indir', help='Input dir nanme. [String]')
    parser.add_option('-o', '--outdir', dest='outdir', help='Out dir nanme. [String]')

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT
    
    main(options,args)
        
