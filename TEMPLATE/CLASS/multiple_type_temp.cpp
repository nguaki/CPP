////////////////////////////////////////////////////////////////////
//July 1, 18
//
//Demonstration of multiple types in a generic class.
//
//
//James  53
//17  22
////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <class T, class Y>
class S{
	T t1;
	Y y1;

	public:
		S(T t1, Y y1){ this->t1=t1; this->y1=y1; }
		void vDisp(){ cout << t1 << "  " << y1 << endl;}
};

int
main(void)
{
	S<string, int> s("James", 53);
	S<int, int>    m(17, 22);

	s.vDisp();
	m.vDisp();

	return 0;
}