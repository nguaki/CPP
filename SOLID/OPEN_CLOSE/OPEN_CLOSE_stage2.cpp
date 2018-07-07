//Lets suppose a new requirement came in.
//The requirement is for temp temployee.
//The bonuse is 0.4.
//This additional write violates the OPEN_CLOSE principle.
//
#include <iostream>
#include <vector>

using namespace std;

class Employee {
	int    _id;
	string _sName;
	string _sType;

	public:
		Employee(int id, string sName, string sType ){ _id = id; _sName = sName; _sType = sType; }
		int iGetID() const { return _id; }
		string sGetName() const { return _sName; }
		//////////////////////////////////////////////////
		//This part was rewritten.
		//This would require retest.
		//Who knows this will be rewritten again.
		//////////////////////////////////////////////////
		int iCalBonus( const unsigned int iAmt ){      
			if( _sType == "Permanent" ) return iAmt * 0.3; 
			else return iAmt * 0.2;
		}
};

int
main(void)
{
	//had to rewrite the object parameters.
	Employee Mike(1, "Mike", "Permanent" );
	Employee Jill(1, "Jill", "Temp" );
	
	cout << Mike.iGetID() 
	     << "   " 
	     << Mike.sGetName() 
	     << "  " 
	     << Mike.iCalBonus(5000) 
	     << endl;
	
	cout << Jill.iGetID() 
	     << "   " 
	     << Jill.sGetName() 
	     << "  " 
	     << Jill.iCalBonus(5000) 
	     << endl;
	
	return 0;
}
