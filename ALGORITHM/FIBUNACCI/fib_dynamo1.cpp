//Time complexity is O(n).
//This procedure does not repeat  the  calculation.
//Much faster than recursive approach.

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
 
long
fib( long *iaN,  int N )
{

    long iR;
    
    if(iaN[N] != 0 )
        return iaN[N];
   
    if(N == 1 || N == 2 ) 
        iR = 1;
   
    else
        iR = fib(iaN, N-1)   + fib(iaN, N-2);
    
    iaN[N] = iR;
   
    return iR; 
    
}

int
main(void)
{
    long *ip = new long[5+1];
    fill(ip, ip+6, 0 );
    cout << "fib of 5 is " << fib( ip, 5) << endl;  
    delete ip;
    
    ip = new long[35+1];
    fill(ip, ip+36, 0 );
    cout << "fib of 35 is " << fib( ip, 35) << endl;  
    delete ip;    
    
    ip = new long[50+1];
    fill(ip, ip+51, 0 );
    cout << "fib of 50 is " << fib( ip, 50) << endl;  
    delete ip;
   
    ip = new long[100+1];
    fill(ip, ip+101, 0 );
    cout << "fib of 100 is " << fib( ip, 100) << endl;  
    delete ip;
    
    ip = new long[1000+1];
    fill(ip, ip+101, 0 );
    cout << "fib of 100 is " << fib( ip, 1000) << endl;  
    delete ip;
    
    return 0;
}