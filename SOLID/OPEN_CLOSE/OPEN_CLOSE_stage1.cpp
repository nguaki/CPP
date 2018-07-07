#include <iostream>
#include <vector>

using namespace std;

class Employee {
	int    _id;
	string _sName;

	public:
		Employee(int id, string sName ){ _id = id; _sName = sName; }
		int iGetID() const { return _id; }
		string sGetName() const { return _sName; }
		int iCalBonus( const unsigned int iAmt ){ return iAmt * 0.6; }
};

int
main(void)
{
	Employee objEmp1(1, "Mike");
 
	cout << objEmp1.iGetID() 
	     << "   " 
	     << objEmp1.sGetName() 
	     << "  " 
	     << objEmp1.iCalBonus(5000) 
	     << endl;

	return 0;
}
