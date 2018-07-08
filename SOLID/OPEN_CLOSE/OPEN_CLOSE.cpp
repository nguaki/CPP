//Note that previous code was never touched.
#include <iostream>
#include <vector>

using namespace std;

class IEmployee1{
	public:
	virtual int iCalBonus( const unsigned int iAmt ) = 0; 
};

class IEmployee2{
	public:
	virtual int iMinSalary() = 0;
};

class Employee : public IEmployee1, public IEmployee2{
	int    _id;
	string _sName;

	public:
		Employee(int id, string sName ){ _id = id; _sName = sName; }
		int iGetID() const { return _id; }
		string sGetName() const { return _sName; }
};

class Permanent : public Employee{
	
	public:
		Permanent(int id, string sName ):Employee(id,sName){};
		int iCalBonus( const unsigned int iAmt ){ return iAmt * 0.6; }
		int iMinSalary(){ return 5000; }
};
	
class Temp : public Employee{
		
		public:
			Temp(int id, string sName ):Employee(id,sName){}
			int iCalBonus( const unsigned int iAmt ){ return iAmt * 0.3; }
			int iMinSalary(){ return 1000; }
};

class Contract : public IEmployee2{
	int    _id;
	string _sName;

	public:
		Contract(int id, string sName ){ _id = id; _sName = sName; }
		int iGetID() const { return _id; }
		string sGetName() const { return _sName; }
		int iMinSalary(){ return 4000; }
};

int
main(void)
{
	vector<Employee *> Employees;
	Employees.push_back( new  Permanent(1, "Mike" ));
	Employees.push_back( new  Temp(2, "Jill" ));
	
	
	
	auto it = Employees.begin();
	while( it != Employees.end() ){
		cout << (*it)->iGetID() 
			 << "   " 
			 <<  (*it)->sGetName() 
			 << "   " 
			 << (*it)->iMinSalary() 
			 << "   "  
			 << (*it)->iCalBonus(5000) 
			 << endl;
		it++;
	}
		
	vector<Employee *> Employees2;
	Employees2.push_back( new  Permanent(1, "Mike" ));
	Employees2.push_back( new  Temp(2, "Jill" ));
	Employees2.push_back( new  Temp(3, "George" ));
	
	auto it2 = Employees2.begin();
	while( it2 != Employees2.end() ){
		cout << (*it2)->iGetID() 
			 << "   " 
			 <<  (*it2)->sGetName() 
			 << "   " 
			 << (*it2)->iMinSalary() 
			 << "   "  
			 << endl;
		it2++;
	}
	return 0;
}
