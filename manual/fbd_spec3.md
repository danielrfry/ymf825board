## Tone Parameter

#### Notes
+ [tn] means "Tone Number". Ymf825 has a maximum of 16 tones.
+ [op] means "FM Operator". Ymf825 has 4 operators per voice.

### BO

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#0+30x[tn]|BO|"0"|"0"|"0"|"0"|"0"|"0"|BO1|BO0|

#### Description
BO means Basic Octave. BO controls an octave setting.

+ BO=0 : 2^1
+ BO=1 : 2^0
+ BO=2 : 2^-1
+ BO=3 : 2^-2

### LFO, ALG

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#1+30x[tn]|LFO,ALG|LFO1|LFO0|"0"|"0"|"0"|ALG2|ALG1|ALG0|

#### Description

LFO means a frequency of low frequency oscillator.

+ LFO=0 : 1.8Hz
+ LFO=1 : 4.0Hz
+ LFO=2 : 5.9Hz
+ LFO=3 : 7.0Hz

ALG means FM Algorithm. 8 algorithms can be selected.

![FM Algorithm](algo.png)


### SR, XOF, KSR

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#2+30x[tn]+7x[op]|SR, XOF, KSR|SR3|SR2|SR1|SR0|XOF|"0"|"0"|KSR|

#### Description

SR controls sustain rate of each operator.
if SR is set to 0, sound level is retained.  
XOF controls ignoring keyoff.
Evenif keyoff is set, any changes will not happen.  
KSR means key scale sensitivity for AEG rate. if KSR bit is on, high F-num EG rate changes faster.


### RR, DR

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#3+30x[tn]+7x[op]|RR,DR|RR3|RR2|RR1|RR0|DR3|DR2|DR1|DR0|

#### Description

RR controls release rate of each operator.  
DR controls decay rate of each operator.  

### AR, SL

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#4+30x[tn]+7x[op]|AR,SL|AR3|AR2|AR1|AR0|SL3|SL2|SL1|SL0|

#### Description

AR controls attack rate of each operator.  
SL controls sustain level of each operator. Sustain Level is the level just after decay rate.

### TL, KSL

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#5+30x[tn]+7x[op]|TL,KSL|TL5|TL4|TL3|TL2|TL1|TL0|KSL1|KSL0|

#### Description
TL means total level.TL controls operator level.  

KSL means key scaling level sensitivity.In natural instruments, the volume attenuates as the pitch increases.KSL simulates this phenomenon.
+ KSL=0 : 0
+ KSL=1 : 3dB/oct
+ KSR=2 : 1.5dB/oct
+ KSR=3 : 6.0dB/oct


### DAM, EAM, DVB, EVB

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#6+30x[tn]+7x[op]|DAM,EAM,DVB,EVB|"0"|DAM1|DAM0|EAM|"0"|DVB1|DVB0|EVB|

#### Description

EAM means enable amplitude modulation.EAM set amplitude modulation.   
DAM means amplitude modulation depth.  
+ DAM=0 : 1.3dB
+ DAM=1 : 2.8dB
+ DAM=2 : 5.8dB
+ DAM=3 : 11.8dB

EVB means enable vibrato.EVB set vibrato.  
DVB means vibrato depth.
+ DVB=0 : 3.4cent
+ DVB=1 : 6.7cent
+ DVB=2 : 13.5cent
+ DVB=3 : 26.8cent


### MULTI, DT

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#7+30x[tn]+7x[op]|MULTI, DT|MULTI3|MULTI2|MULTI1|MULTI0|"0"|DT2|DT1|DT0|

#### Description
MULTI controls magnification of frequency.  

|MULTI|0|1|2|3|4|5|6|7|8|9|10,11|12,13|14,15|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|magnification|1/2|1|2|3|4|5|6|7|8|9|10|12|15|

DT means detune.  
MSB of DT indicates a sign bit. When DT=0, no effect is applied.  
The detune frequency is affected by MULTI setting. If MULTI is doubled, it will also be doubled.  

The table below shows the frequency difference between BLOCK+BO, FNUM, DT setting and DT=0.

