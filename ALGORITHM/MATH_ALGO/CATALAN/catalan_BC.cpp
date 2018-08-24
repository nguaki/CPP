//Aug 23, 18
//Demonstrates the power of dynamic programming.
//catalan has huge importance in application.
#include<iostream>
using namespace std;
 
// A recursive function to find nth catalan numbers
unsigned long long BC(unsigned int n, unsigned int k)
{
    unsigned int k1;
    
    if( k <= 1 ) return 1;
    
    k1 = min( k, n-k);
    
    unsigned long long res = 1;
    for (int i=0; i<k1; i++){
        res *= (n-i);
        res /= (i+1);
    }
 
    return res/(k+1);
}
 
// Driver program to test above function
int main()
{
    for (int i=0; i<100; i++){
        cout << i << "  " << BC(2*i, i) << endl;
    }
    BC(6, 3);
    BC(4, 2);
    
    return 0;
}