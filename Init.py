import csv
import sys
import pandas as pd
import numpy as np
from sklearn.model_selection import KFold
import Train
if(len(sys.argv) < 2):
    print("没有文件路径!");
    exit(0);

filepath = './DataSets/ori/' + sys.argv[1] + '.data';
filepath2 = './DataSets/toone/' + sys.argv[1] + '.xlsx'
head = ["age","year of operation","Number of pan","ans"];
head_Data = [];
data = {}
for i in head:
    head_Data.append([i])
    data[i] = [];
#print(data)
with open(filepath,"r") as fin:
    str = fin.readline()
    while(str != ''):
        if(str != '\n'):
            li = str.strip('\n').split(',')
            for i in range(0,len(head)):
                data[head[i]].append(li[i])
        str = fin.readline()
#print(data);
DataF = pd.DataFrame(data=data,dtype=float)
df = pd.DataFrame(data=data,dtype=float)


for colum in DataF.columns:
    if(colum == "ans"):
        df[colum] = DataF[colum]
        break;
    cmax = max(DataF[colum])
    cmin = min(DataF[colum])
    for i in range(0,DataF[colum].size):
        df[colum][i] = (DataF[colum][i] - cmin) / (cmax - cmin)
        

print(df)

kf = KFold(10)
for train,test in kf.split(df):
    Train.train()
    
#df.to_excel(filepath2,"Sheet1");
# with pd.ExcelWriter(filepath2) as writer:

