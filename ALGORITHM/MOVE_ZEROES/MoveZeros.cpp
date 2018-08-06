#include <iostream>

using namespace std;

int 
main(void)
{
    int iA[] = { 1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9 };
    int N = sizeof(iA)/sizeof(iA[0]); 
    int iCntNonZero = 0;
    int i;
    
    for( i=0; i<N; i++){
        if(iA[i] > 0 ){
            iA[iCntNonZero] = iA[i];
            iCntNonZero++;
        }
    }
    
    while(iCntNonZero < N ) iA[iCntNonZero++] = 0;
    
    for( i=0; i<N; i++) cout << iA[i] << "  ";
    
    return 0;
}





    