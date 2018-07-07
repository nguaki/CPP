#include <iostream>
#include <cstdlib>
#include <cstdint>
using namespace std; 

//size_t DoItThisWay(uint8_t buf[], size_t siz);
size_t DoItThisWay(int buf[], size_t siz);
template<typename T, size_t N> size_t DoIt(T(&buf)[N], size_t siz) 
{
    // Work done here...
    cout << "N = " << N << endl;
    cout << "siz = " << siz << endl;
    if( N > 1 )
	{
	for( int i=0; i<N; i++)
	for( int j=0; j<siz; j++)
		cout << buf[i][j] << endl;

	int *pointer;
    pointer = &buf[0][0];
	for( int i=0; i<siz*N; i++)
	    cout << *pointer++ << endl;
DoItThisWay(&buf[0][0], siz*N);
}else
{

	for( int j=0; j<siz; j++)
		cout << buf[j] << endl;
	int *pointer;
    pointer = &buf[0];
	for( int i=0; i<siz*N; i++)
	    cout << *pointer++ << endl;
DoItThisWay(&buf[0], siz*N);
}
    return 0;
}

//size_t DoItThisWay(uint8_t buf[], size_t siz)
size_t DoItThisWay(int *buf, size_t siz)
{
	cout << "From DoitThisWay " << endl;
    for( int i=0; i<siz; i++ )
	cout << buf[i] << endl;
}

int
main(void)
{
	/*
        int  iArray[4][5] = { {1,2,3,4,5},
			     {6,7,8,9,10},
			     {11,12,13,14,15},
			     {16,17,18,19,20}};
       DoIt( iArray, 5 );
	*/
        int  iArray[5] =  {1,2,3,4,5};
       DoIt( iArray, 1 );
	return 0;
}
