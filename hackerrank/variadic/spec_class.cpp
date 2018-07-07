// Demonstrates specialiezed class.
//
//
//This is not a char 1
//This is not a char 1.567
//This is not a char Hello Matthew
//this is a char M

#include <iostream>
using namespace std;

template <typename T>
class punky{
    T gVar;
    public:
        punky(T gVar):gVar(gVar){}
        //void vPrint(T gVar){ cout << "This is not a char " << gVar << endl; }
        void vPrint(){ cout << "This is not a char " << gVar << endl; }
};

//This is a specialize template class definition.
template <>   // <=== Notice empty type definition.
              // There will be an error message if this template<> is not declared.
class punky<char>{  // <=== Notice the data type definition at the class level.
    char gVar;
    public:
        punky(char gVar):gVar(gVar){}
    
        void vPrint(){ cout << "this is a char " << gVar << endl; }
};



int 
main()
{
    punky<int> oPunky1(1);  //Must have template argument defined.
                           //There will be error message without it.

    punky<double> oPunky2(1.567);
    punky<string> oPunky3("Hello Matthew");
    punky<char> oPunky4('M');
    
    oPunky1.vPrint();
    oPunky2.vPrint();
    oPunky3.vPrint();
    oPunky4.vPrint();

    
    
    return 0;
}