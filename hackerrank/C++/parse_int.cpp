//Hackerrank.
//
// Parse integers from a string "9,8,89,0".
//
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(const string &str) {
   // Complete this function
   int  i;
   char c;
   stringstream ss(str);    //copies a string to stringstream.
   vector<int> vi;
    
    while( ss >> i){   //Here is the trick.  This will read an integer or end of string.
        vi.push_back(i);//populate vector.
        ss >> c;      //Read a comma
    }    
    return vi;
    
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
