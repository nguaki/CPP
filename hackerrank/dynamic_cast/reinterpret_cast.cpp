// Reinterpret RAM data.
// Impacts during compile time.
//
//
//
#include <iostream>

using namespace std;

struct Cow{
    int  iLegs;
    int  iMooCnt;
    char cGender;
    bool bButchered;

};

int
main(){

    Cow stCow;
    
    stCow.iLegs      = 4;
    stCow.iMooCnt    = 10;
    stCow.cGender    = 'F';
    stCow.bButchered = true;

    Cow *pCow;
    
    pCow = &stCow;
    
    int  *iPtr;
    
    iPtr = (int *)&stCow;
    
    cout << *iPtr << endl;
    
    iPtr = reinterpret_cast<int *>(pCow);
    
    cout << *iPtr << endl;
    
    iPtr++;
    
    cout << *iPtr << endl;
    
    iPtr++;
    
    char *pC = reinterpret_cast<char *>(iPtr);
    
    cout << *pC << endl;
    
    pC++;
    
    bool *pB = reinterpret_cast<bool *>(pC);
    
    cout << *pB << endl;
    
    return 0;
}
