// June 7. 2018
// Explanation of nested namespace.
// OUTPUT:
// 12
#include <iostream>

using namespace std;

namespace one{
	int i;

	namespace one{   //Nested namespace 
		int i;
	};
};

int
main(void)
{
	one::one::i = 10; //Specifies variable using namespace.

	using namespace one::one;
	i++;
	i++;
	cout << i << endl; //Since using was defined above, don't need to use
                           //scope resolution operator.

	return 0;
}
