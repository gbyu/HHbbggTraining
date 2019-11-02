import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_lxplus/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_lxplus/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9741   #test_xgbr_diphotons
#roc_auc = 0.9882  #test_xgbr_gJets   
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables'%(roc_auc))

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_ptmgg_lxplus/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_ptmgg_lxplus/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9760   #test_xgbr_diphotons
#roc_auc = 0.9895  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables + pt/mgg'%(roc_auc))

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_ptmgg_ptmjj_dR_lxplus/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2017/st_MC_Bkg_ptmgg_ptmjj_dR_lxplus/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9777   #test_xgbr_diphotons
#roc_auc = 0.9901  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables + pt/mgg, pt/Mjj, PhoJetOtherDr'%(roc_auc))
#plt.plot(y, x, lw=1, label='ROC (area = %0.4f), standart input variables with adding pt/mgg, pt/Mjj, PhoJetotherDr'%(roc_auc), marker='o')
#for i,j in zip(y,x):

#test_xgbr_diphotons
x2 = 0.105
y2 = 0.940  
x1 = 0.105
y1 = 0
#
#test_xgbr_gJets
#x2 = 0.043
#y2 = 0.940  
#x1 = 0.043
#y1 = 0
ax.annotate('(%s; %s)' %(x2,y2) , xy=(x2+0.007,y2-0.017), fontsize=34)    
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    #([x1,x2],[y1,y2])
#test_xgbr_diphotons
x2 = 0.088
y2 = 0.940  
x1 = 0.088
y1 = 0
#
#test_xgbr_gJets
#x2 = 0.033
#y2 = 0.940 
#x1 = 0.033
#y1 = 0
ax.annotate('(%s; %s)' %(x2,y2), xy=(x2-0.110,y2+0.008), fontsize=34)    
#ax.annotate('(%s; %s)' %(x2,y2), xy=(x2-0.080,y2+0.008), fontsize=34)    
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    
#test_xgbr_diphotons
x2 = 0.105
y2 = 0.940  
x1 = -0.05
y1 = 0.940
#
#test_xgbr_gJets
#x2 = 0.0390
#y2 = 0.940
#x1 = -0.05
#y1 = 0.940
plt.plot([x1,x2],[y1,y2], "--")    
    
#plt.figure(1, figsize=(4, 3))
#plt.xlim([-0.05, 1.05])
#plt.ylim([-0.05, 1.05])
plt.xlim([-0.05, 0.50])
plt.ylim([0.70, 1.01])
#plt.xlabel('False Positive Rate', fontsize="large")  #xx-large
#plt.ylabel('True Positive Rate', fontsize="large")
plt.xlabel('False Positive Rate', fontsize=24)
plt.ylabel('True Positive Rate', fontsize=24)
#plt.title('ROC Curve')
plt.xticks(size = 24)
plt.yticks(size = 24)
#plt.legend(loc="lower right", fontsize="large")
#plt.legend(loc="lower right", fontsize="xx-small")
plt.legend(loc=4, prop={'size': 26})
plt.grid()
#plt.line((0.20,0.00, 0.20,0.90), fill=128)
plt.savefig("test.eps")

plt.show()

