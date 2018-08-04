#include <iostream>

using namespace std;

int
main(void)
{
    //int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
    int iA[] = { 3, 3, 4, 2, 4, 4, 2, 4 };
    
    int i, j;
    int iCnt[8] = {0};
    int iSize = sizeof(iA)/sizeof(iA[0]);
    bool bFound = false;
    
    int N = 9; 
    float fMajority = N/2;
    for( i=0; i<N; i++)
        for( j=0; j<N; j++){
            if( i != j && iA[i] == iA[j] ) iCnt[i]++;
            if( (float)iCnt[i] > fMajority ){
                cout << iA[i] << " is majority" << endl;
                bFound = true;
                break;
            } 
            if( bFound ) break;
        }
   
    if( bFound == false )  cout << "There is no majority number." <<endl; 
    return 0;
}
            
            