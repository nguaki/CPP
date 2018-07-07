// June 5, 18
// This shows that an assignment of an object create separate memory space.
// This is what we want.
// See the next episode.
//
//Anil  25    <--- s obj
//Anil  25    <--- m obj (after m=s)
//James  53   <--- s obj after modification
//Anil  25    <--- m obj is left untouched
#include <iostream>
#include <string>

using namespace std;

class S{
	string sName;
	int    iAge;

	public:
		S(){};
		S( string s, int i ){ sName = s; iAge = i; }
		void vModify( string s, int i ){ sName = s; iAge = i; }
		void vDisp(){ cout << sName << "  " << iAge << endl; }
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
