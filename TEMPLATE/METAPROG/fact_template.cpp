/////////////////////////////////////////////////////////////////////////////////
//Jun 21, 2018
//
//Demonstration of template meta programming.
//Supposedly all the calculation is done during the compile time.
//Thus the execution supposedly very fast.
//
//OUTPUT:
//2 6 24 120 
//
//Jun 21, 2018            Usage of keyword auto caused 'value' does not name
//                        a type.  I don't get it.
//                        Must compile with -std=c++11 option.
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <utility>
#include <cassert>
using namespace std;

template <size_t n> struct fact;

template<>
struct fact<0>{
	//const static int value = 1;
	const static auto value = 1;
};

template <size_t n>
struct fact{
	//const static int value = n * fact<n-1>::value;
	const static auto value = n * fact<n-1>::value;
};

int
main(void)
{
	cout << fact<2>::value << ' '
	     << fact<3>::value << ' '
	     << fact<4>::value << ' '
             << fact<5>::value << endl;

	assert(fact<5>::value == 120);

	return 0;
}