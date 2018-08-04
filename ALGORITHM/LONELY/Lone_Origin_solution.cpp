//This is what most people would think to solve this problem.
//This is O(n^2).
//Very inefficient.
#include <iostream>

using namespace std;

int
main(void)
{
    int iNum[] = { 1, 1, 2, 2, 3, 4, 4 };
    
    int iLoneNum = 0;
    
    int i, j;
   
    for( i = 0; i < sizeof(iNum)/sizeof(iNum[0]); i++){
        iLoneNum = 1; 
        for( j = 0; j < sizeof(iNum)/sizeof(iNum[0]); j++){
            if( i != j ){
                if(iNum[i] == iNum[j] ){
                    iLoneNum = 0;
                    break;
                } 
            }         
        } 
        if( iLoneNum ){
            cout << iNum[i]  << " is lonely!";
            break;
        }
    }     
    
    return 0;
    
}