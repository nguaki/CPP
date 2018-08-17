//Aug 11, 2018
//Demonstration of array class.
//Advantage: Don't need to count number of elements in an array.
#include <iostream>
#include <array>
using namespace std;

int
main(void)
{
    array<int,3> aInt = { 10, 20 , 30 };
    array<string,3> aString = { "Hello", "World" , "I am not done yet" };
    
    for( int i = 0; i<aInt.size(); i++ )
        cout << aInt[i] << endl;
    for( int i = 0; i<aString.size(); i++ )
        cout << aString[i] << endl;
        
    return 0;
}