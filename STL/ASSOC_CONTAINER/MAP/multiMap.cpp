//////////////////////////////////////////////////////////////////////////////
//
// Sep 28, 16
// Demonstration of search() method of multimap data structure.
// Also demonstates the iterator to list.
//
//search for:kim
//kim:1234
//kim:2222
//kim:3333
//kim:4444
//
// Uses  insert(), find(),  upper_bound() methods.
//
// June 20, 18     Iterates over the original list.
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int
main(){
    
    multimap<string,string> mulmPhoneInfo;
    
    //Why does it have to typecast when it was already declared?
    mulmPhoneInfo.insert(pair<string,string>("kim", "1234"));
    mulmPhoneInfo.insert(pair<string,string>("jack", "1234"));
    mulmPhoneInfo.insert(pair<string,string>("kim", "2222"));
    mulmPhoneInfo.insert(pair<string,string>("afadf", "1234"));
    mulmPhoneInfo.insert(pair<string,string>("kim", "3333"));
    mulmPhoneInfo.insert(pair<string,string>("werer", "1234"));
    mulmPhoneInfo.insert(pair<string,string>("kim", "4444"));
   
    //Iterate thru and print out all inputs.
    multimap<string,string>::iterator multIterX = mulmPhoneInfo.begin();
    while( multIterX != mulmPhoneInfo.end()){
            cout << multIterX->first << ":" << multIterX->second << endl;
            multIterX++;
    }
    
    
    string sName;
    cout << "search for:";
    cin  >> sName;
    
    //Somehow this 2 lines iterates only the ones with the sName.
    multimap<string,string>::iterator multIter = mulmPhoneInfo.find(sName);
    multimap<string,string>::iterator multIterLast = mulmPhoneInfo.upper_bound(sName);
    
    for( ; multIter != multIterLast; multIter++ ){
        cout << multIter->first << ":" << multIter->second << endl;
    }
    
    return 0;
}