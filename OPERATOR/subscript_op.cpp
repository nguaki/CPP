//June 5,18
//Subscript operator overload.
#include <iostream>
#include <string>
using namespace std;

class S{
	int _i[3];
	public:
		S(int i, int j, int k ){ _i[0] = i; _i[1] = j; _i[2] = k; };
		int operator[]( int iIndex ){ return _i[iIndex]; }
};

int
main()
{
	S S1(5,10,15);

	cout << S1[1] << endl;  //This utilizes subscript operator overload.
	return 0;
}
