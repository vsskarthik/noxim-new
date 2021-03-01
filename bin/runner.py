import os

r_algos = ['CAXY','CAOE']
s_algos = ['FA']
traffics = ['BIT_REVERSAL','RANDOM','TRANSPOSE1','TRANSPOSE2']

for r in r_algos:
    for s in s_algos:
        for t in traffics:
            os.system(f'python3 parser-cli.py {r} {s} {t}')