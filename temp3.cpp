#include <iostream> 
#include <stdio.h>  
#include <string>

using namespace std;  

int main() { 
  // Output prompt 
  cout << "Press any key to continue..." << endl; 

  // Set terminal to raw mode 
  system("stty raw"); 

  // Wait for single character 
  char input = getchar(); 
  string s;
  int i = 0;
	while( input >= '0' and input <='9')
	{
  		// Echo input:
		cout << "--" << input << "--";
		s = s + input;
		//s[i++] = input;		
		cout << "s=" << s << endl;
  		input = getchar(); 
	}

	cout << "s=" << s << endl;
	double d;
	d = stod(s);
	cout << "d=" << d << endl;

  // Reset terminal to normal "cooked" mode 
  system("stty cooked"); 

  // And we're out of here 
  return 0; 
}
