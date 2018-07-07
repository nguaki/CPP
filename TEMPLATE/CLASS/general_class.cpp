/////////////////////////////////////////////////////////////////////////////////
//June 7, 18
//
//Purpose of template class to reduce the duplication and thus easier to 
//maintain code.
//
//July 7, 18   There is a cost of maintability.  That is weird syntax.
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <class T>
class S
{
	T t1, t2;

	public:
		S(T t1, T t2){ this->t1 = t1; this->t2 = t2; }
		void vShowMe(){ cout << t1 << "  " << t2 << endl; }
};

int
main(void)
{
	S<int>     s1(53, 55);
	S<string>  s2("James", "John");

	s1.vShowMe();
	s2.vShowMe();

	return 0;
}