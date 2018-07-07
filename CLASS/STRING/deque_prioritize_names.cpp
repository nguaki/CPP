//
// Oct 6, 16
//
//  Demonstrates string class functionalities such as end(), find() and substr().
//
//  Reads line at a time.  If a string contains 'p' as lastname initial, the name will be
//  inserted to the front, otherwise it will be inserted to the back.
//
//  priority.txt contains following data:
//  xyz
//  abc
//  Matthew p
//  Angel p
//  ttt
//  aaa
//
//strIter = 
//after decrement = z
//strIter = 
//after decrement = c
//strIter = 
//after decrement = p
//strIter = 
//after decrement = p
//strIter = 
//after decrement = t
//strIter = 
//after decrement = a
//Angel
//Matthew
//xyz
//abc
//ttt
//aaa
//
#include <iostream>
#include <fstream>
#include <deque>
#include <string>

using namespace std;

int
main()
{
    deque<string> dqNames;
    ifstream      ifInput;
    string        sLine, sName;
    int           iPos;
    
    ifInput.open("priority.txt");
    
    while(!ifInput.eof()){
        getline(ifInput,sLine);
        
        string::iterator strIter = sLine.end();
        cout << "strIter = " << *strIter << endl;
        --strIter;  //Goes to previous character.
        cout << "after decrement = " << *strIter << endl;
        
        iPos = sLine.find(' ');
        sName = sLine.substr(0,iPos);
        
        if(*strIter == 'p')
            dqNames.push_front(sName);
        else
            dqNames.push_back(sName);
            
    }
    
    deque<string>::iterator dqIter = dqNames.begin();
    
    while( dqIter != dqNames.end()){
        cout << *dqIter++ << endl;
    }
    
    return 0;
}