import sys
import os
import time




injection_rates = [0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5]
#injection_rates = [0.012,0.014,0.016,0.018,0.020,0.022,0.024,0.026,0.028]
routing_algo = 'ODD_EVEN'
selection_algo = 'RANDOM'
traffic_pattern = 'TRANSPOSE1'

def yaml_handler(yaml_file,key,value):
    f = open(yaml_file,'r')
    lines = f.readlines()
    for i in range(len(lines)):
        if((key in lines[i]) and ('#' not in lines[i])):
            lines[i] = lines[i].split(':')[0]+": "+str(value)+"\n"
    with open('temp.yaml','w') as of:
        of.writelines(lines)


def run_sim(yaml_file,rate,routing_algo,selection_algo,traffic_pattern):
    yaml_handler(yaml_file,'packet_injection_rate',rate)
    yaml_handler('temp.yaml','routing_algorithm',routing_algo)
    yaml_handler('temp.yaml','selection_strategy',selection_algo)
    yaml_handler('temp.yaml','traffic_distribution','TRAFFIC_'+traffic_pattern)
    os.system(f'./noxim -config ./temp.yaml > ./test_results/temp_res')


def parse(filename):
    f= open(filename,'r')
    lines = f.readlines()
    req = lines[-15:]
    delay_line = [i for i in req if "Global average delay" in i]
    req_line = delay_line[0]
    delay = req_line.split(':')[1].strip()
    return float(delay)


if __name__ == '__main__':
    config_file = '../config_examples/test_config.yaml'
    csv_path = f'csv_files/{routing_algo}_{selection_algo}_{traffic_pattern}_{int(time.time())}.csv'
    latest_path = f'csv_files/{routing_algo}_{selection_algo}_{traffic_pattern}_latest.csv'
    csv_file = open(csv_path,'w')
    latest_file = open(latest_path,'w')
    print(f'Routing Algo: {routing_algo} | Selection: {selection_algo} | Traffic: {traffic_pattern}')
    c=1
    for i in injection_rates:
        run_sim(config_file,i,routing_algo,selection_algo,traffic_pattern)
        latency = parse('./test_results/temp_res')
        csv_file.write(f'{i},{latency}\n')
        latest_file.write(f'{i},{latency}\n')
        print(f'{c}/{len(injection_rates)} => {i} : {latency}')
        c+=1
    csv_file.close()
    latest_file.close()
