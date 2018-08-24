//Aug 23, 18
//Demonstrates the power of dynamic programming.
//catalan has huge importance in application.
#include<iostream>
using namespace std;
 
// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n, int* DP)
{
    //cout << "n=" << n << endl;
    // Base case
    if (n <= 1) return 1;
    if (DP[n]) return DP[n];
    
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i, DP)*catalan(n-i-1, DP);
 
    DP[n] = res;
    
    return res;
}
 
// Driver program to test above function
int main()
{
    int DP[100];
    
    for (int i=0; i<100; i++) DP[i] = 0;
    
    for (int i=0; i<100; i++){
        
        cout << i << "  " << catalan(i, DP) << endl;
    }
    catalan(3, DP);
    catalan(2, DP);
    
    return 0;
}