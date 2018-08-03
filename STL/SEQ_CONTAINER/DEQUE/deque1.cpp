////////////////////////////////////////////////////////////////////////////////
//Oct 6, 2016
//
// Demonstrates the at(), insert() of deque.
// Also demonstrates usage of iterator to insert into deque.
//
//OUTPUT:
//Found at 2
//five
//two
//four
//three
//two
//one
//==============================
//five
//two
//four
//three
//two
//one
//
// June 20, 18    Since dqueue is a linear data structure, index can be used
//                to print out values.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <deque>

using namespace std;

int find( const deque<string> &deQue, const string &sValue){
    
    
    for(int i = 0; i<deQue.size(); i++){
        if( deQue.at(i) == sValue ){
            return i;
        }
    }
    return -1;
}

int
main()
{
    deque<string> dqValues;
    int iIndex;
    
    dqValues.push_back("five");
    dqValues.push_back("four");
    dqValues.push_back("three");
    dqValues.push_back("two");
    dqValues.push_back("one");
    
    iIndex = find(dqValues, "three");
    
    if(iIndex > 0 )
        cout << "Found at " << iIndex << endl;
    else
        cout << "Not found" << endl;
        
    deque<string>::iterator dqIter = dqValues.begin(); //Start from beginning which 
                                                       //has the value 'five'.
    
    dqIter++; //Go to next.  The value is 'four'.
    
    dqValues.insert(dqIter, "two" ); //Place 'two' at this location. So between
                                     //'five' and 'four'.
    for( dqIter = dqValues.begin(); dqIter < dqValues.end(); dqIter++){
        cout << *dqIter << endl;
    }
    cout << "=============================="  << endl;
    for( int i=0; i<dqValues.size(); i++){
        cout << dqValues[i] << endl;
    }
    return 0;
}