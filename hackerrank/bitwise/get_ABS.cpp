// Oct 12, 2016
//
// Gets absolute value of a number.
//
//  e.g.   get abs(-5).
//
//  5        =>    0000 0101
//                 1111 1010 (one's compliment)
//               + 0000 0001 ( add 1 )
//               ------------
//                 1111 1011 ( two's compliment)
//
//    -( -5 < 0 )  = -(1)
//                 = -(0000 0001)
//                 =  1111 1111
//
//     (X^-X)&(11111111) = (X^-X)
//     X^(X^-X) = 0^-X = -X
//     -(-5) = 5
//
#include <iostream>

using namespace std;

void
vGetABS( int X ){

    int iAbs;
    
    iAbs =  X ^ (( X ^ -X )  & -( X < 0 ));

    cout << "absolute = " << iAbs << endl;
}

int
main()
{

    int i;
    
    do{
        cin >> i;
    
        vGetABS( i );
    }while( i != 0 ); 
}
