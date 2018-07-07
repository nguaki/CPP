////////////////////////////////////////////////////////////////
//
// June 20, 18
//
// Demonstrates ability to send multiple types to a function.
// Demonstrates amazing flexibility of a template function.
//
//OUTPUT
//12
//12.1234
//
//July 7, 18    Note that there is no need to do this: max<int,int>(5,6);
//              This will cause compilation error.
//
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

//The input parameters can be of any type.
//The ability to compare two different types of values.
template <typename T, typename U>
T max( T &value1, U &value2)
{
    //if( value1 > value2) return value1;
    //else return value2;
    
    return ( value1 > value2) ? value1:value2;
}

int
main()
{
    int    iX=10,     iY=11;
    double dX= 12.1234,  dY=12.567;

    cout << max(iX,dY) << endl;  //return value is integer
    cout << max(dX,iY) << endl;  //return value is double
    
    //Following lines will cause compilation errors.
    //cout << max<int,int>(iX,dY) << endl;  //return value is integer
    //cout << max<double,double>(dX,iY) << endl;  //return value is double

    return 0;
}