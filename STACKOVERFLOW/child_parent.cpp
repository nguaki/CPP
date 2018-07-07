#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Parent{
        public:
		Parent(){ pegged = 11; status = "Parent thingy";}
                int age;
                int pegged;
                // define those methods:
                int get_age(void);
                void (set_age(int AGE));
                string status;
};


//method get_age, gets age:
int Parent::get_age(void){
        return age;
}

//method set_age, sets age:
void Parent::set_age(int AGE){
        age = AGE;
}

class Child:public Parent{
        public:
                Child(){ stat = "Child"; }
		string stat;
};

int main(){

        //object gen1 is the parent
        Parent gen1;
        gen1.set_age(303);
        cout << "gen1's age: " << gen1.age << "\n";
        cout << "another way to find gen1's age: " << gen1.get_age() << "\n";
        cout << "gen1's pegged int" << gen1.pegged << "\n";

        cout << gen1.status << "\n";

        Child gen2;
        // if gen2 inherits its base class's public members, how to access one?
         gen2.set_age(243); 
        cout << "gen2's age: " << gen2.age << "\n";
        cout << "another way to find gen2's age: " << gen2.get_age() << "\n";
        cout << "gen2's *stat:" << gen2.stat << "\n";
        cout << "gen2.pegged: " << gen2.pegged << "\n";
        return 0;
}
