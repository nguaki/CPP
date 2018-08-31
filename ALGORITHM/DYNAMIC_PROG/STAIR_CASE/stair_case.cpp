#include <iostream>

using namespace std;

int
iNumOfWays(int N)
{
    int iNum;
    
    if( N == 0 || N == 1 ) return 1;
   
    
    return iNumOfWays(N-1) + iNumOfWays(N-2);
    
}

int
main(void)
{
    int i;
    
    for( i = 0; i < 35; i ++ )
        cout << "# of ways for " << i << " is " << iNumOfWays(i) << endl;
    
    return 0;    
}    
    
    