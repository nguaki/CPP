//Getting all permutation using sort() and next_permutation() algorithm.
#include <iostream>
#include <algorithm>

using namespace std;

void
vPermute(string str)
{
    sort(str.begin(), str.end());
    
    do{ 
        cout << str << endl; 
    }while(next_permutation(str.begin(), str.end()));
}

int
main(void)
{
    string str("MAN"); 0;
    vPermute(str);

    return 0;
}