//Oct 6, 16
//
// Uses template allowing multiple types as a parameter.
//
//11  <== int comparison
//11  <== double comparison
//XYZ <== string comp
#include <iostream>
#include <string>
using namespace std;

//The input parameters can be of any type.
template <typename T>
T max( T &value1, T &value2)
{
    //if( value1 > value2) return value1;
    //else return value2;
    
    return ( value1 > value2) ? value1:value2;
}

int
main()
{
    int    iX=10,     iY=11;
    double dX= 10.0,  dY=11.0;
    string sX= "ABC", sY="XYZ";
    
    cout << max(iX,iY) << endl;
    cout << max(dX,dY) << endl;
    cout << max(sX,sY) << endl;
    
    return 0;
}