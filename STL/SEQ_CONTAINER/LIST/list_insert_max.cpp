///////////////////////////////////////////////////////////////////////////////
// Sep 28, 16
//
// Adds a value to a list data structure if the value is greater than
// the max value in the list.
//
//
//Enter a value:5
//Enter a value:5
//Enter a value:7
//Enter a value:9
//Enter a value:5
//Enter a value:5
//Enter a value:4
//Enter a value:3
//Enter a value:2
//Enter a value:1
//0
//5
//7
//9
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <list>

using namespace std;

void vInsertMax( list<int> &liList, int iValue ){
    
    int iMax;
    
    liList.sort();
    iMax =  liList.back();  //Obtain the last value of the list.
    
    if( iValue > iMax ){
        cout << "Inserting " << iValue << " at the end" << endl;
        liList.push_back(iValue);  //Enter the new greatest value to the end.
    }
}

int
main()
{
    list<int> liValues;
    int iValue;
    
    liValues.push_back(0);
    
    for( int i=0; i<10; i++){
        cout << "Enter a value:";
        cin >> iValue;
        vInsertMax( liValues, iValue);    
    }
 
    list<int>::iterator liIter = liValues.begin();
    
    while(liIter != liValues.end()){
        cout << *liIter++ << endl;
    }
   
    //Index doesn't work since this is a double linked list.
    //for( int i=0; liValues.size(); i++) cout << liValues[i] << endl;   
    return 0;
}