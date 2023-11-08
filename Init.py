import csv
import sys
import pandas as pd
import numpy as np
#from sklearn.model_selection import KFold
if(len(sys.argv) < 2):
    print("没有文件路径!");
    exit(0);

filepath = './DataSets/ori/' + sys.argv[1] + '.data';
filepath2 = './DataSets/toone/' + sys.argv[1] + '.xlsx'
#head = ["age","year of operation","Number of pan","ans"];
head = ["sepal length","sepal width","petal length","petal width","ans"];
catoMap = {}
head_Data = [];
data = {}
for i in head:
    head_Data.append([i])
    data[i] = [];
#print(data)
with open(filepath,"r") as fin:
    nowstr = fin.readline()
    while(nowstr != ''):
        if(nowstr != '\n'):
            li = nowstr.strip('\n').split(',')
            for i in range(0,len(head) - 1):
                data[head[i]].append(li[i])
            last = len(head) - 1
            if(not catoMap.get(li[last])):
                    catoMap[li[last]] = len(catoMap) + 1
            data[head[last]].append(catoMap[li[last]])
        nowstr = fin.readline()
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
        
nm = df.to_numpy()
print(nm);
np.random.seed(1337)
np.random.shuffle(nm);
print(nm);
df = pd.DataFrame(data=nm,columns= head,dtype=float)
print(catoMap);
# print(df)
# kf = KFold(n_splits=2)
# for train,test in kf.split(['a','b','c','d']):
#     print(train,test)

df.to_excel(filepath2,"Sheet1");
# with pd.ExcelWriter(filepath2) as writer:

