# TDFDcube
Hello Jerry W,

Find here a C++ program that I wrote based on the information in your posting.

14 Dec 2016 - v0.0.1

For matrix/array problems of this type, I recommend using Boost multi_array:
http://www.boost.org/doc/libs/1_62_0/libs/multi_array/doc/
http://www.boost.org/doc/libs/1_62_0/libs/multi_array/doc/user.html

On Mac/Linux/UNIX compile with:
g++ -std=c++11  TDFDcube.cpp -o TDFDcube

NOTE: You must have Boost installed!

keithjmiklas@gmail.com


[~/g/evolve] $ ./TDFDcube 
Rectangular prism slice 0:
0	1	2	3
4	5	6	7
8	9	10	11
12	13	14	15
16	17	18	19

Rectangular prism slice 1:
20	21	22	23
24	25	26	27
28	29	30	31
32	33	34	35
36	37	38	39

Rectangular prism slice 2:
40	41	42	43
44	45	46	47
48	49	50	51
52	53	54	55
56	57	58	59

Simple performance test. Assign prism values 1,000,000 times, and clock it.
It took 5.05094 seconds.
