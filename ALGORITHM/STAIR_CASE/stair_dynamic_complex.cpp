#include <iostream>

using namespace std;

int iStorage[101];

int
iNumOfWays(int N)
{
    int iNum;
    int iTotal;
    
    if( N == 0 || N == 1 ) return 1;
    if( iStorage[N] != 0 ) return iStorage[N];
    
    if( N-5 > 0 )
        iTotal =  iNumOfWays(N-1) + iNumOfWays(N-3) + iNumOfWays(N-5);
    else if( N-3 > 0 )
        iTotal =  iNumOfWays(N-1) + iNumOfWays(N-3);
    else
        iTotal =  iNumOfWays(N-1);
    
    iStorage[N] = iTotal; 
    return iTotal; 
}

int
main(void)
{
    int i;
    fill( iStorage, iStorage+101, 0); 
    iStorage[0] = 1;
    iStorage[1] = 1;
    
    for( i = 0; i < 100; i ++ )
    {
        cout << "# of ways for " << i << " is " << iNumOfWays(i) << endl;
    } 
    return 0;    
}    
    
    