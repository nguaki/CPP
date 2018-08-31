//Aug 7, 2018
//This utilizes stack class.
#include <iostream>
#include <stack>
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
    stack<char> sCheckPair;
   
    int i;
    
    for( i=0; i<strlen(ca); i++){
        if( bCheckOpen(ca[i]) )
            sCheckPair.push(ca[i]);
        else if( sCheckPair.size() != 0 && bCheckClose(ca[i])){
            //top() MF doesn't pop. It just returns the value.
            char c1 = sCheckPair.top();
            if( !bCheckPair(c1, ca[i])) return false;
            else  sCheckPair.pop();
        }
    }
    
    if( sCheckPair.size() == 0 ) return true;
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