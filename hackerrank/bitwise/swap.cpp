// Oct 12, 16
//
// Uses XOR to swap two variables.
//
#include <iostream>

using namespace std;

int
main()
{

    int X, Y;
    
    cout <<  "X:";
    cin >> X;
    cout << "Y:";
    cin >> Y;
    
    X = X ^ Y;
    Y = Y ^ X;
    X = X ^ Y;
    
    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;

    return 0;
}