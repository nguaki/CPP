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
//
//Aug 31, 18     let s=abcba
//               string( s.rbegin(), s.rend()) will return
//               a string which is a reverse.  In this case
//               'abcba'.
//               string object to string object equality check
//               is an overload == operator which is legal in C++.
//               Very condensed line but gets the job done.
//////////////////////////////////////////////////////////////////
bCheckPalindrome( string s )
{
    if( s == string( s.rbegin(), s.rend() ))
        return true;
    else
        return false;
}
bool
bCheckPalindrome2( string s )
{
    if( equal( s.begin(), s.end(), s.rbegin()))
        return true;
    else
        return false;
}
/*
this won't work.
It sounds logical but reverse() doesn't return anything.
it stores the output back to the string.
bool
bCheckPalindrome3( string s )
{
   if( s == reverse(s.begin(), s.end()))
        return true;
    else
        return false;
}
*/ 
int
main(void)
{
    string s;
    
    assert( bCheckPalindrome("abcba") == true );
    assert( bCheckPalindrome("abcb") == false );
    assert( bCheckPalindrome("abababa") == true );
    assert( bCheckPalindrome("") == true );
    assert( bCheckPalindrome("a") == true );
    
    assert( bCheckPalindrome2("abcba") == true );
    assert( bCheckPalindrome2("abcb") == false );
    assert( bCheckPalindrome2("abababa") == true );
    assert( bCheckPalindrome2("") == true );
    assert( bCheckPalindrome2("a") == true );
   /*** 
    assert( bCheckPalindrome3("abcba") == true );
    assert( bCheckPalindrome3("abcb") == false );
    assert( bCheckPalindrome3("abababa") == true );
    assert( bCheckPalindrome3("") == true );
    assert( bCheckPalindrome3("a") == true );
    **/
    return 0;
}