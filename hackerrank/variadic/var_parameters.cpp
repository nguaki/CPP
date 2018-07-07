// Oct 13, 16
//
//Demonstrates variadic ( unknown type and unknown size)
//
//1, 2, 3, 4
//1, 2, 3, 4, 5
//Hello, World, 2.3, 4.567, C, 1

#include <iostream>

using namespace std;

//This is a must otherwise there is a compilation error.
//This takes care of the last element.
template <typename T>
ostream &vPrint(ostream &os, const T &t )
{
    return os << t;     
}
    

template <typename T, typename... Args>  //Expansion pack
//The first t is for the first element.
//rest represents 0 or more elements.
ostream &vPrint(ostream &os, const T &t, const Args&... rest )
{
    os << t << ", ";
    
    return vPrint(os, rest...); //Recursive call.
}

int
main()
{
    vPrint(cout, 1,2,3,4);
    cout << endl;
    vPrint(cout, 1,2,3,4,5);
    cout << endl;
    vPrint(cout, "Hello", "World", 2.3, 4.567, 'C', true);
    cout << endl;

    return 0;
}