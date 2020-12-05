% fname: routing_XY__topology_8x8__.m
% ../bin/noxim -routing XY -topology MESH -dimx 8 -dimy 8  -sim 10000 -warmup 2000 -size 8 8 -buffer 4 -config ../config_examples/default_config.yaml -power ../bin/power.yaml 

function [max_pir, max_throughput, min_delay] = routing_XY__topology_8x8__(symbol)

data = [
%             pir      avg_delay     throughput      max_delay   total_energy       rpackets         rflits
             0.01        26.8486      0.0797305            366    8.69269e-06           5104          40822
             0.01        30.2736      0.0829512            764    8.71408e-06           5311          42471
             0.01        24.9774      0.0788711            389    8.67692e-06           5047          40382
             0.01        28.0142      0.0814863            605    8.70912e-06           5212          41721
             0.01        24.7312      0.0779316            461    8.67254e-06           4988          39901
             0.01         27.558       0.079791            336    8.70399e-06           5106          40853
             0.01        27.6929      0.0810977            803    8.71453e-06           5190          41522
             0.01        25.8907      0.0804297            283    8.69619e-06           5149          41180
             0.01         22.987      0.0781602            379    8.68368e-06           5003          40018
             0.01        27.3054       0.081207            314    8.72019e-06           5200          41578
            0.011        34.2683      0.0865137            739    8.76273e-06           5538          44295
            0.011        37.2363      0.0875664            746    8.77807e-06           5602          44834
            0.011        31.5804      0.0870039            370    8.77161e-06           5569          44546
            0.011        41.8362      0.0880586            846    8.78231e-06           5634          45086
            0.011        34.3605      0.0878711            716    8.78076e-06           5622          44990
            0.011         34.557      0.0875957            823    8.77336e-06           5607          44849
            0.011        32.8066       0.089125            389    8.76709e-06           5703          45632
            0.011         36.887      0.0898711            526    8.79267e-06           5752          46014
            0.011        36.7332      0.0893301            541    8.78285e-06           5719          45737
            0.011        30.8969      0.0875195            666    8.77654e-06           5599          44810
            0.012        59.8615      0.0964902           1563    8.86475e-06           6175          49403
            0.012        46.1493      0.0935605            971    8.83238e-06           5987          47903
            0.012        46.6447      0.0958965            719     8.8635e-06           6139          49099
            0.012        46.4993       0.095666            781    8.85207e-06           6126          48981
            0.012        42.9959      0.0943945            887    8.84613e-06           6039          48330
            0.012        36.2121      0.0940566            663    8.83354e-06           6020          48157
            0.012        41.1675        0.09525            585    8.84755e-06           6096          48768
            0.012         54.051       0.094291            987    8.84572e-06           6036          48277
            0.012         46.501       0.095498            740    8.85721e-06           6114          48895
            0.012        57.0531      0.0957383           1124    8.86551e-06           6126          49018
            0.013        161.189       0.103908           3646    8.94995e-06           6652          53201
            0.013        165.732       0.103799           2690    8.94159e-06           6647          53145
            0.013        101.669       0.102094           3246    8.92413e-06           6536          52272
            0.013        121.352       0.102912           2776    8.92984e-06           6587          52691
            0.013        135.769       0.102656           3444    8.92274e-06           6568          52560
            0.013        106.908       0.102006           2147      8.921e-06           6530          52227
            0.013        82.2774       0.102959           1494    8.92946e-06           6590          52715
            0.013        117.371       0.103557           2197    8.93413e-06           6632          53021
            0.013        92.8213       0.101045           3577    8.91445e-06           6465          51735
            0.013        108.012       0.105336           1871    8.95371e-06           6743          53932
            0.014        201.724       0.109311           4531      8.988e-06           6998          55967
            0.014        190.285       0.106811           6674    8.97944e-06           6837          54687
            0.014        206.989       0.107496           5035    8.97868e-06           6882          55038
            0.014        155.954       0.108402           5406    8.98749e-06           6939          55502
            0.014        216.143        0.10851           5894    8.98389e-06           6945          55557
            0.014        229.212       0.107449           5053    8.97613e-06           6878          55014
            0.014        201.483       0.106758           6115    8.96853e-06           6834          54660
            0.014        166.684       0.107375           5817    8.97451e-06           6872          54976
            0.014        246.765       0.107889           6220    8.98262e-06           6906          55239
            0.014        324.748       0.106789           5460    8.97245e-06           6837          54676
];

rows = size(data, 1);
cols = size(data, 2);

data_delay = [];
for i = 1:rows/10,
   ifirst = (i - 1) * 10 + 1;
   ilast  = ifirst + 10 - 1;
   tmp = data(ifirst:ilast, cols-6+1);
   avg = mean(tmp);
   [h sig ci] = ttest(tmp, 0.1);
   ci = (ci(2)-ci(1))/2;
   data_delay = [data_delay; data(ifirst, 1:cols-6), avg ci];
end

fig1 = figure(1);
set(fig1,'Name','data_delay');
hold on;
plot(data_delay(:,1), data_delay(:,2), symbol);

data_throughput = [];
for i = 1:rows/10,
   ifirst = (i - 1) * 10 + 1;
   ilast  = ifirst + 10 - 1;
   tmp = data(ifirst:ilast, cols-6+2);
   avg = mean(tmp);
   [h sig ci] = ttest(tmp, 0.1);
   ci = (ci(2)-ci(1))/2;
   data_throughput = [data_throughput; data(ifirst, 1:cols-6), avg ci];
end

fig2 = figure(2);
set(fig2,'Name','data_throughput');
hold on;
plot(data_throughput(:,1), data_throughput(:,2), symbol);

data_maxdelay = [];
for i = 1:rows/10,
   ifirst = (i - 1) * 10 + 1;
   ilast  = ifirst + 10 - 1;
   tmp = data(ifirst:ilast, cols-6+3);
   avg = mean(tmp);
   [h sig ci] = ttest(tmp, 0.1);
   ci = (ci(2)-ci(1))/2;
   data_maxdelay = [data_maxdelay; data(ifirst, 1:cols-6), avg ci];
end

fig3 = figure(3);
set(fig3,'Name','data_maxdelay');
hold on;
plot(data_maxdelay(:,1), data_maxdelay(:,2), symbol);

data_totalenergy = [];
for i = 1:rows/10,
   ifirst = (i - 1) * 10 + 1;
   ilast  = ifirst + 10 - 1;
   tmp = data(ifirst:ilast, cols-6+4);
   avg = mean(tmp);
   [h sig ci] = ttest(tmp, 0.1);
   ci = (ci(2)-ci(1))/2;
   data_totalenergy = [data_totalenergy; data(ifirst, 1:cols-6), avg ci];
end

fig4 = figure(4);
set(fig4,'Name','data_totalenergy');
hold on;
plot(data_totalenergy(:,1), data_totalenergy(:,2), symbol);


%-------- Saturation Analysis -----------
slope=[];
for i=2:size(data_throughput,1),
    slope(i-1) = (data_throughput(i,2)-data_throughput(i-1,2))/(data_throughput(i,1)-data_throughput(i-1,1));
end

for i=2:size(slope,2),
    if slope(i) < (0.95*mean(slope(1:i)))
        max_pir = data_throughput(i, 1);
        max_throughput = data_throughput(i, 2);
        min_delay = data_delay(i, 2);
        break;
    end
end
