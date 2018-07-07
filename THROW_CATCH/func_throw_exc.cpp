//Date: June 8, 2018
//Description: Illustrates function throwing exception.
//Output:
//Throw integer  20
//c
//RUNTIME_ERROR
#include <iostream>
#include <stdexcept>

using namespace std; 

void test() throw( char, int, runtime_error)
{
	//throw 20;
	//throw 'c';
	throw runtime_error("RUNTIME_ERROR");
}
int
main(void)
{
	try{
        test();
	}
	catch( const char e){
		cout << e << endl;
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
