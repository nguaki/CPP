//June 5, 2018
//() operator overloading.
#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int j){ _i = j; }
		void vDisp(){ cout << _i << endl; }
		S operator()( int j ){ _i = j; return *this; } //return is needed for (S1()).vDisp() to work.
		void operator()( int j ){ _i = j; }
};

int
main()
{
	S S1(50);

	S1.vDisp();

	(S1(30)).vDisp();  //Calls () overload function.
	S1.vDisp();

	return 0;
} 
