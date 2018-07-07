#include <iostream>
using namespace std;

int
main()
{
    int iPos = 0;
    string key;
    
    //key = "1048576";
    key = "2097152";

    string str = "2222222";
    
    while((iPos = str.find(key, iPos)) != string::npos) {
        cout << "FOUND " << endl;
    }

    cout << iPos << endl;
}