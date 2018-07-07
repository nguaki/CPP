//Aug 21, 16
// Read entire line including a space.
#include <iostream>

using namespace std;

int
main()
{
  string name;
  
  cout << "Enter Name:";
  getline(cin, name);
  
  cout << name << endl;
}