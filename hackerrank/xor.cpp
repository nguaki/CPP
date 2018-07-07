//
//Demonstrates the properties of XOR.
//XOR has commutative property like the multiplication.
//When there is an even number of identical values, it becomes 0.
//The value 0 for XOR is like an initial value - nothing.
//
//OUTPUT
//0
//2
//2
//same
//same
 //
#include <iostream>

using namespace std;

int
main()
{

   int iR = 1 ^ 2 ^ 3;
   int iR1 = 1 ^ 2 ^ 3 ^ (1^2)^(2^3);
   int iR2 = 1 ^ 2 ^ 3 ^ (1^2)^(2^3)^(1^2^3);

    cout << iR << endl;
    cout << iR1 << endl;
    cout << iR2 << endl;
    
    //The following demonstrates commutative property of XOR.
    if((1 ^ 2 ^ 3 ^ (1^2)^(2^3)^(1^2^3)) == (1^1^1)^(2^2^2^2)^(3^3^3))
    {
        cout << "same" << endl;
    }
    
    //The following line demonstrates that even XOR of identical values
    //cancel each other out.  (e.g. XOR(1^1) becomes nothing or 0.
    if((1^1^1)^(2^2^2^2)^(3^3^3) == 1^3)
    {
        cout << "same" << endl;
    }
    
}