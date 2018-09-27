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
        
    for( int i=0; i < iSourceLen; i++ )
    {
        if( sSource[i] == sPattern[0] )
        {
            int iSrcIndexFirstLetterOccurred = i;
            bool bMatchExists = true;
            for( int j=1; j<iPatternLen && bMatchExists; j++)
            {
                if( sSource[iSrcIndexFirstLetterOccurred+j] == sPattern[j] )
                    continue;
                else 
                    bMatchExists = false;
            }
            if(bMatchExists) return true;
        }
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