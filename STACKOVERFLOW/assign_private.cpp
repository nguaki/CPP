//June 2, 2018
//
//Describes how a function is used to assign a private variable.
//
// OUTPUT: 50
#include <iostream>
#include <cstdio>

class X{
	public:
	int &AssignMe()
	{
		return iIamPrivate;
	}
	void vPrintMe()
	{
		printf( "%d\n", iIamPrivate );	
	}
	private:
		int iIamPrivate;
};

int
main()
{
	X objX;

	objX.AssignMe() = 50;  //Returns the address of iIamPrivate variable.
			       //Assigns 50 to this variable.
	objX.vPrintMe();

	return 0;
}
