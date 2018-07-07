//Sep 5, 2016
//Demonstrates pair DS.
//Creates variable name and inputs data directly.
//Demonstrates the usage of the property names 'first' and 'second'.
//
//Output:
//Matthew:100
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int
main()
{
    pair<string,int> paGrades("Matthew", 100);
 
    //Matthew:100
   
    cout << paGrades.first << ":"  << paGrades.second << endl;
    
    return 0;
}