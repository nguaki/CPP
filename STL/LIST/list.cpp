////////////////////////////////////////////////////////
//Sep 28, 16
//
//Demonstrates the functions of list data structure.
//    Usage of these functions: push_back(), begin(), end(), sort(), reverse(),
//                              front(), back().
//
//Jesus
//Christ
//Abraham
//James
//===================================
//Reverse Order
//James
//Abraham
//Christ
//Jesus
//===================================
//Sort Order
//Abraham
//Christ
//James
//Jesus
//===================================
//TOP:Abraham
//BOTTOM:Jesus
////////////////////////////////////////////////////////
#include <iostream>
#include <list>

using namespace std;

int
main(){
    list<string> liNames;
    
    liNames.push_back("Jesus");
    liNames.push_back("Christ");
    liNames.push_back("Abraham");
    liNames.push_back("James");

    //OUTPUT
    //--------
    //Jesus
    //Christ
    //Abraham
    //James
   
    list<string>::iterator nameIter = liNames.begin();
    while( nameIter != liNames.end() ){
        cout << *nameIter++ << endl;
    }
    cout << "==================================="  << endl;
    cout << "Reverse Order"  << endl;
    //James
    //Abraham
    //Christ
    //Jesus

    liNames.reverse();
    list<string>::iterator revIter = liNames.begin();
    while( revIter != liNames.end() ){
        cout << *revIter++ << endl;
    }
    cout << "==================================="  << endl;
    cout << "Sort Order"  << endl;
  

    //Abraham
    //Christ
    //James
    //Jesus

    liNames.sort();
    list<string>::iterator sortIter = liNames.begin();
    while( sortIter != liNames.end() ){
        cout << *sortIter++ << endl;
    }
    cout << "==================================="  << endl;
    cout << "TOP and BOTTOM"  << endl;

    //TOP:Abraham
    //BOTTOM:Jesus
    cout << "TOP:" << liNames.front() <<endl;
    cout << "BOTTOM:" << liNames.back() <<endl;
    
    return 0;
}