#include <iostream>

#include "derived.cpp"

class ToyFactory{
    public:
    static Toy *PtrObjCreateToy(int iChoice){
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
;
        
    }
};