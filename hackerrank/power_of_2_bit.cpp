//Sep 29, 16
//
#include <iostream>

using namespace std;

//This function checks if the input is a power of 2 number.
//If power of 2, the binary will look like  0010000.
//If decrement 1, the binary will look like 0001111.
//e.g.  8   is   0b01000
//      7   is   0b00111
//so AND will be 0b00000
int iCheckPowerOf2(unsigned long long int n){
    unsigned long long int ulli;
    
    ulli = n & (n-1);
    cout << ulli << endl;
    
    if( (n & (n-1)) == 0 ) {
        cout << "I am 0" << endl;
        return 1;
    }
    else return 0;
}

int setBits(unsigned long long int n) {
	int count = 0 ;
    
    while(n) {
    	n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int
main()
{
    unsigned long long int ull;
    int iCnt;
    
    ull = 0b10000000;

    if( iCheckPowerOf2(ull) ) 
    {
        cout << ull << " is a power of 2" << endl;
    }

    iCnt = setBits(ull);
    cout << iCnt << endl;;

    ull = 0b11111110001000;
    iCnt = setBits(ull);
    cout << iCnt << endl; //8
    
    iCnt = setBits(ull-1);
    cout << iCnt << endl;  //10
    
    
    ull = 0b111111111111000;
    iCnt = setBits(ull);
    cout << iCnt << endl; //12  
    iCnt = setBits(ull-1);
    cout << iCnt << endl;  //14  number of 1 to the right of least significant set 1, (11) 
                           //    number of 0 to the right of least significant set 1 (3)
    
    //cout << "iCount = " << iCount;
    
}