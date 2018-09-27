#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string
sMoveAdjDup( string sDupString )
{
    int iLen = sDupString.size();
    
    for( int i=1; i<iLen; i++ )
    {
        if( sDupString[i] == sDupString[i-1] )
        {
            int j = i-1;
            int iDupCnt = 1; 
            while( sDupString[j] == sDupString[j+1]){
                iDupCnt++;
                j++;
            }
            sDupString.erase(i-1,iDupCnt);
            iLen = iLen - iDupCnt; 
            i = 0; //i gets incremented right away.
        }
    }
    
    return sDupString;
}

int
main(void)
{
    assert(sMoveAdjDup("azxxzy")=="ay");
    assert(sMoveAdjDup("geeksforgeeg")=="gksfor");
    assert(sMoveAdjDup("caaabbbaacdddd")=="");
    assert(sMoveAdjDup("caaabbbaac")=="");
    return 0;
}