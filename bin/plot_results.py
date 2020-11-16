import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os

file_list = os.listdir('./csv_files')
file_list.sort()
for i,j in enumerate(file_list):
    print(f'{i}) {j}')

ch = list(map(int,input('Space Seperated File Numbers: ').split()))

files = []

for i in ch:
    files.append(file_list[i])


rate_list = []
latency_list = []

for i in files:
    df = pd.read_csv('./csv_files/'+i,header=None)
    rates = df.iloc[:,0].values
    latencies = df.iloc[:,1].values
    rate_list.append(rates)
    latency_list.append(latencies)
    #print(rates,latencies)

for x,y in zip(rate_list,latency_list):
    plt.plot(x,y,'-o')

legends = [x[:x.rindex("_")] for x in files]
plt.legend(legends)
plt.show()
