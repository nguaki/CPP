//June 7, 2018
//Demonstrates explicit declaration of class template.
#include <iostream>

using namespace std;

template <class T> class S
{
	T t;

	public:
	S(T t){ this->t = t; }
	void vDisp(){ cout << t << endl; }
};

template <> class S<int>  //Weird syntax.
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
	S<int>	  s2(17);

	s1.vDisp();
	s2.vDisp();

	return 0;	
}
