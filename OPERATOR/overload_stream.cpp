// June 5. 2018
// Stream overload functions.
#include <iostream>
#include <string>

using namespace std;

class S{
	string sName;
	int    iAge;

	public:
		void vDisp(){ cout << sName << "  " << iAge << endl; }
		friend ostream &operator<< (ostream &, S & );   //Overload output
		friend istream &operator>> (istream &, S & );   //Overload input
};

ostream & operator<< (ostream &output, S &s)
{
	output << s.sName << "  " << s.iAge << endl;
	return output;
}
istream & operator>> (istream &input, S &s)
{
	input >> s.sName >> s.iAge;
	return input;
}
int
main(void)
{
	cout << "Enter data:";

	S s;

	cin >> s;   //Calls operator >>

	cout << s;  //Calls operator <<

	return 0;
}
