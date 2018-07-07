//Date: June 7, 2018
//Description: Example inline keyword for namespace.
//             It acts as if the namespace is anonymous.
//             It allows to access its functions without the usage of namespace scope.
//Output:
//Version A
//Version B
//Version C
//Whats up
#include <iostream>

using namespace std;

namespace version{

	namespace versionA{
		void vDisp(){
			cout << "Version A" << endl;
		}
	};

	namespace versionB{
		void vDisp(){
			cout << "Version B" << endl;
		}
	};

inline	namespace versionC{
		void vDisp(){
			cout << "Version C" << endl;
		}
	};

	namespace versionC{
		void vWhatsUp(){
			cout << "Whats up" << endl;
		}
	};
};

int
main(void)
{
	version::versionA::vDisp();
	version::versionB::vDisp();

	version::vDisp();
	version::vWhatsUp();

	return 0;
}
