//Aug 3, 2018
//This algorithm is upgrade version of fib_dynamo1.cpp.
//This doesn't call recursive.
//It stores the data from the beginning.
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

unsigned long long
fib( unsigned long long *iaN,  int N )
{

    int  i; 
    
   iaN[0] = 1;
   iaN[1] = 1;
  
   if(N==0||N==1) 
        return 1;
        
   for( i = 2; i<=N; i++ ) 
        iaN[i] = iaN[i-2] + iaN[i-1];
   
    return iaN[N]; 
    
}

int
main(void)
{
    unsigned long long ip[100];

    fill( ip, ip+99, 0);
    assert(fib(ip,0)==1);
    assert(fib(ip,1)==1);
    assert(fib(ip,2)==2);
    assert(fib(ip,3)==3);
    assert(fib(ip,4)==5);
    assert(fib(ip,5)==8);
    assert(fib(ip,6)==13);
    assert(fib(ip,7)==21);

    cout << "fib of 5 is " << fib( ip, 5) << endl;  
    
    cout << "fib of 35 is " << fib( ip, 35) << endl;  
    
    cout << "fib of 50 is " << fib( ip, 50) << endl;  
    cout << "fib of 98 is " << fib( ip, 98) << endl;  
    
    cout << "fib of 100 is " << fib( ip, 100) << endl;  
    
    return 0;
}