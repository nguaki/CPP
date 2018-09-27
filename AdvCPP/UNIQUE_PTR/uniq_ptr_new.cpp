#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Dog {
    public:
        string m_name;
        Dog(){ cout << "nameless dog has been created" << endl; }
        ~Dog(){ cout <<  m_name + "is destroyed" << endl; }
        void vBark(){ cout << "Grrrrr" << endl; }
        Dog(string sName){ m_name = sName; cout << sName + " is creatd." << endl; }
}; 

void
test()
{
    unique_ptr<Dog> pobjDog(new Dog("Gunner"));
    pobjDog->vBark();
    
    //unique_ptr automatcally deletes the pointer.
    //The problem with the old way is that the 
    //delete line may not even reach.
    //So in other words, it does the garbage collection.
    //delete objDog;
    
    //This releases the memory.
    pobjDog.release(); 
   
    //pobjDog.reset(); 
    //pobjDog.reset("Smokey"); 
    if (pobjDog==NULL)
        cout << "pobjDog is empty \n";
}

int
main(void)
{
   test();
   return 0;
}