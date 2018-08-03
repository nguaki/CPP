//////////////////////////////////////////////////////////////////////////////////////
//
// Sep 28, 16
//
// Uses generate() built-in function to populate vector and add sum.
// Uses accumulate() built-in .function to add these values
//
//OUTPUT
//90  76  83  21  96  41  59  5  11  23  
//53  32  65  64  10  95  9  16  42  7  
//sum:393
//sum:393
//
//////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>  //needed for accumulate() function call.


using namespace std;

template <typename T>
void 
vDisplay(vector<T> vcValues){
    
    for(int i=0; i<vcValues.size();i++){
        cout << vcValues[i] << "  ";
    }
    cout << endl;
}

int
iGenerateRand(){
    
    return rand() % 100 + 1;
}

int
main()
{
    vector<int> vecValues;
    int iValue;
    
    srand(time(NULL));

    //I don't understand the need for these lines for this 
    //program to work.
    for(int i = 0; i < 10; i++){
        iValue = rand() % 100 + 1;
        vecValues.push_back(iValue);
    }
    
    vDisplay(vecValues);
    
    
    //Uses call back function to populate this vector.
    //If the above lines were not executed, this doesn't work.
    generate( vecValues.begin(), vecValues.end(), iGenerateRand );
    
    vDisplay(vecValues);
    
    //Confirming if accumulate algo really works.
    int iSum = 0;
    for(int i = 0; i<vecValues.size(); i++){
        //cout << "adding " << vecValues[i] << endl;
        iSum += vecValues[i];
    }
    
    cout << "sum:" << iSum << endl;
    
    //Uses built in function accumulate to add.  The third parameter is
    //offset.
    iSum = accumulate(vecValues.begin(), vecValues.end(), 0);
    cout << "sum:" << iSum << endl;
     
   return 0;
}
