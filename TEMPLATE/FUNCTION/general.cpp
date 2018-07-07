/////////////////////////////////////////////////////////////////////////////
//June 7, 2018
//An example of general function template.
//
//OUTPUT:
//5
//5.5
//
//Jul 7, 18    Note that there is no need to identify typename when callling
//             a template function.  e.g. No need to do this: tMax<int,int>(5,4).
//             This syntax will cause an error.
//             This is confusing from class declaration.
/////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

//template <typename T>    //Angular bracket goes after template.
template <class T>         //This works also.
T tMax( T a, T b )
{
	T tMax;

	return (a > b) ? a : b;
	//(a > b) ? tMax =  a : tMax =  b;
	//return tMax;
}

int
main(void)
{

	cout << tMax(5,2) << endl;     //Note that there is no need to define the type a function call level.
	cout << tMax(5.5,2.2) << endl;
	return 0;
}