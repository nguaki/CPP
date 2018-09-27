//Sep 1, 18
//Elegant way to mimic strstr() using substr() function.
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool
bIsSubstr( string sPattern, string sSource )
{
    int iSourceLen = sSource.length();
    int iPatternLen = sPattern.length();
    
    if( iSourceLen == 0 || iPatternLen == 0 || iPatternLen > iSourceLen ) 
        return false;
        
    for( int i=0; i <= iSourceLen - iPatternLen; i++ )
    {
        //cout << sSource.substr(i, iPatternLen) << endl;
        if(sPattern == sSource.substr(i, iPatternLen)) 
            return true;
    }        
    return false;
}
int
main(void)
{

    assert(bIsSubstr( "int", "Sprint" ) == true );
    assert(bIsSubstr( "int", "Sprnit" ) == false );
    assert(bIsSubstr( "int", "Spritn" ) == false );

    return 0;
}