// Oct 13, 16
//
// Identifies if 2 numbers are same sign or opposite sign.
//
//How does it work?
//
//   e.g.    3   =>   0000 0011  
//           
//          -3   =>   0000 0011  (positive 3)
//                    1111 1100  (compliment)
//                   +0000 0001  (add 1)
//                   -----------
//                    1111 1101
//
//  A property of XOR is 1 ^ 0 = 1
//
//  Notice that the sign bit (the very first bit) is opposite.
//
//   So if XOR, the sign bit will always be 1 which means it is less than zero.
#include <iostream>
#include <bitset>


using namespace std;

int
main()
{
    int X, Y;
    
    cin >> X >> Y;
    bitset<16> bitX(X);
    bitset<16> bitY(Y);
    
    if( (X^Y) < 0 ) cout << "Opposite signed numbers." << endl;
    else cout << "Same signed numbers." << endl; 

    cout << "X: " << bitX << endl;
    cout << "Y: " << bitY << endl;
    
    return 0;
}
