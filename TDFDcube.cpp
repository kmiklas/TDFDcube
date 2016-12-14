// TDFDcube v0.1 for Jerry W
// 14 Dec 2016 - v0.0.1
// 
// For matrix/array problems of this type, I recommend using Boost multi_array:
// http://www.boost.org/doc/libs/1_62_0/libs/multi_array/doc/
// http://www.boost.org/doc/libs/1_62_0/libs/multi_array/doc/user.html
// 
// On Mac/Linux/UNIX compile with:
// g++ -std=c++11  TDFDcube.cpp -o TDFDcube
// 
// NOTE: You must have Boost installed!
//
// keithjmiklas@gmail.com
//

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "boost/multi_array.hpp"

int main() {
  // Create a 3D array that is 3 x 5 x 4
  typedef boost::multi_array<double, 3> array_type;
  typedef array_type::index index;
  array_type Bx(boost::extents[3][5][4]);

  // Assign values to the elements
  int values = 0;
  for(index i = 0; i != 3; ++i) 
    for(index j = 0; j != 5; ++j)
      for(index k = 0; k != 4; ++k)
        Bx[i][j][k] = values++;

  // Print values
  for(index i = 0; i != 3; ++i) {
  	std::cout << "Rectangular prism slice " << i << ":" << std::endl;
    for(index j = 0; j != 5; ++j)
      	std::cout << Bx[i][j][0] << '\t' << Bx[i][j][1] << '\t' << Bx[i][j][2] << '\t' << Bx[i][j][3] << std::endl;
	std::cout << std::endl;
	}

	std::cout << "Simple performance test. Assign prism values 1,000,000 times, and clock it." << std::endl;
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (long int a = 0; a < 1000000; ++a) {
		values = 0;
		for(index i = 0; i != 3; ++i) 
			for(index j = 0; j != 5; ++j)
				for(index k = 0; k != 4; ++k)
					Bx[i][j][k] = values++;
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	std::cout << "It took " << time_span.count() << " seconds." << std::endl;

	std::cout << "\n";
	return 0;
}


/* OUTPUT
=========

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

*/
