#include <iostream>

// If  a number is power of 2,
// the bitwise representation will have just one 1 bit
// and the rest is 0.
//
// e.g.        16  is    0001 0000
//             15  is    0000 1111
//                     ------------
//                       0000 0000 (AND operation
//)

using namespace std;

void
vFindThisIsPowerOf2( int i){

    if((i & (i-1)) == 0 ) cout << "Power of 2" << endl;
    else cout << "Not Power of 2" << endl;
}



int
main()
{
    
    int i;
    
    do{
        cin >> i;
        vFindThisIsPowerOf2(i);
        
    }while( i != 0 );
    return 0;
}