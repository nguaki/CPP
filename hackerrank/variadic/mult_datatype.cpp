// Oct 17, 16
//
// Allows multiple data types.
//
//23 45.67
//Angela jkjjlkj

#include <iostream>

using namespace std;
    
template <class T1, class T2>
class MyClass{
    T1  t1;
    T2  t2;
    
    public:
        MyClass(T1 t1, T2 t2):t1(t1), t2(t2){};
        void vDisplay(){
            cout << t1 << " " << t2 << '\n';
        }
};

int
main()
{
    MyClass<int,float>     obj1( 23, 45.67 );
    MyClass<string,string> obj2( "Angela", "jkjjlkj" );
    
    obj1.vDisplay();
    obj2.vDisplay();

    return 0;
}