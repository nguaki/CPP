//
// Demonstrated a deep copy by customized copy constructor.
//
// June 20, 18   Commented.
//
#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        string *name;
        int age;

    Person(string name,int age){
    this->name = new string(name);
    this->age = age;
    }

    //Copy constructor.  Deep copy.
    Person(const Person &p){
    cout << "copy constructor is called "<<endl;
    name = new string(*p.name);
    age = p.age;
    }

    void changeNameandAge(string name,int age){
    *(this->name) = name;
    this->age = age;
    }

    void introduce(){
    cout << "hey i am "<<*name<<" and i am "<<age<<" years old"<<endl;
    }
};

int main()
{
    Person anil("1anil",24);
    anil.introduce();

    Person duplicateanil = anil;  //Copy constructor is called at declaration.
    duplicateanil.introduce();

    anil.changeNameandAge("anil shetty",100);
    anil.introduce();
    duplicateanil.introduce();
    return 0;
}