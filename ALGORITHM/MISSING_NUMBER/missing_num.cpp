//Aug 4, 18
//The solution is understanding math equation of N*(N+1)/2 = sum(1,N);
#include <iostream>

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
    int iA[] = { 1, 2, 4, 5, 6 };
    
    vGetMissNum( iA, 6 );
    
    return 0;
}