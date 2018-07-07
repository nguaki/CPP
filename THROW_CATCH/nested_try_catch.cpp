//Date: June 8, 2018
//Description: Illustrates nested try and catch.
//Output:
//     Inner catchDivide by 0
//     Outer catch Divide by 0
#include <iostream>
#include <stdexcept>

using namespace std; 

int
main(void)
{
	try{
	    try{
	    	throw "Divide by 0";    //Catch my first catch
		}catch( const char *e){
			cout << "Inner catch" << e << endl;
			throw 12;
		}
		
	}
	catch( const char *e){
		cout << "Outer catch " << e << endl;
	}
	catch( const int  e){
		cout << "Throw integer  " << e << endl;
	}
	catch( runtime_error e){
		cout << e.what() << endl;
	}
	catch( ... ){
		cout << "Caught another exception." << endl;
	}

	return 0;
}
