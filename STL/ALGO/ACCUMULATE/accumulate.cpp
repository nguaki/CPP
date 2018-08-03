///////////////////////////////////////////////////////////////////////////////
// Oct 6, 2016
//
// DESCRIPTION:
// uses accumulate() algorithm function to add all numbers for vector<int>
// and concatenate for all strings for vector<string>.
//
// accumulate() is an overloading algorithm function which can take any types.
//
// OUTPUT:
//SUM is: 55                                                                                                               
//Result string:amanaplanacanalpananma        
//
// June 20, 2018      Added comments.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int
main()
{
    vector<int> vecNumbers;
    
    for( int i=0; i<= 10; i++){
        
        vecNumbers.push_back(i);
    }
    
    //Note that the third parameter is initialization.
    int iSum = accumulate( vecNumbers.begin(), vecNumbers.end(), 0);
    
    cout << "SUM is: " << iSum << endl;
    
    vector<string> vecString;
    
    vecString.push_back("a");
    vecString.push_back("man");
    vecString.push_back("a");
    vecString.push_back("plan");
    vecString.push_back("a");
    vecString.push_back("canal");
    vecString.push_back("pananma");
    
    string sString = accumulate( vecString.begin(), vecString.end(), string(""));
    cout << "Result string:" << sString << endl;
    
    return 0;
}