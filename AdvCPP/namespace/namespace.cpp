 //Aug 25, 16
//Using namespace and scope operator to print out.
//
//
//OUTPUT
//10
//5
//2
//1
//10
//5
//2
//1

#include <iostream>

using namespace std;

namespace Currency{
    const int Ten = 10;
    const int Five = 5;
    const int Two = 2;
    const int One = 1;
};

int main()
{
    using namespace Currency;
    
    cout << Ten << endl;
    cout << Five << endl;
    cout << Two << endl;
    cout << One << endl;
    

    cout << Currency::Ten << endl;
    cout << Currency::Five << endl;
    cout << Currency::Two << endl;
    cout << Currency::One << endl;
    
    
    return 0;
}
