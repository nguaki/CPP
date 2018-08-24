//Aug 23, 2018
//No multiplication used for POW() function.
#include <iostream>

using namespace std;

long long int 
_pow(int a, int b)
{
    int iInc = a;
    int iSum = a;
    int i, j;
    
    for( i=0; i<b-1; i++){
        for( j=0; j<a-1; j++ ){
            iSum += iInc;
        }
        iInc = iSum;
    }
    
    return iSum;
}

int
main(void)
{
    cout << _pow(5,4);
    
    return 0;
}