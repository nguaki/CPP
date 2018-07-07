// June 7, 18
// Explanation of namespace.
//
// Output:
//From namespace 1.
//From namespace 2.
//
#include <iostream>
using namespace std;

#include "ns1.cpp"
#include "ns2.cpp"

using namespace std;

int
main(void)
{
	one :: vDisp();   //Uses scope resolution operator. This does not cause compilation error. Although the function
	two :: vDisp();   //names are same.

	return 0;
}
