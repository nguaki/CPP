//PALINDROME: method 1
#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

bool
//////////////////////////////////////////////////////////////////
//Aug 10, 2018
//Note that the reference will fail compiling since there is no
//object in the memory.
//bCheckPalindrome( string &s )
//////////////////////////////////////////////////////////////////
bCheckPalindrome( string s )
{
    if( s == string( s.rbegin(), s.rend() ))
        return true;
    else
        return false;
}

int
main(void)
{
    string s;
    
    assert( bCheckPalindrome("abcba") == true );
    assert( bCheckPalindrome("abcb") == false );
    assert( bCheckPalindrome("abababa") == true );
    assert( bCheckPalindrome("") == true );
    assert( bCheckPalindrome("a") == true );
    
    return 0;
}
    
    
    