# Conversion XGBoost model to TMVA weight file for Classification
python convert_pkl2xml.py --infile test_file.pkl  <br /> 

# Conversion XGBoost model to TMVA weight file for Regression
python convert_regression_pkl2xml.py --infile test_file.pkl  <br />

# Read TMVA weight file
root -l -q Reader_xml.C <br />
