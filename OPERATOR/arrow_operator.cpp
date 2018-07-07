//Magical arrow operator overload.
//June 5, 2018
#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int j){ _i = j; }
		void vDisp(){ cout << _i << endl; }
		S *operator->(){ return this; } //Returns the address of the object.
};

int
main()
{
	S S1(40);

	S1.vDisp();

	S1->vDisp();

	return 0;
}