|BLOCK+BO|FNUM|DT=x01b|DT=x10b|DT=x11b|
|-|-|-|-|-|-|
|0|000H-|0[Hz]|0.05[Hz]|0.09[Hz]|
|0|1C0H-|0|0.05|0.09|
|0|200H-|0|0.05|0.09|
|0|240H-|0|0.05|0.09|
|1|000H-|0.05|0.09|0.14|
|1|1C0H-|0.05|0.09|0.14|
|1|200H-|0.05|0.09|0.14|
|1|240H-|0.05|0.09|0.14|
|2|000H-|0.05|0.09|0.18|
|2|1C0H-|0.05|0.14|0.18|
|2|200H-|0.05|0.14|0.18|
|2|240H-|0.05|0.14|0.23|
|3|000H-|0.09|0.18|0.23|
|3|1C0H-|0.09|0.18|0.27|
|3|200H-|0.09|0.18|0.27|
|3|240H-|0.09|0.23|0.32|
|4|000H-|0.09|0.23|0.37|
|4|1C0H-|0.14|0.27|0.37|
|4|200H-|0.14|0.27|0.41|
|4|240H-|0.14|0.32|0.46|
|5|000H-|0.18|0.37|0.50|
|5|1C0H-|0.18|0.37|0.55|
|5|200H-|0.18|0.41|0.59|
|5|240H-|0.23|0.46|0.64|
|6|000H-|0.23|0.50|0.73|
|6|1C0H-|0.27|0.55|0.78|
|6|200H-|0.27|0.59|0.87|
|6|240H-|0.32|0.64|0.91|
|7|000H-|0.37|0.73|1.00|
|7|1C0H-|0.37|0.73|1.00|
|7|200H-|0.37|0.73|1.00|
|7|240H-|0.37|0.73|1.00|

### WS, FB

|T_ADR|Name|D7|D6|D5|D4|D3|D2|D1|D0|
|-|-|-|-|-|-|-|-|-|-|
|#8+30x[tn]+7x[op]|WS,FB|WS5|WS3|WS2|WS1|WS0|FB2|FB1|FB0|

#### Description
WS means wave shape each operator generates.
29 wave shapes can be selected.  

![wave shapes](ws.png)

FB means FM feedback level.
+ FB=0 : 0
+ FB=1 : pi/16
+ FB=2 : pi/8
+ FB=3 : pi/4
+ FB=4 : pi/2
+ FB=5 : pi
+ FB=6 : 2pi
+ FB=7 : 4pi

### How to calculate EG Rate

From the AR/DR/SR/RR setting value and Rof, the RATE value is calculated by the following formula.  
* RATE = [AR/DR/SR/RR]*4 + Rof

Rof is the offset value, which is determined by KSR, BLOCK+BO and FNUM MSB.

|KSR|BLOCK+BO|FNUM MSB|Rof|
|-|-|-|-|
|0|0|0|0|
|0|0|1|0|
|0|1|0|0|
|0|1|1|0|
|0|2|0|1|
|0|2|1|1|
|0|3|0|1|
|0|3|1|1|
|0|4|0|2|
|0|4|1|2|
|0|5|0|2|
|0|5|1|2|
|0|6|0|3|
|0|6|1|3|
|0|7|0|3|
|0|7|1|3|
|1|0|0|0|
|1|0|1|1|
|1|1|0|2|
|1|1|1|3|
|1|2|0|4|
|1|2|1|5|
|1|3|0|6|
|1|3|1|7|
|1|4|0|8|
|1|4|1|9|
|1|5|0|10|
|1|5|1|11|
|1|6|0|12|
|1|6|1|13|
|1|7|0|14|
|1|7|1|15|

Please refer to the table below from the obtained RATE value to find the actual time.

|RATE|Attack [ms]/(0-96[dB])|Other [ms]/(0-96[dB])|
|-|-|-|
|64-60|0|2.63|
|59|0.26|3.00|
|58|0.30|3.50|
|57|0.34|4.20|
|56|0.38|5.25|
|55|0.43|6.01|
|54|0.53|7.00|
|53|0.62|8.40|
|52|0.71|10.50|
|51|0.82|12.00|
|50|0.96|14.00|
|49|1.15|16.80|
|48|1.44|21.00|
|47|1.65|24.00|
|46|1.92|28.00|
|45|2.23|33.60|
|44|2.88|42.00|
|43|3.28|48.00|
|42|3.83|56.00|
|41|4.60|67.20|
|40|5.75|84.00|
|39|6.56|96.00|
|38|7.66|112.00|
|37|9.19|134.00|
|36|11.49|168.00|
|35|13.14|192.00|
|34|15.32|224.00|
|33|18.39|268.80|
|32|22.99|336.00|
|31|26.28|384.00|
|30|30.66|448.00|
|29|36.79|537.60|
|28|45.98|672.00|
|27|52.55|768.00|
|26|61.31|896.00|
|25|73.57|1075.20|
|24|91.97|1344.00|
|23|105.09|1536.00|
|22|122.61|1792.00|
|21|147.14|2150.41|
|20|183.92|2688.00|
|19|210.20|3072.00|
|18|245.23|3584.00|
|17|294.28|4300.80|
|16|367.85|5376.00|
|15|420.40|6144.00|
|14|490.47|7168.00|
|13|588.55|8601.60|
|12|735.69|10752.01|
|11|840.80|12288.00|
|10|980.92|14336.00|
|9|1177.11|17203.20|
|8|1471.39|21504.00|
|7|1681.59|24576.00|
|6|1961.86|28672.00|
|5|2354.23|34406.40|
|4|2942.78|43008.00|
|0-3|EG stops|EG stops|



