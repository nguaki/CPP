//June 4, 2018
//friend allows to see see private members.
//OUTPUT: 200
#include <iostream>
#include <string>

using namespace std;
class faculty;   //forward declaration

class student{
	int iScore;

	public: void vDispScore(){ cout << iScore << endl;};

	void vSet(int i ){ iScore = i; }
	friend faculty objAdd( student &s1, faculty &f1 );
};

class faculty{
	int iScore;

	public: void vDispScore(){ cout << iScore << endl; }

	void vSet(int i ){ iScore = i; }
	friend faculty objAdd( student &s1, faculty &f1 );
};

faculty objAdd( student &s1, faculty &f1 )
{
	faculty fTemp;
	fTemp.iScore = s1.iScore + f1.iScore;

	return fTemp;
}	


int
main()
{
	student s;
	faculty f;

	s.vSet(100);
	f.vSet(100);

	faculty t;
	t = objAdd( s, f);
	t.vDispScore();

	return 0;
}
