////////////////////////////////////////////////////////////////////////////////
// Oct 4, 16
//
// set is a DS that allows only unique values.
// Demonstration of begin(), end(), insert().
//Enter a name:ab                                                                                                          
//Enter a name:abc                                                                                                         
//Enter a name:ab                                                                                                          
//Enter a name:abc                                                                                                         
//Enter a name:quit                                                                                                        
//ab  abc  
//
//Note that "ab" is repeated.But it is saved only once.
//Other than that, I don't see much difference to 
//vector.
// 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <set>

using namespace std;


int
main()
{
    set<string> stNames;
    string sName;
    
    do{
    
        cout << "Enter a name:";
        cin >> sName;
        
        stNames.insert(sName);
        
        
    }while( sName != "quit");
    
    
    set<string>::iterator stIter = stNames.begin();
    
    while( stIter != stNames.end()){
        cout << *stIter++ << "  ";
    }
    return 0;
}