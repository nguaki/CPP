//June 5, 2018
//Overloading new and delete operators.
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Student{
	string sName;
	int    iAge;
	int    iAge1;
	int    iSib;
	public:
		Student(){ sName = "NoName"; iAge = 0; }
		Student( string s, int i ){ sName = s; iAge = i; }
		void vDisp(){ cout << sName << "  " << iAge << endl;}
		//Note that compiler sends in the size by computing the size of bytes
		//of members.	
		void *operator new( size_t size ){
			void *pointer;	
			cout << "Allocating " << size << "memory." << endl;	
			pointer = malloc(size);
			if(!pointer)
			{
				bad_alloc ba;
				throw ba;
			}	
			return pointer;
		}
		void operator delete( void *s ){
			cout << "Deleting memory." << endl;	
			free(s);
		}
};

int
main(void)
{
	Student *s;

	s = new Student("Angela", 56 );

	try{
		s->vDisp();
		delete(s);
	}catch(bad_alloc ba ){
		cout << ba.what() << endl;
	}
}
