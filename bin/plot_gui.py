import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os
import tkinter as tk
import tkinter.filedialog as fd

root = tk.Tk()
root.geometry('0x0')
files = fd.askopenfilenames(parent=root,initialdir = '/home/karthik/noxim/bin/new_csv_files/latency', title='Choose files to plot')

rate_list = []
latency_list = []

for i in files:
    df = pd.read_csv(i,header=None)
    rates = df.iloc[:,0].values
    latencies = df.iloc[:,1].values
    rate_list.append(rates)
    latency_list.append(latencies)
    #print(rates,latencies)

for x,y in zip(rate_list,latency_list):
    plt.plot(x,y,'-o')

file_names = [f.split('/')[-1] for f in files]
legends = [x[:x.rindex("_")] for x in file_names]
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
