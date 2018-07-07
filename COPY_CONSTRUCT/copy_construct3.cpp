// June 5, 18
// This episode gets rid of the episode 2 problem.
//
//djajflff
//copy constructor
//Anil  25    <--- s obj
//Anil  25    <--- m obj (Assignment from copy constructor).
//James  53   <--- s obj after modification
//Anil  25    <--- Bingo. The name is left intact.
//
//June 20, 18   The important point is that copy constructor is called
//              at the time of declaration.  If it is called afterwards,
//              the built in assignment operator function is called.
//
#include <iostream>
#include <string>

using namespace std;

class S{

	public:
	string *sName;
	int    iAge;
		S(){};
		S( string s, int i ){ sName = new string(s); iAge = i; } //Allocated memory.
		S(const S &m){ 
		    cout << "copy constructor" << endl;
		     sName = new string(*(m.sName)); 
		     iAge   = m.iAge;
		}
		void vModify( string s, int i ){ *sName = s; iAge = i; }
		void vDisp(){ cout << *sName << "  " << iAge << endl; }
		//~S(){ delete sName; }
};

int
main()
{
	S s( "Anil", 25 );
	cout << "djajflff" << endl;	
	S m = s;  //Copy constructor is called at the time of declaration.

	s.vDisp();
	m.vDisp();

	s.vModify( "James", 53 );

	s.vDisp();
	m.vDisp();
	
	return 0;
}
