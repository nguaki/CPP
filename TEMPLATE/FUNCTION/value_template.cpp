//////////////////////////////////////////////////////////////////////////
//
//June 21, 2018
//
//Demonstrates a twist with a template function.
//Here a template function is called with a constant value.
//
//OUTPUT:
//Printing
//Printing
//Printing
//Printing
//Printing
//Printing
//Printing
//Printing
//Printing
//Printing
//
//Usually the signature of template to a function is
//     template <typename T> 
// but 
//     template <size_t T>
//
// in this case the type specified.
//
// June 21, 18     This template signature really defeats its purpose
//                 of generalization.  void vPrint( size_t N ) would have
//                 been better solution.
//                 It makes C++ less elegant and makes it more confusing.
//                 <> happens during compile time. But what is the big deal?
// Jul 7, 18       This also adds confusion of calling a templated function.
//                 Usually, there is no need for function<type>(4,5).
//                 In this case,  function<45>(); syntax is needed.
//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <size_t NUM_OF_COPIES>
void vPrint()
{
	for( int i=0; i<NUM_OF_COPIES; i++ )
		cout << "Printing\n";
}

int
main(void)
{
	vPrint<10>();
	return 0;
}
