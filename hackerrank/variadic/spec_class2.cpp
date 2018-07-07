// Oct 17, 2016
// 
// Using specific class form generic class.
//
//
//
#include <iostream>

using namespace std;

template<class T>
class MyClass{
    T t1;
    
    public:
        MyClass(T t1):t1(t1){}
        
        void vDisplay()
        { 
            cout << "general class" << '\n';
            cout << t1 << '\n'; 
        }
};

template<>
class MyClass<int>{
    int t1;
    
    public:
        MyClass(int t1):t1(t1){}
        
        void vDisplay(){ 
            cout << "specific class" << '\n';
            cout << t1 << '\n'; 
            
        }
};
int
main()
{
    MyClass<string> objMyClass("ngdeedga");
    MyClass<float>  objMyClassf(7.567);
    MyClass<char>   objMyClassc('c');
    MyClass<int>    objMy(56);
    
    objMyClass.vDisplay();
    objMyClassf.vDisplay();
    objMyClassc.vDisplay();
    objMy.vDisplay();

    return 0;

}