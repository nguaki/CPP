#include <iostream>
#include <string>

using namespace std;

class S{
	int _i;

	public:
		S(int i){ _i = i; }
		friend void operator+= (S &s, int j);
		friend void operator-= (S &s, int j);
		void vDisp(){ cout << _i << endl; }
};

void operator+= (S &s, int j)
{
	s._i += j;
}

void operator-= (S &s, int j)
{
	s._i -= j;
}

int
main()
{
	S S1(10);

	S1 += 5;
	S1.vDisp(); 

	S1 -= 5;
	S1.vDisp(); 

	return 0;
};
