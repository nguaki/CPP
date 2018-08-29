#include<iostream>
#include<algorithm>

using namespace std;

int
iFindLIS(int *iA, int iSize)
{
    int iLIS[iSize+1];
    int iUpperBound, iLowerBound;
    int iActSolution[iSize+1];
    
    for(int i=0; i<iSize; i++ ){
        iLIS[i] = 1;
        iActSolution[i] = i; 
    } 
    
    for( iUpperBound = 1; iUpperBound < iSize; iUpperBound++){
    
        for( iLowerBound = 0; iLowerBound < iUpperBound; iLowerBound++ ){
            if (iA[iLowerBound] < iA[iUpperBound]){
                //iLIS[iUpperBound] = max(iLIS[iUpperBound], iLIS[iLowerBound]+1);
                if( iLIS[iLowerBound]+1 > iLIS[iUpperBound] ){
                    iLIS[iUpperBound] = iLIS[iLowerBound]+1;
                    iActSolution[iUpperBound] = iLowerBound;
                }
            }
        }                
    }
    
    for(int i=0; i<iSize; i++ )
        cout << iActSolution[i] << "  ";
    cout << endl;
    
    int imaxIndex = 0;
    for(int i=0; i < iSize; i++ ){
        if(iLIS[i] > iLIS[imaxIndex] )
            imaxIndex = i;
    }
    
    int it = imaxIndex;
    int inewT = imaxIndex;
    
    do{
        it = inewT;
        cout << iA[it] << "  ";
        inewT = iActSolution[it];
    }while( it != inewT );
    
    
    return iLIS[iSize-1];
} 


int
main(void)
{
    int iA[] = { 3, 4, -1, 0, 6, 2, 3 };
    cout << iFindLIS(iA, sizeof(iA)/sizeof(iA[0]));
    
    return 0;
}