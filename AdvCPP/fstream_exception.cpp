///////////////////////////////////////////////////////////////////////////////
//Date:
//Description:
//             Declares file exceptions.
//             Catch file exceptions.
//Output:
//97
//98
//99
//100
//101
//102
//103
//10
//basic_ios::clear
//File cannot open
//
// Jun 21, 18   Where is throw? I think it is invoked from file.open().
//              Why 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int
main(){ 
    
    ifstream file;
    
    file.exceptions( ifstream::failbit |  ifstream::badbit);
    
    try{
        file.open("abc.txt");
        while(!file.eof()){
            cout << file.get() << endl;
        }
    }
    
    catch(ifstream::failure e){
        cout << e.what() << endl;
        cout << "File cannot open" << endl;
        return 1;
    }
    
    file.close();
    
    return 0;
}