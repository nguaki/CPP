// Oct 12, 16
//
// Sets i-th bit to 1.
//
//Enter an integer: 8
//Enter bit position to set: 3
//OLD bit0000000000001000
//NEW bit0000000000001100
//
//How does it work?
//
// e.g.          8   =>   0000 1000
//           3rd position bit is  ( 1 << 2 ) => 0000 0100
//
//               0000 1000
//           OR  0000 0100
//          ------------------
//               0000 1100
//

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;
//using namespace std;

int
main()
{
    int i;
    int iNewNumber, iBitPlace;
    
    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter bit position to set: ";
    cin >> iBitPlace;
    
    iNewNumber  = i | (1 << (iBitPlace-1));
    //cout << showbase << bin << endl;

    bitset<16> bitX(i);
    bitset<16> newBitX(iNewNumber);
    cout << "OLD bit" << bitX << endl;
    cout << "NEW bit" << newBitX << endl;
    
 

    return 0;
}