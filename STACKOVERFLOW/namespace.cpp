#include <iostream>

using namespace std;

namespace A {
  namespace B {
	namespace C {}
    /*
	namespace { // Unnamed

	void vDisplay(){ cout << "From unnamed" << endl;}
    }
   */
  }
}
namespace A::B::C{  };
// After
/**
namespace A::B:: {
  namespace { // Forced to remain as a separate definition
	void vDisplay(){ cout << "From unnamed" << endl;}
  }
}
**/
int
main(void)
{
	A::B::vDisplay();

	return 0;
}
