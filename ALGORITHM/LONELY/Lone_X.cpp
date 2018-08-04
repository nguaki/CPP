//The power of X- eXeclusive OR.
//
// 5 XOR 5 = 0
// 5 XOR 0 = 5
// XOR has commutative property?
//   Which means is that the order of XOR doesn't matter.
// 5 ^ 4 ^ 6 = 6 ^ 4 ^ 5
//
#include <iostream>

using namespace std;

int
main(void)
{
    int iNum[] = { 1, 1, 2, 2, 3, 4, 4 };
    
    int iLoneNum = 0; //Initialize to 0, not 1.  Easy mistake.
    
    int i;
    
    for( i = 0; i < sizeof(iNum)/sizeof(iNum[0]); i ++ )
        //This little symbole has all the power in the world.
        iLoneNum = iLoneNum ^ iNum[i];
        
    cout << "Lonely number is " << iLoneNum << endl;
    
    return 0;
}