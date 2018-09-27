////////////////////////////////////////////////////////////////////////////////
// June 25, 18
//
// Demonstration of factory pattern
//
//
//       [Toy Interface]   <>------------   [ToyFactory]
//             ^
//    |--------|---------|
//  [Car]   [Train]  [AirPlane]
//
//  Note:The derived classes not only inherits but implements.
//
//  Uses interface(pure abstract class) and derived by 3 classes.
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
//
// Sep 5, 18  -  Does it have to use static method?
//               Why?  Need to experiment without using static method.
//               I guess creating a class which generates different kind of
//               objects is a big deal.
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