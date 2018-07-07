// Sep 29, 2016
//
//Hello 
//Hello 
//**********
//We are the world
//Hello world
//we are children
//
//Demonstration of string assignment and concatenation.
//
#include <iostream>
#include <string>

using namespace std;

int
main()
{
    string s0;
    
    //4 ways of initiating a string.
    string s1 = "Hello ";
    string s2(s1);
    string s3(10, '*');
    string s4("We are the world");
    
    string s5 = s1 + "world"; //concatenation.
    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    
    //string s6 = "we are " + "children".  //Cannot concatenate literal to literal.
    string s7 = "children";
    string s8 = "we are " + s7;
    cout << s8 << endl;
    
    return 0;
}