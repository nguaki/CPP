// Oct 12, 16
//
// Sets i-th bit to 1.
//
//Enter an integer: 15
//Enter bit position to clear: 3
//OLD bit0000000000001111
//NEW bit0000000000001011
//
//How does it work?
//
// e.g.  15    =>   0000 1111
//      (1<<2) =>   0000 0100
//     ~(1<<2) =>   1111 1011
//
//                  0000 1111
//                 &1111 1011
//                 -----------
//                  0000 1011
//

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int
main()
{
    int i;
    int iNewNumber, iBitPlace;
    
    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter bit position to clear: ";
    cin >> iBitPlace;
    
    iNewNumber  = i & ~(1 << (iBitPlace-1));
    //cout << showbase << bin << endl;

    bitset<16> bitX(i);
    bitset<16> newBitX(iNewNumber);
    cout << "OLD bit" << bitX << endl;
    cout << "NEW bit" << newBitX << endl;
    
 

    return 0;
}