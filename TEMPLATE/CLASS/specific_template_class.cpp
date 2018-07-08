///////////////////////////////////////////////////////////////////////////////
//June 7, 2018
//Demonstrates explicit declaration of class template.
//
//OUTPUT:
//Matthew
//17
//
//Jul 7,18    Specific declaration of class really defeats the purpose of 
//            template
//////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <class T> class S
{
	T t;

	public:
	S(T t){ this->t = t; }
	void vDisp(){ cout << t << endl; }
};

//Specific template class.
template <> class S<int>  
{
	int t;

	public:
	S(int t){ this->t = t; }
	void vDisp(){ cout << t << endl; }
};

int
main(void)
{
	S<string> s1("Matthew");
	S<int>	  s2(17); //This will use latter class.

	s1.vDisp();
	s2.vDisp();

	return 0;	
}