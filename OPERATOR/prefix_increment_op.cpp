// June 5, 18
// Prefix increment/decrement operator overloading.
//
//  
#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int i){ _i = i; }
		//There should not be any arguements for this to
                //be recognized as a prefix increment.
                S operator++ ()
		{ 
			_i--; 
			return *this;   //Note this is returning this object.
		};
		friend S operator-- (S &s);
		void vDisp(){ cout << _i << endl; }
};

//This is a friend version of prefix decrement.
//Note that there should not be second arguement in order for this 
//to be recognized as prefix(not postfix) decrement.
S operator-- (S &s)
{
	s._i -= 1;
	return s;
}

int
main()
{
	S S1(10);

	(--S1).vDisp(); //Expect 9.
	S1.vDisp();     //Expect 9.

	(++S1).vDisp(); //Expect 10.
	S1.vDisp();     //Expect 10.

	return 0;
};
