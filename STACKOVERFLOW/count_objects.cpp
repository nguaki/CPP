//Date: June 7, 18
//Description: Counts number of objects that were created.
//Output: 
//1
//2
//3

#include <iostream>
using namespace std; 

class M
{
	public:
		static int iCnt;
		M(){ iCnt++; }
		int iRetNumOfObj(){ return iCnt; }
};

int M::iCnt = 0;


int
main(void)
{
	M m1;
	cout << m1.iRetNumOfObj() << endl;

	M m2;
	cout << m2.iRetNumOfObj() << endl;

	M m3;
	cout << m3.iRetNumOfObj() << endl;

	return 0;
}
