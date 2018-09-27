//Sep 25, 18
//Note that these are not ordered by keys.
//Aeter  32
//Zeter  42
//Peter  62

#include <iostream>
#include <unordered_map>

using namespace std;

int
main()
{
    unordered_map<string,int> um;
    
    um.insert(make_pair("Peter", 62));
    um.insert(make_pair("Zeter", 42));
    um.insert(make_pair("Aeter", 32));
    
    for( auto i : um ){
        cout << i.first << "  " << i.second << endl;
    }
        return 0;
}