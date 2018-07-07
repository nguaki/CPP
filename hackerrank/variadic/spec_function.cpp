//  Oct 17, 16
//  Uses specialized function which overloads generalized function.
//
//
#include <iostream>

using namespace std;

//Note that when I use 'const int &it', there is an error message.
template <typename T>
T tReturn( T t ){
    cout << "Using generic function" << '\n';
    return t;
}

//Note that when I use 'const int &it', there is an error message.
template <>
int tReturn( int it ){
    cout << "Using specific function" << '\n';
    return it;
}

int
main()
{

    cout << tReturn("Matthew Che") << '\n';
    cout << tReturn( 394.56 ) << '\n';
    
    cout << tReturn( 1 ) << '\n';
    
    return 0;
}