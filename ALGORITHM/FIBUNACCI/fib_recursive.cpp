////////////////////////////////////////////////////////////////////////////
// Time complexity of 2^^N.
//
// f(5), f(35) didn't take too long.
// f(50) took forever.
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int fib( int x){
	if(x==1 || x==2 ) return 1;
	else
		return fib(x-1)+fib(x-2);
}

int main( int argc, char **argv)
{
	//printf( "%s %s\n", argv[0], argv[1] );
	//int n = atoi(argv[1] );
	//
	cout << "Fib result is : " << fib(5) << endl;
	cout << "Fib result is : " << fib(35) << endl;
	cout << "Fib result is : " << fib(50) << endl;
	return 0;
}
