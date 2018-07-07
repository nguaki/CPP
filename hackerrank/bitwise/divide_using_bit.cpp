//  Oct 13, 16 
//
//  Doing division by power of 2 numbers(e.g. 2, 4 ,8, 16, 32, )
//  using right bit shift.
//
#include <iostream>

using namespace std;

int
main(){

    int i;
    int iMultiplyBy;
    
    cout << "Enter a number:";
    cin >> i;
    
    cout << "Enter a number to multiply: (2,4,8,16,32):";
    
    cin >> iMultiplyBy;
    
    switch(iMultiplyBy){
        case 2:
            i = i >> 1;
            break;
        case 4:
            i = i >> 2;
            break;
        case 8:
            i = i >> 3;
            break;
        case 16:
            i = i >> 4;
            break;
        case 32:
            i = i >> 5;
            break;
        default:
            break;
    }
    
    cout << "Result = " << i << endl;
}