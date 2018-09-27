//Sep 5,18   -  There is polymorphism here.
//              Returns a pointer to base abstract class but
//              the actual object are all derived objects.
//Sep 26,18     According to Derek Banas: Factory pattern is "When a method
//              returns object of one of several classes that share a common
//              super class".  This happens during runtime.
#include <iostream>

#include "derived.cpp"

class ToyFactory{
    public:
    
    //This time the returning object is polymorphic.
    //Sep 26, 2018 - There is no need to return anything since the 
    //               parts are already created.
    //               There is no return statement.
    //               Why static?
    static Toy* PtrObjCreateToy(int iChoice){
        Toy *ptrObjToy;
        switch(iChoice){
            case 1:
                ptrObjToy = new Car();
                break;
            case 2:
                ptrObjToy = new Train();
                break;
            case 3:
                ptrObjToy = new AirPlane();
                break;
            default:
               break;
        }
        ptrObjToy->vPrepareParts();
        ptrObjToy->vLabelParts();
        ptrObjToy->vAssembleParts();
        ptrObjToy->vCombineParts();
    }
};