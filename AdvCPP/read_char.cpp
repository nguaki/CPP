//Aug 21, 2016
//Reads a character at a time.
#include <iostream>

using namespace std;

int
main()
{
  char c;
  
  cin.get(c);
  cout << c;
  
  do{
    cin.get(c);
    cout << c;
  }while(!cin.eof());  //Treats cin as if a file.  ^D is considered as a eof.
  
   
  
}