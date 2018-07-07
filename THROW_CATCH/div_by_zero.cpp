//Date: June 8, 18
//Description: Exception handling for div by zero.
//Output:
//        Div by zero error
//
//       If try{} block is ommitted, the following compilation error has occurred:
//       expected primary-expression before ‘catch’
#include <iostream>
#include <exception>

using namespace std; 

int
main(void)
{
	int a = 10, b = 0;
	int c;

	try{
		if( b== 0 ) throw("Div by zero error"); //This jumps to catch().
		c = a/b;

		cout << c << endl;
	}
	catch( const char *e )
	{
		cout << e << endl;
	}

	return 0;
}
