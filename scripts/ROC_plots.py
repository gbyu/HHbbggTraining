import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)

#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st/ROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_MCbkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_MCbkg/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_MCbkg_MXcut/train_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_bkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_bkg/train_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
#roc_auc = auc(fpr, tpr)
#roc_auc = 0.9778   #test_xgbr_diphotons
roc_auc = 0.9899  #test_xgbr_gJets   
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), standart input variables'%(roc_auc))

#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_pt_mgg/ROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_MCbkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_MCbkg/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_MCbkg_MXcut/train_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_bkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_bkg/train_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
#roc_auc = 0.9790   #test_xgbr_diphotons
roc_auc = 0.9909  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), standart input variables with adding pt/mgg'%(roc_auc))

#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_pt_mgg_pt_mjj_drother/ROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_ptmjj_r_MCbkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_ptmjj_r_MCbkg/test_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_ptmjj_r_bkg/test_xgbr_diphotons_st_cutsROC_res.dat', 'r') as f:
#with open('/home/ovtin/cernbox/HHggbb/HHbbgg_ETH_devel/Training/plots/st_ptmgg_ptmjj_r_bkg/train_xgbr_gJets_st_cutsROC_res.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y = [float(line.split()[1]) for line in lines]
        
#roc_auc = 0.9809   #test_xgbr_diphotons
roc_auc = 0.9915  #test_xgbr_gJets  
plt.plot(y, x, lw=1, label='ROC (area = %0.4f), standart input variables with adding pt/mgg, pt/Mjj, PhoJetotherDr'%(roc_auc))
#plt.plot(y, x, lw=1, label='ROC (area = %0.4f), standart input variables with adding pt/mgg, pt/Mjj, PhoJetotherDr'%(roc_auc), marker='o')
#for i,j in zip(y,x):

#test_xgbr_diphotons
#x2 = 0.089
#y2 = 0.940  
#x1 = 0.089
#y1 = 0
#
#test_xgbr_gJets
x2 = 0.036
y2 = 0.940  
x1 = 0.036
y1 = 0
ax.annotate('(%s;' %x2, xy=(x2+0.005,y2-0.010), fontsize=24)    
ax.annotate('%s)' %y2, xy=(x2+0.027,y2-0.010), xytext=(50,0), textcoords='offset points', fontsize=24)
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    #([x1,x2],[y1,y2])
#test_xgbr_diphotons
#x2 = 0.071
#y2 = 0.940  
#x1 = 0.071
#y1 = 0
#
#test_xgbr_gJets
x2 = 0.027
y2 = 0.940 
x1 = 0.027
y1 = 0
ax.annotate('(%s;' %x2, xy=(x2-0.074,y2+0.003), fontsize=24)    
ax.annotate('%s)' %y2, xy=(x2-0.052,y2+0.003), xytext=(50,0), textcoords='offset points', fontsize=24)
plt.plot(x2, y2, marker='o')    
plt.plot([x1,x2],[y1,y2], "--")    
#test_xgbr_diphotons
#x2 = 0.089
#y2 = 0.940  
#x1 = -0.05
#y1 = 0.940
#
#test_xgbr_gJets
x2 = 0.036
y2 = 0.940
x1 = -0.05
y1 = 0.940
plt.plot([x1,x2],[y1,y2], "--")    
    
#plt.figure(1, figsize=(4, 3))
#plt.xlim([-0.05, 1.05])
#plt.ylim([-0.05, 1.05])
plt.xlim([-0.05, 0.50])
plt.ylim([0.70, 1.01])
#plt.xlabel('False Positive Rate', fontsize="large")  #xx-large
#plt.ylabel('True Positive Rate', fontsize="large")
plt.xlabel('False Positive Rate', fontsize=20)
plt.ylabel('True Positive Rate', fontsize=20)
#plt.title('ROC Curve')
plt.xticks(size = 20)
plt.yticks(size = 20)
#plt.legend(loc="lower right", fontsize="large")
#plt.legend(loc="lower right", fontsize="xx-small")
plt.legend(loc=4, prop={'size': 18})
plt.grid()
#plt.line((0.20,0.00, 0.20,0.90), fill=128)
plt.savefig("test.eps")

plt.show()

