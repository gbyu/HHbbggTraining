for year in 2017
do

indirSig="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/$year/"$year"_SM_c2v01_noCosTheta_conversion/"
indir="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/$year/"$year"_SM_c2v01_noCosTheta_conversion/"
##indir="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/$year/"$year"_SM_c2v01_noCosTheta_conversion/C2V/"
##indir="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/$year/"$year"_SM_c2v01_noCosTheta_conversion/KL/"
out="transformedMVA"
##out="transformedMVA/C2V"
##out="transformedMVA/KL"
outdir="/afs/cern.ch/work/i/ivovtin/public/legacy_branch_flattrees/vbfhh/$year/"$year"_SM_c2v01_noCosTheta_conversion/$out/"
mkdir $outdir
 
##python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_allnodes_TuneCP5_PSWeights_13TeV-madgraph-pythia8.root -o $outdir

python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i Data.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_1_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_0_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
##python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_2_C3_1_dipoleRecoilOn-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_2_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_5_C2V_1_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_0_5_C2V_1_C3_1_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_1_C3_2_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_1_C3_0_dipoleRecoilOff-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
##python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHHTo2B2G_CV_1_C2V_1_C3_1_dipoleRecoilOn-TuneCP5_PSweights_13TeV-madgraph-pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_VBFHToGG_M-125_13TeV_powheg_pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_GluGluToHHTo2B2G_all_node.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_ttHToGG_M125_13TeV_powheg_pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_DiPhotonJetsBox2BJets_MGG-80toInf_13TeV-Sherpa.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_DiPhotonJetsBox1BJet_MGG-80toInf_13TeV-Sherpa.root -o $outdir
python transformMVAOutput_VBFHH.py -s $indirSig -d $indir -i output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root -o $outdir

done 
