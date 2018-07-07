//Oct 5, 2016
//
//OUTPUT
//needle
//in a haystack
//a pin in a haystack

// Demonstrates string commands: find(), substr(), replace().
#include <iostream>

using namespace std;

int
main()
{
    string s1 = "a needle in a haystack";
    string word = "needle";
    
    //Returns the nth position of the word in the string.
    int iPos = s1.find(word);
    
     //Returns the substr of a string from iPos to the length.
    string s2 = s1.substr( iPos, word.length());
    
    //Returns the substr starting from a position to the end of the string.
    string s3 = s1.substr( iPos + word.length() + 1);
    
    cout << s2 << endl;
    cout << s3 << endl;
    
    //Replaces 'needle' with 'pin'.
    s1.replace( iPos, word.length(), "pin");  //<== specifies word position to be replaced.
    //s1.replace( "needle", "pin");    <== doesn't compile.  although this makes a perfect sense.
    
    cout << s1 << endl;
    
    
    return 0;
}