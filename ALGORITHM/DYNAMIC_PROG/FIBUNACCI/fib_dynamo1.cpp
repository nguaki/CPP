//Time complexity is O(n).
//This procedure does not repeat  the  calculation.
//Much faster than recursive approach.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;
 
long
fib( long *iaN,  int N )
{
    if( N == 0 || N == 1 ) return 1;
    
    if(iaN[N] != 0 )
        return iaN[N];
   
    iaN[N] = fib(iaN, N-1)   + fib(iaN, N-2);
   
    return iaN[N]; 
    
}

int
main(void)
{
    long ip[100];
    fill(ip, ip+99, 0 );
    
    cout << "fib of 5 is " << fib( ip, 5) << endl;  
    assert(fib(ip,0)==1);
    assert(fib(ip,1)==1);
    assert(fib(ip,2)==2);
    assert(fib(ip,3)==3);
    assert(fib(ip,4)==5);
    assert(fib(ip,5)==8);
    assert(fib(ip,6)==13);
    assert(fib(ip,7)==21);
    cout << "fib of 35 is " << fib( ip, 35) << endl;  
    
    cout << "fib of 50 is " << fib( ip, 50) << endl;  
   
    cout << "fib of 100 is " << fib( ip, 100) << endl;  
    
    return 0;
}