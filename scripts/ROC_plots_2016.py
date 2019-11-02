import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9713   #test_xgbr_diphotons
#roc_auc = 0.9868  #test_xgbr_gJets   
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables'%(roc_auc))

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st_ptmgg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st_ptmgg/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9734   #test_xgbr_diphotons
#roc_auc = 0.9886  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables + pt/mgg'%(roc_auc))

with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st_ptmgg_ptmjj_dR/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbggTraining/Training/output_files/2016/st_ptmgg_ptmjj_dR/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
roc_auc = 0.9753   #test_xgbr_diphotons
#roc_auc = 0.9886  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), Std. variables + pt/mgg, pt/Mjj, PhoJetOtherDr'%(roc_auc))
#for i,j in zip(y,x):
#test_xgbr_diphotons
x2 = 0.124
y2 = 0.940  
x1 = 0.124
y1 = 0
#
#test_xgbr_gJets
#x2 = 0.049
#y2 = 0.940 
#x1 = 0.049
#y1 = 0
ax.annotate('(%s; %s)' %(x2,y2) , xy=(x2+0.007,y2-0.017), fontsize=34)    
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    #([x1,x2],[y1,y2])
#test_xgbr_diphotons
x2 = 0.099
y2 = 0.940  
x1 = 0.099
y1 = 0
#
#test_xgbr_gJets
#x2 = 0.039
#y2 = 0.940  
#x1 = 0.039
#y1 = 0
#ax.annotate('(%s; %s)' %(x2,y2), xy=(x2-0.085,y2+0.008), fontsize=34)    
ax.annotate('(%s; %s)' %(x2,y2), xy=(x2-0.100,y2+0.008), fontsize=34)    
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    
#test_xgbr_diphotons
x2 = 0.124
y2 = 0.940  
x1 = -0.05
y1 = 0.940
#
#test_xgbr_gJets
#x2 = 0.049
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

