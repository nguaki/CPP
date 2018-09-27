//Sep 26, 2018
//"is a" relationship
//Car      is a toy.
//Train    is a toy.
//Airplane is a toy.
#include <iostream>
using namespace std;

class Toy{
    public:
        virtual void vPrepareParts()=0;
        virtual void vLabelParts()=0;
        virtual void vAssembleParts()=0;
        virtual void vCombineParts()=0;
};

class Car: public Toy{
        void vPrepareParts(){ cout << "Prepare Car." << endl; }
        void vLabelParts(){ cout << "Label Car." << endl; }
        void vAssembleParts(){ cout << "Assemble Car." << endl; }
        void vCombineParts(){ cout << "Combine Car. " << endl; }
};

class Train: public Toy{
        void vPrepareParts(){ cout << "Prepare Train." << endl; }
        void vLabelParts(){ cout << "Label Train." << endl; }
        void vAssembleParts(){ cout << "Assemble Train." << endl; }
        void vCombineParts(){ cout << "Combine Train. " << endl; }
};

class AirPlane : public Toy{
        void vPrepareParts(){ cout << "Prepare Airplne." << endl; }
        void vLabelParts(){ cout << "Label Airplne." << endl; }
        void vAssembleParts(){ cout << "Assemble Airplne." << endl; }
        void vCombineParts(){ cout << "Combine Airplne. " << endl; }
};