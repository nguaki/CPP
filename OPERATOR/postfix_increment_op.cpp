// June 5, 18
// Postfix increment/decrement operator overloading.
//
//  
#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int i){ _i = i; }
		//There should be an arguement for this to
                //be recognized as a postfix increment.
		//Note that arguement is never used but it is important to leave it
		//like this since this forces the compiler to recognize it as a
		//post increment.
                S operator++ ( int i )
		{ 
			S duplicate(*this);
			_i++; 
			return duplicate;   //Note this is returning this object.
		};
		friend S operator-- (S &s, int i);
		void vDisp(){ cout << _i << endl; }
};

//This is a friend version of postfix decrement.
//Note that there should be second arguement in order for this 
//to be recognized as a postfix(not prefix) decrement.
//Note that second arguement is never used but it is important to leave it
//like this since this forces the compiler to recognize it as a
//post decrement.
S operator-- (S &s, int i)
{
	S duplicate(s);
	s._i -= 1;
	return duplicate;
}

int
main()
{
	S S1(10);

	(S1--).vDisp(); //Expect 10.
	S1.vDisp();     //Expect 9.

	(S1++).vDisp(); //Expect 10.
	S1.vDisp();     //Expect 11.

	return 0;
};
