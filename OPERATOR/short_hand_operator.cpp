#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int i){ _i = i; }
		void operator+= (int j){ _i = _i + j; }
		void operator-= (int j){ _i = _i - j; }
		void vDisp(){ cout << _i << endl; }
};

int
main()
{
	S S1(10);

	S1 += 5;
	S1.vDisp(); 

	S1 -= 5;
	S1.vDisp(); 

	return 0;
};
