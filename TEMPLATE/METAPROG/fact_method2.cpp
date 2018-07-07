//June 21, 2018
//
//Demonstration of template meta programming.
//Second method of calculating fibonacci using template
//meta programming.
#include <iostream>
using namespace std;

//When changing the order of these 2 functions, I am getting:
//fact_method2.cpp:5:8: error: ‘Factorial’ is not a class template
//struct Factorial<0> 
//        ^
//fact_method2.cpp:6:1: error: explicit specialization of non-template ‘Factorial’
// {
// ^
//fact_method2.cpp:11:8: error: ‘Factorial’ is not a template type
// struct Factorial 
//        ^

template <int N>
struct Factorial 
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
    enum { value = 1 };
};
int main(void)
{
    int i = Factorial<4>::value;
    int j = Factorial<0>::value;
    //The following lines cause error messages.
    //warning:multi-character constant [-Wmultichar]
    //cout << Factorial<4>::value << '  '
    //    << Factorial<0>::value; 
    cout << i << endl;
    cout << j << endl; 
    return 0;
};