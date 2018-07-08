////////////////////////////////////////////////////////////////////////////////
//June 7, 2019
//General function overloading.
//
//OUTPUT
//100
//Fdjskjfls
//100.123
//
//Jul 7, 18   Usage of specific template.
//            Again, this defeats the purpose of general template concept.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <typename T>void vShowMe(T t );
template <>void vShowMe<int>(int i );   //This will work with another vShowMe() generic function.

int
main(void)
{
	vShowMe( 100 );
	vShowMe( "Fdjskjfls" );
	vShowMe( 100.12345 );

	return 0;
}

template <typename T>void vShowMe(T t )
{
	cout << t << endl;
}
template <>void vShowMe<int>(int i )
{
	cout << i << endl;
}
