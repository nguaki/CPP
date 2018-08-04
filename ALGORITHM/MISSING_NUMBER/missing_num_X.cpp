//Aug 4, 18
//The solution is understanding the properties of Xor.
//
//Strategy:
//  Lets say 3 is missing of N = 4;
//
//    A1 = 1 ^ 2 ^ 3 ^ 4;
//    B1 = 1 ^ 2 ^ 4;
//
//    C = A1 ^ B1 = 3.
//
#include <iostream>
#include <algorithm>

using namespace std;

int
main(void)
{
   int iA[] = { 2, 4, 5, 6, 1 };
   int i;
    
   int A = 0;
   int B = 0;
   int C;
   
   
   for( i=0; i <= 4; i ++) 
    A = A ^ iA[i];
    
    
   for( i=1; i <= 6; i ++) 
    B = B ^ i;
    
   C = A ^ B;
  
   cout << C << " is missing number" << endl; 
   return 0;
}