//
//Aug 20, 2016
//
//OUTPUT
//1  2  3  4  5  6  7  8  9  10  
//Jane  Kareem  Magic  Worthy  Scottie  Michael  Byron  Bird  James  Matt  
//
//Uses template to generalize parameter data types.
//
#include <iostream>
#include <string>
using namespace std;

//Outstanding feature of C++.
//Any array type can be sent to this function.
template <typename T>
void vDisplay(T tArray[], int iSize)
{
    for( int i = 0; i<iSize; ++i){
        cout << tArray[i] << "  ";
    }
    cout << endl;
}

int
main()
{
    const int size = 10;
    int iArray[size];
    string strArray[size] = { "Jane", "Kareem", "Magic", "Worthy", "Scottie",
                              "Michael", "Byron", "Bird", "James", "Matt" };
    
    for( int i = 0; i<size; i++){
        iArray[i] = i + 1;
    }
    vDisplay(iArray, size);
    vDisplay(strArray, size);
    
    return 0;
}