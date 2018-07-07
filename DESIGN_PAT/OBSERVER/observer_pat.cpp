////////////////////////////////////////////////////////////////////////////////
// June 25, 2018
//
//Demonstration of Observation Pattern.
//This pattern is used in games.
//Example: In racing car game, when a car's position has changed, it has ackowledge
//         the new position to all the cars currently running on the screen.
//
//Need -std=c++11 to compile keyword auto
//
//Uses vector of pointers of objects.
//
//
//               [ Observer  ]
//               [-Car       ]        <---------------------->  [Car               ]
//                                                              [-vector<Observer*>]
//   [LeftObserver] [CenterObserver] {RightObserver]
//
//    Note that both sides uses each other's objects.
//
//I am left
//I am left
//I am right
//I am right
//I am right
//I am center
//r
//I am right
//I am right
//I am right
//l
//I am left
//I am left
//c
//I am in the middle
//0
//
// Setting up:
//    (1)Instatiate a Car object using new.
//    (2)Instatiate derived observer objects and pass in address of Car object.
//
//  Tricks:
//    (1)Derived class calls Observer base constructor immediately using 
//            LeftObservator( Car *aCar ) : aCar(Observator)
//    (2)From Observer base class, it does
//            Observator( Car *aCar ){
//                 _car = aCar;
//                 _car->vAttach(this);
//            }
//        Here, it sends itself.
//   (3)From Car.vAttach() method, is uses polymorphism to loade up derived classes.
//
// Updating Position
//   (1) Call Call.vUpdate() method.
//   (2) From vUpdate(), go thru each item from the vector list,
//         call Observer's derived object.  Again using polymorphism.
//   (3) From each derived object, get the current Car's position
//       by calling the getter.
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

//Forward reference.
class Observer;

class Car{ 
    int _iPosition; 
    vector<Observer *> vobjptrList;
    public:
        //Adds a new object to a vector.
        void vAttach(Observer *obs)
        { 
            vobjptrList.push_back(obs); 
        }      
        //Display all objects currently in a vector.
        void vDisp(); 
        //Updates a new position of the car.
        void vSetPosition( int iPosition )
        {
            _iPosition = iPosition;
            vUpdate();
        }
        void vUpdate();
        
        //Returns the current position of the car.
        int iGetPosition()
        {
            return _iPosition;
        }
};

//The location of these functions is important since vUpdate() of Observer class
//has not yet been defined, there will be an error message.
//This function needs to at the end.
/**
void Car::vUpdate()
{
    auto it = vobjptrList.begin();
   
    while(it !=  vobjptrList.end() ){
        (*it)->vUpdate();
        it++;
}
**/
/**
void Car::vDisp()
{
    auto it = vobjptrList.begin();
    //vector<Observer *>::iterator it = vobjptrList.begin();
   
    while(it !=  vobjptrList.end() ){
        //it->(Observer *)vDisp();
        //(**it).vDisp();
        //*(*it).vDisp();
        //(Observer *)(*it).vDisp();
        
        //(*it)->vDisp();
        cout << "attached."; 
        it++;
    }
}
**/
//Abstract class with 2 virtual functions.
class Observer{
    Car *_car;
    public:
        //Constructor which is invoked by the derived classes.
        Observer(Car *ptrCar)
        { 
            _car = ptrCar; 
            _car->vAttach(this); //Calls car method to add to a vector.
        }
        Car * ptrGetCar(){ return _car;}
        virtual void vDisp() = 0; 
        virtual void vUpdate() = 0; 
        //void vDisp(){ cout << "Observer " << endl;  }
        //void vSetCar(Car &refCar){ _car = refCar; }
};

//Derived class which is left side of the car.
class Leftobserver : public Observer{
    public:
        //
        Leftobserver(Car *objptrCar) : Observer(objptrCar){}
        void vDisp(){ cout << "I am left" << endl; }
        //gets update of the car in motion.
        //if it actually came this way, need to do something.
        //Since Car is a private variable, need to use getter to access the
        //position.
        void vUpdate()
        { 
            if( ptrGetCar()->iGetPosition() < 0 ) cout << "I am left" << endl; 
        }
};

class Rightobserver : public Observer{
    public:
        Rightobserver(Car *objptrCar) : Observer(objptrCar){}
        void vDisp(){ cout << "I am right" << endl; }
        void vUpdate()
        { 
            if( ptrGetCar()->iGetPosition() > 0 ) cout << "I am right" << endl; 
        }

};

class Centralobserver : public Observer{
    public:
        Centralobserver(Car *objptrCar) : Observer(objptrCar){}
        void vDisp(){ cout << "I am center" << endl; }
        void vUpdate()
        { 
            if( ptrGetCar()->iGetPosition() == 0 ) cout << "I am in the middle" << endl; 
        }

};

//Uses iterator to print out current Obsersers.
//Uses polymorphism to distinguish between left, right and center observers.
void Car::vDisp()
{
    auto it = vobjptrList.begin();
    //vector<Observer *>::iterator it = vobjptrList.begin();
   
    while(it !=  vobjptrList.end() ){
        //it->(Observer *)vDisp();
        //(**it).vDisp();
        //*(*it).vDisp();
        //(Observer *)(*it).vDisp();
        
        (*it)->vDisp();//Uses polymorphism to print out the right derived classes.
        it++;
    }
}

//Uses OO Polymorphism to update the right derived object.
void Car::vUpdate()
{
    auto it = vobjptrList.begin();
   
    while(it !=  vobjptrList.end() ){
        (*it)->vUpdate();
        it++;
    }
}

int
main(void)
{
    Car *car = new Car();
    //Car car;  <==== Giving by address caused compilation error.
    //                How does C++ know this is C address operator vs C++ reference address?
    
    //Not sure how this works>  Putting 2 cars on the left, 3 cars on the right and 1 car in the middle.
    Leftobserver leftobj(car);
    Leftobserver leftobj1(car);
    Rightobserver rightobj(car);
    Rightobserver rightobj1(car);
    Rightobserver rightobj2(car);
    Centralobserver centerobj(car);

    car->vDisp();
    
    char cPressed;
    bool bBreakLoop = false;
    
    while( bBreakLoop == false )
    {
        cin >> cPressed;
        
        switch(cPressed)
        {
            case 'l':
                car->vSetPosition(-1);
                break;
            case 'r':
                car->vSetPosition(1);
                break;
            case 'c':
                car->vSetPosition(0);
                break;
            case '0':
                bBreakLoop = true;
                break;
            default:
                cout << "careful driving" << endl;
                break;
        }
    }
    
    return 0;
}