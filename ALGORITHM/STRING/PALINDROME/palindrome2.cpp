//PALINDROME: method 2
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
//
//This is 50% clever since it can run 50% faster.
//How does it work?
// (s.begin(), s.begin()/2  will compare only the half string.
// s.rbegin() will start another string from the reverse.
// Just need to get used to the function call.
//////////////////////////////////////////////////////////////////
bCheckPalindrome( string s )
{
    //Note that only half of the string needs to be checked if
    //a string is a palindrome.
    if( equal( s.begin(), s.begin()+s.size()/2, s.rbegin()))
        return true;
    else
        return false;
}

int
main(void)
{
    
    assert( bCheckPalindrome("abcba") == true );
    assert( bCheckPalindrome("abcb") == false );
    assert( bCheckPalindrome("abababa") == true );
    assert( bCheckPalindrome("") == true );
    assert( bCheckPalindrome("a") == true );
    
    return 0;
}