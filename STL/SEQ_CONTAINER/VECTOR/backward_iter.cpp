////////////////////////////////////////////////////////////////////////////////
// Oct 6, 2016
//
// Uses vector<>  to contain data.
// Uses vector variable to print the data.
// And also uses iterator(forward and backward) to print the data.
//
//1  2  3  4  5  6  
//1  2  3  4  5  6  
//1  2  3  4  5  6  
//6  5  4  3  2  1  
//6  5  4  3  2  1
//
//3 ways of printing out values:
//(1) Use array index
//(2) For loop
//(3) While loop
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    vector<int>  vecValues;
    
    vecValues.push_back(1);
    vecValues.push_back(2);
    vecValues.push_back(3);
    vecValues.push_back(4);
    vecValues.push_back(5);
    vecValues.push_back(6);
    
    //print using vector variable as array.
    for(int i=0; i<vecValues.size(); i++){
        cout << vecValues[i] << "  ";
    }
    cout << endl;
    
    vector<int>::iterator itValues = vecValues.begin();
    
    //Print using iterator for loop(). Printing as a dereference value.
    for( ; itValues != vecValues.end(); itValues++){
        cout << *itValues << "  ";
    }
    cout << endl;
    
    
    itValues = vecValues.begin();
    //Print using iterator while() loop().
    while( itValues != vecValues.end() )
    {
        cout << *itValues << "  ";
        itValues++;
    }
    cout << endl;
    
    //rbegin() refers to the end of vector.
    vector<int>::reverse_iterator ritValues = vecValues.rbegin();
    
    //Print using reverse iterator for() loop().
    for( ; ritValues != vecValues.rend(); ritValues++){
        cout << *ritValues << "  ";
    }
    cout << endl;
    
    ritValues = vecValues.rbegin();
    
    //rend() refers to the beginning of vector.
    //Print using reverse iterator while() loop().
    while( ritValues != vecValues.rend()){
        
        cout << *ritValues << "  ";
        ritValues++;
    }
   
    return 0;
}