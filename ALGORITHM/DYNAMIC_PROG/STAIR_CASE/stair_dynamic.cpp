//Dynamic program solution to recursive only solution. 
//This reduces the number of calculation by storing already calculated numbers
//into an array.
//This method will save the time of execution dramatically.
//Used to be O(2^^n). But now it is ??? Should be linear, not exponential.
//Not sure what is actual O() notation for this method.
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
    
    iTotal =  iNumOfWays(N-1) + iNumOfWays(N-2);
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
    
    