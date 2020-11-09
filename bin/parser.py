import sys
import os


def yaml_handler(yaml_file,key,value):
    f = open(yaml_file,'r')
    lines = f.readlines()
    for i in range(len(lines)):
        if((key in lines[i]) and ('#' not in lines[i])):
            lines[i] = lines[i].split(':')[0]+": "+str(value)+"\n"
    with open('temp.yaml','w') as of:
        of.writelines(lines)

#[TODO] Add Log Function


def run_sim(yaml_file,rate,routing_algo,selection_algo):
    yaml_handler(yaml_file,'packet_injection_rate',rate)
    yaml_handler('temp.yaml','routing_algorithm',routing_algo)
    yaml_handler('temp.yaml','selection_strategy',selection_algo)
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
    config_file = '../config_examples/my_config.yaml'
    injection_rates = [0.01,0.02,0.1]
    routing_algo = 'ODD_EVEN'
    selection_algo = 'RANDOM'
    print(f'{routing_algo} | {selection_algo}')
    for i in injection_rates:
        run_sim(config_file,i,routing_algo,selection_algo)
        latency = parse('./test_results/temp_res')
        print(f'{i} : {latency}')


