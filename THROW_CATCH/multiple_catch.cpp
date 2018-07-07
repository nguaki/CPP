//Date: June 8, 2018
//Description: Illustrates multiple catch.
//Output:
//        divide by 0
//        Run time eroor
//        Throw integer 20
//        overflow_error
#include <iostream>
#include <stdexcept>

using namespace std; 

int
main(void)
{
	try{
	    //throw "Divide by 0";    //Catch my first catch
	    //throw 20;    //Catch my first catch
        // throw runtime_error ("Run time eroor");  //Catch my 2nd catch.
        throw overflow_error("overflow_error");  //Catch my 3rd catch.
	}
	catch( const char *e){
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
