//Calling const
//Calling NON-const
//Calling const

#include <iostream>

using namespace std;

class Dog
{
    string  name;
    int     age;
    
 public:
    void setAge( const int& age1 )
    { 
        cout << "Calling const" << endl;
        age = age1; 
    }
    void setAge( int &age1 )
    {
        cout << "Calling NON-const" << endl;
        age = age1; 
    
    }
};

int
main()
{
    Dog dog;
    
    dog.setAge( 5 );
    
    int age = 10;
    dog.setAge( age );
    
    const int cage = 50;
    dog.setAge( cage );
    
    return 0;
}