// June 5, 18
// This shows the problem of equal assignment of objects whose member needs
// to allocate memory.  In this case, sName had to allocate memory.
//
//Anil  25    <--- s obj
//Anil  25    <--- m obj (after m=s)
//James  53   <--- s obj after modification
//James  25    <--- Here is the problem. m obj has its member data altered.
//                  This should have been Anil 25 like the previous episode. 
//
// Here is the reason:
// S
// [ sName ]  --> [Anil]0XAA
// [ 25    ]
// M
// [ sName ]  --> [    ]0XAA  M.sName points at the same memory address as S.sName
// [       ]
//
// June 20, 2018  ~S(){ delete sName; }   This causes seg fault which means it 
//                already got deallocated. But where?

#include <iostream>
#include <string>

using namespace std;

class S{
	string *sName;
	int    iAge;

	public:
		S(){};
		S( string s, int i )
		{ 
			sName = new string(s); //Allocated memory.
			iAge = i;
			
		}
		void vModify( string s, int i )
		{ 
			*sName = s; 
			iAge = i; 
		}
		void vDisp(){ cout << *sName << "  " << iAge << endl; }
		//~S(){ delete sName; }   This causes seg fault which means it already got deallocated. But where?
};

int
main()
{
	S s( "Anil", 25 ), m;
	
	m = s;

	s.vDisp();
	m.vDisp();

	s.vModify( "James", 53 );

	s.vDisp();
	m.vDisp();
	
	return 0;
}
