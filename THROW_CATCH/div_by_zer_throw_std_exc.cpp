//Date: June 8, 18
//Description: Usage of stdexcept header to throw standard exceptions.
//Output: Div by zero
//   Following are legit exceptions:
//                       bad_allod
//                       bad_cast
//                       logic_failure
//                       bad_typeid
//                       bad_exception
//                       runtime_error
//                       domain_error
//                       invalid_argument
//                       length_error
//                       out_of_range
//                       overflow_error
//                       range_error
//                       underflow_error
//
#include <iostream>
#include <stdexcept>
//#include <exception>   //Note that stdexcept includes exception header file.
using namespace std; 

int
main(void)
{
	int a,b,c;

	a = 10;
	b = 0;

	try{
	
		if( b==0 )  throw runtime_error("Div by zero");
		c = a/b;

		cout << c << endl;
	}catch( runtime_error e ){
		cout << e.what() << endl;
	}

	return 0;
}
