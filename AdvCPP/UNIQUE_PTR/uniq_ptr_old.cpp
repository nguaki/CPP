#include <string>
#include <iostream>

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
    Dog*  objDog = new Dog("Gunner");
    objDog->vBark();
    delete objDog;
}

int
main(void)
{
   test();
   return 0;
}