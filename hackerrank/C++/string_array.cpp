#include <iostream>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string strNumbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int i;
    
    cin >> i;
    
    if( (i>=1) && (i<=9) ){
        cout << strNumbers[i-1] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }
    
 
   return 0;
}
