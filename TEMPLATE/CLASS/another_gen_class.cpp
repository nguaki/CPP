//////////////////////////////////////////////////////////////////////////////
// July 7, 18
//
// Simple demonstration of generic template class.
//
//OUTPUT
//4
//5
//Sum is 9
//1.1
//2.2
//Sum is 3.3
//////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <class T>
class Add{
    T a[2];
    
    public:
        Add(){ cin >> a[0] >> a[1]; }
        T tDispSum(){ return a[0]+a[1]; }
};

int
main(void)
{
    Add<int> A;
    cout << "Sum is " << A.tDispSum() << endl;
    
    Add<float> B;
    cout << "Sum is " << B.tDispSum() << endl;
    
    return 0;
}