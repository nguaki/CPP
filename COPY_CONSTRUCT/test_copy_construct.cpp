/////////////////////////////////////////////////////////////////////////////////
//June  20, 2018
//
//PURPOSE:
//Demonstrates that copy constructor is invoked when an object is called by value.
//Demonstrates that copy constructor is invoked when an object is returned by value.
//
//OUTPUT:
//Calling copy constructor
//Calling copy constructor
//Calling copy constructor
//10
///////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

class A
{	
	int i;

	public:
	
		A(){};
		A(int i){ this->i = i;}

		A( const A &a )
		{
			cout << "Calling copy constructor" << endl;
			this->i = a.i;
		}
		////////////////////////////////////////////////////////////
		//Receiving an object by value will call copy constructor.
		//Sending an object by value will call copy constructor.
		//Note that if declaration is
		// A& operator + ( A const &a )
		//where both receiving and sending is by reference, the copy
		//constructor is not called.
		////////////////////////////////////////////////////////////
		A operator + ( A const a ) 
		{
			i = i + a.i;
			return *this;  //June 20, 18  Why didn't this trigger a copy constructor?
		}
		void vPrint(){ cout << i << endl; }
};

int
main(void)
{
	A a(5), b(a), c;  //Note that b(a) also calls copy constructor.

	c = a + b;
	c.vPrint();
}
