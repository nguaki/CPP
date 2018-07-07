//June 7, 2018
//Example of nested anonymous namesapce.
//OUTPUT: 20
#include <iostream>

using namespace std;

namespace{
	int iX = 10;

	namespace A{
		void vDisplay(){ cout << iX << endl; }  //Has an access to outer namespace.
	};
};

int
main(void)
{
	iX = 20; //Anonymous variable does not need scope resolution operator.

	A::vDisplay();//Inner namespace has a name.

	return 0;
}
