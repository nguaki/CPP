//Oct 6, 16
//
//Creates distinct set of characters.
//Note that in order for this to work, all the similar characters 
//must be next to each other.
//
//OUTPUT:
//aaaaaabbbbbcccceeeerrrrtyu
//abcertyu

#include <iostream>
#include <algorithm>

using namespace std;
int
main(){

    string s;
    
    cin >> s;
    cout << s << endl;
    
    s.erase(unique(s.begin(), s.end()),s.end());
    
    cout << s;

}