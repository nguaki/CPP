
//Date: June 7. 2018
//Description: Changing namespace name.
//Output:10
#include <iostream>

using namespace std;

namespace abcdefghijklmnop{
	int iX;
	namespace aaaaaaaaaa{
		void vDisplay(){ cout << iX << endl; }
	};
};

int
main()
{
	namespace A = abcdefghijklmnop;
	namespace B = A::aaaaaaaaaa;

	A::iX = 10;
	B::vDisplay();

	return 0;
}

