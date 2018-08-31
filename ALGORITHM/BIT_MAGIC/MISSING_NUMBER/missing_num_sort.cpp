//Aug 4, 18
//Remember only 1 number is missing.
//The solution is understanding math equation of N*(N+1)/2 = sum(1,N);
#include <iostream>
#include <algorithm>

using namespace std;

void
vGetMissNum( int *iA, int N )
{

    int iSum = N * (N+1) / 2;
    
    int i;
    
    for( i = 0; i <N-1; i++ )
        iSum -= iA[i];
        
    cout << "Missing num is " << iSum << endl;
}

int
main(void)
{
   int iA[] = { 2, 4, 5, 6, 1 };
   int i;
    
   sort( iA, iA + 5 );
   
   for( i=0; i < 4; i ++) 
    if( iA[i] != i+1){
        cout << i+1 << " is missing" << endl;
        break;
    }     
    
   return 0;
}