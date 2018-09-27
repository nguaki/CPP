//Aug 3, 2018
//This algorithm is upgrade version of fib_dynamo2.cpp.
//This one has Space complexity of O(1)
//This doesn't call recursive.
//It stores the data from the beginning.
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

unsigned long long
fib( int N )
{

    int  i, iOneBefore = 1, iOneBeforeBefore = 1, iCurrent; 
    
   if(N==0||N==1) 
        return 1;
        
   for( i = 2; i<=N; i++ ) 
   {
        iCurrent = iOneBefore + iOneBeforeBefore;  //f(n) = f(n-1) + f(n-2)
        iOneBeforeBefore = iOneBefore;
        iOneBefore = iCurrent;
   }     
   
   return iOneBefore; 
    
}

int
main(void)
{

    assert(fib(0)==1);
    assert(fib(1)==1);
    assert(fib(2)==2);
    assert(fib(3)==3);
    assert(fib(4)==5);
    assert(fib(5)==8);
    assert(fib(6)==13);
    assert(fib(7)==21);

    cout << "fib of 5 is " << fib( 5) << endl;  
    
    cout << "fib of 35 is " << fib(35) << endl;  
    
    cout << "fib of 50 is " << fib(50) << endl;  
    cout << "fib of 98 is " << fib( 98) << endl;  
    
    cout << "fib of 100 is " << fib(100) << endl;  
    
    return 0;
}