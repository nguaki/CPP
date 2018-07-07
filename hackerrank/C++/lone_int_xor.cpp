//  Hackerrank 
//
// Find lonely integer using xor.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    int _a_item;
    int iLonelyInt;
    // XOR is a commuatative property.
    // So  37 ^ 39 ^ 38 ^ 37 ^ 38
    //   = 37 ^ 37 ^ 38 ^ 38 ^ 39
    //   =    0    ^    0    ^ 39
    //   =   39
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        iLonelyInt ^= _a_item;
    
    }

    cout << iLonelyInt;
    
    return 0;
}
