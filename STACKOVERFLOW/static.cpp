//June 4, 2018
//Without the declaration of int X::ix below, there will be undefined reference to `X::ix'
//Treat class like typedef. If there is no variable from typedef, no variables can be used.
#include <iostream>

using namespace std;

class X{
	//static int ix = 0; //forbids in-class initialization of non-const static member ‘X::ix’
	static int ix; 

	public:
	static int iGet(){ return ix; }
	static void vSet(int i){ ix = i; };
};
int X::ix;   //Very important since class is only a signature. No variable was instantiated.

int
main()
{
	//X::ix = 0;    //Cannot set private variable.
	//:int X::ix = 0;
	X::vSet(3);
	cout << X::iGet() << endl;

	return 0;
}
