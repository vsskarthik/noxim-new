% fname: routing_CAOE__topology_4x4__.m
% ../bin/noxim -routing CAOE -topology MESH -dimx 4 -dimy 4  -sim 10000 -warmup 2000 -size 8 8 -buffer 4 -config ../config_examples/test_config.yaml -power ../bin/power.yaml 

function [max_pir, max_throughput, min_delay] = routing_CAOE__topology_4x4__(symbol)

data = [
%             pir      avg_delay     throughput      max_delay   total_energy       rpackets         rflits
