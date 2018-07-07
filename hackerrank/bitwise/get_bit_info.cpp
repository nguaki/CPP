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
    cout << "Find out bit of which position: ";
    cin >> iBitPlace;
    
    iNewNumber  = i & (1 << (iBitPlace-1));
    //cout << showbase << bin << endl;

    bitset<16> bitX(i);
    bitset<16> newBitX(iNewNumber);
    cout << "OLD bit" << bitX << endl;
    cout << "NEW bit" << newBitX << endl;
    
 

    return 0;
}