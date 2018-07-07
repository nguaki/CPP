//June 7, 2018
//Example of anonymouse namespace.
//Not sure what is the real world usage but this acts as if 
//it is a part of main().
//OUTPUT
//Hello there X= 
//10
#include <iostream>

using namespace std;

namespace{
	int x;
	void vDisp(){
		cout << "Hello there X= \n" << x << endl;
	}
}

int
main(void)
{
	x = 10;
	vDisp();

	return 0;
}
