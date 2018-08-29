#include<iostream>
#include<algorithm>

using namespace std;

int
iFindLIS(int *iA, int iSize)
{
    int iLIS[iSize+1];
    int iUpperBound, iLowerBound;
    
    for(int i=0; i<iSize; i++ ) iLIS[i] = 1;
    
    for( iUpperBound = 1; iUpperBound < iSize; iUpperBound++){
    
        for( iLowerBound = 0; iLowerBound < iUpperBound; iLowerBound++ ){
            if (iA[iLowerBound] < iA[iUpperBound])
                iLIS[iUpperBound] = max(iLIS[iUpperBound], iLIS[iLowerBound]+1);
        }                
    }
    return iLIS[iSize-1];
} 


int
main(void)
{
    int iA[] = { 3, 4, -1, 0, 6, 2, 3 };
    cout << iFindLIS(iA, sizeof(iA)/sizeof(iA[0]));
    
    return 0;
}