///////////////////////////////////////////////////////////////////////////////
//
//  Aug 21, 16
//
//  Uses template to define a class/function with generic data types.
//  It allows a class/functions to handle multiple data types.
//  Other alternatives is to declare a class/function for each data type.
//
//  Uses index to list items one at a time.  There is no need for iterator.
//  
//  List string first.
//  List int    second.
//  Display string and int values using same class.
//
//OUTPUT:
//
//Beef
//Celery
//Steak seasoning
//Steak seasoning
//Celery
//Beef
//89
//90
//95
//95
//90
//89
//
//July 7, 18      Note that template <typename T> and template <class T> both
//                work.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//template <typename T>
template <class T>
class List{
    private:
        vector<T> tValues;
    public:
        List(){}
        void vAdd(T tValue){
            tValues.push_back(tValue);
        }
        void vDisplay(){
            for( int i=0; i<tValues.size(); i++ ){ //Note that iterator isn't necessary.
                cout << tValues[i] << endl;
            }   
        }
        void vRevDisplay(){
            cout << "Reverse order" << endl;
            for( int i=tValues.size()-1; i>=0; i-- ){//Note that iterator isn't necessary.
                cout << tValues[i] << endl;
            }   

        }
};

int
main(){

    //Declares a List class with string data type.
    List<string> oGroceryList;  
    oGroceryList.vAdd("Beef");
    oGroceryList.vAdd("Celery");
    oGroceryList.vAdd("Steak seasoning");
    
    oGroceryList.vDisplay();
    oGroceryList.vRevDisplay();
    
    //Declares a List class with int data type.
    List<int> oQuizScores;    
    oQuizScores.vAdd(89);
    oQuizScores.vAdd(90);
    oQuizScores.vAdd(95);
    
    oQuizScores.vDisplay();
    oQuizScores.vRevDisplay();
    
    return 0;
}