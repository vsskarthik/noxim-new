import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os

dir = 'latency'
csv_folder = 'new_csv_files'
file_list = os.listdir(f'./{csv_folder}/'+dir)
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
    df = pd.read_csv('./csv_files/'+dir+'/'+i,header=None)
    rates = df.iloc[:,0].values
    latencies = df.iloc[:,1].values
    rate_list.append(rates)
    latency_list.append(latencies)
    #print(rates,latencies)

for x,y in zip(rate_list,latency_list):
    plt.plot(x,y,'-o')

legends = [x[:x.rindex("_")] for x in files]
legends = [x[:x.rindex("_")] for x in legends]
legends = [x[:x.rindex("_")] if('BIT' in x) else x for x in legends]
traffic = files[0]
traffic = traffic[:traffic.rindex('_')]
if('BIT' in traffic):
    idx = traffic[:traffic.rindex('_')].rindex('_')
    traffic = traffic[idx+1:]
else:
    traffic = traffic[traffic.rindex('_')+1:]


plt.legend(legends)
plt.xlabel('Packet Injection Rates(packet/cycle/node)')
plt.ylabel('Average Packet Latency(cycles)')
plt.title(traffic)
plt.show()
