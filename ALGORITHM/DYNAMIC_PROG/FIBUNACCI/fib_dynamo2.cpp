//Aug 3, 2018
//This algorithm is upgrade version of fib_dynamo1.cpp.
//This doesn't call recursive.
//It stores the data from the beginning.
#include <iostream>
#include <cstdio>

using namespace std;

long
fib( long *iaN,  int N )
{

    int iR, i; 
    
   iaN[1] = 1;
   iaN[2] = 1;
   
    for( i = 3; i<=N; i++ ) 
        iaN[i] = iaN[i-2] + iaN[i-1];
   
    return iaN[N]; 
    
}

int
main(void)
{
    long *ip = new long[5+1];

    cout << "fib of 5 is " << fib( ip, 5) << endl;  
    delete ip;
    
    ip = new long[35+1];
    cout << "fib of 35 is " << fib( ip, 35) << endl;  
    delete ip;
    
    ip = new long[50+1];
    cout << "fib of 50 is " << fib( ip, 50) << endl;  
    delete ip;
    
    ip = new long[100+1];
    cout << "fib of 100 is " << fib( ip, 100) << endl;  
    delete ip;
    
    ip = new long[1000+1];
    cout << "fib of 100 is " << fib( ip, 1000) << endl;  
    delete ip;
    return 0;
}