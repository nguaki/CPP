////////////////////////////////////////////////////////////////////////////////
//June 7, 2018
//Overloading generic functions using different signatures of templates.
//
//OUTPUT
//You are    24
//You are
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

template<typename T>void vTellMeSomething(T t)
{
	cout << t << endl;
}

template<typename T1, typename T2>void vTellMeSomething(T1 t1, T2 t2)
{
	cout << t1 << "    " << t2 << endl;
}

int
main(void)
{
	vTellMeSomething( "You are", 24 );
	vTellMeSomething( "You are" );
}
