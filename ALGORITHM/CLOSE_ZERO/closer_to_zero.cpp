#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>
using namespace std;

int
main(void)
{
    int iA[] = { -85, 7, 9, 12, 80, 5, 2, 1, 1 };
    int N = sizeof(iA)/sizeof(iA[0]);
    
    int i,j, iMinLeft = 0, iMinRight = N-1, iMinSum = INT_MAX;
    int iSum;
    
    for(i=0; i<N-1; i++)//Becareful. The upperbound is N-1.
        for(j=i+1; j<N; j++ ){
            iSum = abs(iA[i]+iA[j]);
            
            if( iSum < iMinSum )
            {
                iMinSum = iSum;
                iMinLeft = i;
                iMinRight = j;
            }
        }     
            
    cout << "Min sum close to zero is " << iMinSum << endl;
    cout << "Sum of " << iA[iMinLeft] << "and"  << iA[iMinRight] << endl;
    
    return 0;    
}
