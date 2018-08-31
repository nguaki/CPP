//Getting all permutation using sort() and next_permutation() algorithm.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void
vPermute(string str)
{
    sort(str.begin(), str.end());
    
    do{ 
        cout << str << endl; 
    }while(next_permutation(str.begin(), str.end()));
    
    cout << "==============================" << endl;
    vector<char> vChar;
    
    vChar.push_back('M');
    vChar.push_back('A');
    vChar.push_back('N');
    
    //Must sort this, otherwise this won't work.
    sort(vChar.begin(), vChar.end());
    do{ 
        cout << vChar[0] << vChar[1] << vChar[2] << endl; 
    }while(next_permutation(vChar.begin(), vChar.end()));
    
}

int
main(void)
{
    string str("MAN"); 0;
    vPermute(str);

    return 0;
}