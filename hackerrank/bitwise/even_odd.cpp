// Oct 13, 16
//
// Decides whether an int is even or odd using bitwise operation.
//
#include <iostream>

using namespace std;

int
main()
{

    int i;
    
    cin >> i;
    
    if( (i & 1) == 0 ) cout << "Even" << endl;  //The parenthesis is very important.
    else cout << "Odd" << endl;
}