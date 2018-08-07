//Aug 7, 2018
#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;
bool
bCheckOpen( char c )
{ 
    return ( c == '[' || c == '{' || c== '(' ) ? true: false;
} 
bool
bCheckClose( char c )
{
    return ( c == ']' || c == '}' || c== ')' ) ? true: false;
}

bool
bCheckPair(char openChar, char closeChar ){
    char cExpOpenChar = ' ';
    
    if( closeChar == ')') cExpOpenChar = '(';
    else if( closeChar == ']') cExpOpenChar = '[';
    else if( closeChar == '}') cExpOpenChar = '{';
   
    return (openChar == cExpOpenChar) ? true:false;
}

bool
bCheckBalanced( char *ca )
{
    vector<char> vCheckPair;
   
    int i;
    
    for( i=0; i<strlen(ca); i++){
        if( bCheckOpen(ca[i]) )
            vCheckPair.push_back(ca[i]);
        else if( vCheckPair.size() != 0 && bCheckClose(ca[i])){
            char c1 = vCheckPair[vCheckPair.size()-1];
            if( !bCheckPair(c1, ca[i])) return false;
            else  vCheckPair.pop_back();
        }
    }
    
    if( vCheckPair.size() == 0 ) return true;
    else return false;
}

int
main(void)
{
    char ca[100];
    
    //Must typecast.
    //C++ has string type.  Converting string to char* will give warning message.
    assert( bCheckBalanced( (char *)"{{{}}}" ) == true );
    assert( bCheckBalanced( (char *)"{{[}}}" ) == false );
    assert( bCheckBalanced( (char *)"{[{}]}" ) == true );
    assert( bCheckBalanced( (char *)"{[()]}" ) == true );
    assert( bCheckBalanced( (char *)"{{{}kkk}}" ) == true );
    assert( bCheckBalanced( (char *)"{{xxx{fff}}}" ) == true );
    
    return 0;
}