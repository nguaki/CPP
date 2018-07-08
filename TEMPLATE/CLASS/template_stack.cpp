//////////////////////////////////////////////////////////////
//  Aug 20, 16
//
//  Demonstration of template to make a class a generic class.
//  defines a class of multiple data types using template..
//
// OUTPUT:
//90
//============================
//9
//============================
//3.65657
//============================
//5.44343
//============================
//3.23
//============================
//5.23
//============================
//ghi
//============================
//abc
//
// June 20, 2018    template<class T> and template<typename T> both work.
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//template <typename T>  // T can be int, string, double, float
template <class T>  // T can be int, string, double, float
class Stack{
    private:
        T Values[100];
        int iStackIndex; 
        
    public:
        Stack(){ iStackIndex = -1; }
        
        void Push( T Value ){
            iStackIndex++;
            Values[iStackIndex] = Value;
        }
        
        T Pop(){
            T Value = Values[iStackIndex];
            iStackIndex--;
            return (Value);
        }
        
        T Peek(){
            return Values[iStackIndex];
        }
        
};

int
main()
{
    Stack<int>    iStack;
    Stack<double> dStack;
    Stack<float>  fStack;
    Stack<short>  sStack;
    Stack<string>  strStack;
    
    iStack.Push(5);
    iStack.Push(4);
    iStack.Push(9.56);//store as 9
    iStack.Push(90.78);//store as 90

    cout << iStack.Peek() << endl;
    cout << "============================" << endl;
    iStack.Pop();
    cout << iStack.Peek() << endl;
    cout << "============================" << endl;

    dStack.Push(5.443434);
    dStack.Push(4.565656);
    dStack.Push(3.656565);

    cout << dStack.Peek() << endl;
    cout << "============================" << endl;
    
    dStack.Pop();
    dStack.Pop();
    cout << dStack.Peek() << endl;
    cout << "============================" << endl;

    fStack.Push(5.23);
    fStack.Push(4.34);
    fStack.Push(3.23);

    cout << fStack.Peek() << endl;
    cout << "============================" << endl;

    fStack.Pop();
    fStack.Pop();
    cout << fStack.Peek() << endl;
    cout << "============================" << endl;

    strStack.Push("abc");
    strStack.Push("def");
    strStack.Push("ghi");

    cout << strStack.Peek() << endl;   //Gets the value of the top of the stack.
    cout << "============================" << endl;
   
    strStack.Pop();
    strStack.Pop();
    cout << strStack.Peek() << endl;

}