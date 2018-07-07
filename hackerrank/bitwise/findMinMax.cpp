//  Oct 12. 16
//
//  
//  Lets say X = 2 and Y = 3
//  
//  Here are boolean algebra to get a minimum.
//
//  ( 2 < 3 )  yields ( 1 )
//  - 1   =>     0000 0001  (binary representation of 1)
//               1111 1110  (compliment of 1)
//             + 0000 0001  (2's compliment)
//            -------------
//               1111 1111
//
//   -(X < Y) is 1111 1111
//   
//   ( X^Y ) ^ (1111 1111) = ( X^Y )
//   Y^(X^Y) = X
//
//
#include <iostream>

using namespace std;
 
void
vFindMinMax( int X, int Y )
{
   int iMin;
   int iMax;
   
   iMin = Y^(( X^Y ) &-( X < Y ));
   iMax = X^(( X^Y ) &-( X < Y ));
   
   cout << "Min is " << iMin << endl;
   cout << "Max is " << iMax << endl;
}


int
main()
{
    
    int X, Y;
    
    cin >> X;
    cin >> Y;
    
    vFindMinMax(X, Y);


    return 0;
}