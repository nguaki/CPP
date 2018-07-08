///////////////////////////////////////////////////////////////////////////////
// Sep 24, 16
//
// Study of Queue data structure in C++.
//
// Great data structure when data needs to be pushed/popped from the front
// or the end.
//
// Note that Queue has only one entry point which is the back and only one
// exit point which is front.
// But Deque has 2 entry points and 2 exits points.
//
// OUTPUT
//one
//two
//three
//four
//five
//six
//===============================
//two
//three
//four
//five
//A
//P
//R
//Z
//
// July 7, 2018                 What is important is the real world scenario where
//                              deque is must to have.
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int
main()
{

    deque<string> dqDeque;
    deque<char>   dqAlpha;
    
    //Enters from the back.
    dqDeque.push_back("four");
    dqDeque.push_back("five");
    dqDeque.push_back("six");
    //queue now has "four", "five", "six"
    
    //Enters from the front.
    dqDeque.push_front("three");
    dqDeque.push_front("two");
    dqDeque.push_front("one");
    
    for(int i=0; i<dqDeque.size(); i++){
        cout << dqDeque[i] << endl;
    }
    
    //Deletes last one.
    dqDeque.pop_back();
    //Deletes the first one.
    dqDeque.pop_front();
    
    cout << "==============================="  << endl;
    for(int i=0; i<dqDeque.size(); i++){
        cout << dqDeque[i] << endl;
    }
   
    dqAlpha.push_back('P');
    dqAlpha.push_back('A');
    dqAlpha.push_back('Z');
    dqAlpha.push_back('R');

    sort( dqAlpha.begin(), dqAlpha.end());
    
    for(int i=0; i<dqAlpha.size(); i++){
        cout << dqAlpha[i] << endl;
    }

    
    return 0;
}
