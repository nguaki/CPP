////////////////////////////////////////////////////////////////////////////////
//June 7, 2018
//Demonstrates the ability to assign default parameters to template class.
//
//OUTPUT
//Matthew   17
//6.2   17
//17   Matthew
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//If no type is defined, T is of type string and Y is of type int.
////////////////////////////////////////////////////////////////////////////////
template <class T = string, class Y = int>
class S
{
	T t1;
	Y y1;

	public:
	S(T t, Y y){ this->t1 = t; this->y1 = y; }
	void vDisp(){ cout << t1 << "   " << y1 << endl; }
};

int
main(void)
{
	S<>	s1( "Matthew", 17 );
	S<float, int> s2( 6.2, 17 );
	S<int, string> s3( 17, "Matthew" );

	s1.vDisp();
	s2.vDisp();
	s3.vDisp();

	return 0;
}