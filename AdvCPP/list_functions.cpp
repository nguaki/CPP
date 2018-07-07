//
//  Sep 26, 16
//
// Demonstrates the functions of list including remove().
//
#include <iostream>
#include <list>

using namespace std;

void vDisplay( list<string> liNames ){
     list<string>::iterator nameIter = liNames.begin();
     
     while( nameIter != liNames.end() ){
         cout << *nameIter++ << endl;
     }
   
    cout << "================================" << endl;
}

int
main(){
    list<string> liNames;
    
    liNames.push_back("Jesus");
    liNames.push_back("Christ");
    liNames.push_back("Abraham");
    liNames.push_back("James");
   
    //Jesus
    //Christ
    //Abraham
    //James
    vDisplay(liNames);

    liNames.reverse();

    //James
    //Abraham
    //Christ
    //Jesus
    vDisplay(liNames);


    liNames.sort();
    
    //Abraham
    //Christ
    //James
    //Jesus
    vDisplay(liNames);

    //TOP:Abraham
    //BOTTOM:Jesus
    cout << "TOP:" << liNames.front() <<endl;
    cout << "BOTTOM:" << liNames.back() <<endl;
    
    liNames.push_front("David");
    liNames.push_front("Esther");
    liNames.push_front("Isaac");
    liNames.push_front("Karen");
    
    //Karen
    //Isaac
    //Esther
    //David
    //Abraham
    //Christ
    //James
    //Jesus
    vDisplay(liNames);
    
    liNames.pop_front();
    liNames.pop_front();

    //Esther
    //David
    //Abraham
    //Christ
    //James
    //Jesus
    vDisplay(liNames);
    
    liNames.pop_back();
    liNames.pop_back();

    //Esther
    //David
    //Abraham
    //Christ
    vDisplay(liNames);
    
    liNames.push_front("Abraham");
    liNames.remove("Abraham"); //Removes all occurrences of 'Abraham'.
    //Esther
    //David
    //Christ

    vDisplay(liNames);
    
    liNames.clear();
    vDisplay(liNames);

   

    return 0;
}