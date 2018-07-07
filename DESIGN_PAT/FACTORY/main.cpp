////////////////////////////////////////////////////////////////////////////////
// June 25, 18
//
// Demonstration of factory pattern
//
//
//       [   Toy     ]           -------->  [ToyFactory]
//  [Car]   [Train]  [AirPlane]
//
//
//  Uses abstract class and derived by 3 classes.
//  From ToyFactory, it has a static function which instantiates a derived object.
//  From main, a user chooses which toy to be created and calls the static function
//  of ToyFactory.
//
//1
//Prepare Car.
//Label Car.
//Assemble Car.
//Combine Car. 
//2
//Prepare Train.
//Label Train.
//Assemble Train.
//Combine Train. 
//3
//Prepare Airplne.
//Label Airplne.
//Assemble Airplne.
//Combine Airplne. 
//4
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Factory.cpp"

using namespace std;

int
main(void)
{ 
    bool bRun = true;
    int  iChoice;
    
    while(bRun == true)
    {
        cin >> iChoice;
        if (!(iChoice == 1 || iChoice == 2 || iChoice ==3 )) bRun = false;
        else 
            ToyFactory::PtrObjCreateToy(iChoice);
        
    }

    return 0;
}