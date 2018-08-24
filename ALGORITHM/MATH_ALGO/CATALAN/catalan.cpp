#include<iostream>
using namespace std;
 
// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n)
{
    //cout << "n=" << n << endl;
    // Base case
    if (n <= 1) return 1;
 
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
 
    return res;
}
 
// Driver program to test above function
int main()
{
    for (int i=0; i<100; i++){
        
        cout << i << "  " << catalan(i) << endl;
    }
    catalan(3);
    catalan(2);
    return 0;
}