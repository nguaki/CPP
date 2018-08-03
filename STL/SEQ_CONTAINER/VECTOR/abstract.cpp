////////////////////////////////////////////////////////////////////////////////
// Aug 20, 16
// Declares pure virtual methods(aka abstract methods) for 
// derived classes to define.
//
// This is another illustration of polymorphism which happens
// during the runtime.
//
// Note that vector takes in one type.
// However, in this case it takes in both Dog and Cat.
// That is because  Dog and Cat share the same base class.
//
//OUTPUT:
//
//Meow meow
//Bark bark
//Meow meow
//Bark bark
//
//          [ ANIMAL ]
//           ^      ^
//           |      |
//           |      |
//         [CAT]   [DOG]
//
//Jun 20, 18      Added comments on vector template where template is 
//                a pointer to base class.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

class Animal{
    public:
        virtual void makesSound() = 0;//Pure virtual method
};

class Dog: public Animal{
    public:
        void makesSound(){
            cout << "Bark bark" << endl;
        }
};

class Cat: public Animal{
    public:
        void makesSound(){
            cout << "Meow meow" << endl;
        }
};
int 
main()
{
    Cat cat;
    Dog dog;
    
    //This gets the pointers to Animals. 
    vector <Animal*> animals; 
    
    cat.makesSound();
    dog.makesSound();
    
    //Add the addresses of each animal.
    animals.push_back(&cat);
    animals.push_back(&dog);
    
    for( int i=0; i<animals.size(); i++){
        animals[i]->makesSound();
    }
    
    return 0;
}