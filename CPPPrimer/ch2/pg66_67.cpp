#include <iostream>
//20 21
//42 43
using namespace std;

//causes compilation error
// need to compile with -std=c++11 option.
// g++ -std=c++11 pg66_67.cpp

constexpr int mf = 20;
constexpr int limit = mf + 1;
int j = 43;
constexpr int i = 42;
constexpr const int *p = &i;
constexpr int *p1 = &j;


int
main()
{
    
    cout << mf << " " << limit << endl;
    
    cout << *p << " " << *p1 << endl;
    return 0;
}