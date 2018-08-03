//////////////////////////////////////////////////////////////////////////
//Sep 26, 16
//
// Demonstration of map data structure.
// Map is an associative array (key, value) where 
// key and value types can be different,
// 
// Functions used : size(), erase()
//
//
//matthew:100
//size:4
//size:3
//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>

using namespace std;

int
main()
{
    map<string,int> mpGrades;
    
    mpGrades["matthew"] = 100;
    mpGrades["che"] = 100;
    mpGrades["angela"] = 100;
    mpGrades["kim"] = 100;


    //matthew:100
    cout << "matthew:" << mpGrades["matthew"] << endl;
    
    //size:4
    cout << "size:" << mpGrades.size() << endl;
    
    mpGrades.erase("kim");  //Great erase() method.

    //size:3
    cout << "size:" << mpGrades.size() << endl;
    
    return 0;
}