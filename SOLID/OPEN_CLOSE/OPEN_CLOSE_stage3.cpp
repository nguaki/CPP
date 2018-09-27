//Sep 5, 2018  -  This is truly a beauty of OO.
//                setting up such that a new requirement won't alter any
//                existing code.
#include <iostream>
#include <vector>

using namespace std;

class IEmployee1{
	public:
	virtual int iCalBonus( const unsigned int iAmt ) = 0; 
};

class Employee : public IEmployee1 {
	int    _id;
	string _sName;

	public:
		Employee(int id, string sName ){ _id = id; _sName = sName; }
		int iGetID() const { return _id; }
		string sGetName() const { return _sName; }
};

//Note that this was never touched with new requirement.
//So there is no need to test this class.
class Permanent : public Employee{
	
	public:
		Permanent(int id, string sName ):Employee(id,sName){};
		int iCalBonus( const unsigned int iAmt ){ return iAmt * 0.6; }
};
	
//This new class was added.
class Temp : public Employee{
		
		public:
			Temp(int id, string sName ):Employee(id,sName){} 
			int iCalBonus( const unsigned int iAmt ){ return iAmt * 0.3; } 
};

int
main(void)
{
	//When instatiating an object which derives an abstract class,
	//need to instatiate with new operator which is run time binding.
	//Below is compile time binding and it static binding doesn't work
	//when instatiating an object which derives an abstract class.
	//Employee objEmp1(1, "Mike" );
	//Employee objEmp2(2, "Jill" );
	
	Employee *objEmp1 = new Permanent(1, "Mike" );
	Employee *objEmp2 = new Temp(2, "Jill" );
	

	cout << objEmp1->iGetID() 
	     << "   " 
	     << objEmp1->sGetName() 
	     << "  " 
	     << objEmp1->iCalBonus(5000) 
	     << endl;

	cout << objEmp2->iGetID() 
	     << "   " 
	     << objEmp2->sGetName() 
	     << "  " 
	     << objEmp2->iCalBonus(5000) 
	     << endl;

	return 0;
}
