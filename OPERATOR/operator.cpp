// June 4, 2018
// operator overloading function.
// 

#include <iostream>
#include <string>

using namespace std;

class S{
		int _i;
	public:
		S(){};
		S(int i ){ _i = i; }
		S operator+ (S &s);
		void vDisp(){ cout << _i << endl; }
};	

S S::operator+ ( S &s )
{
    S objS;

    objS._i = _i + s._i;

    return objS;
}

int
main()
{
	S S1(45), S2(55), S3;

	S3 = S1 + S2;

	S3.vDisp();
}
