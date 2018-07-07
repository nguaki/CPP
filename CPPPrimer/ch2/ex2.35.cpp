//  42 42 42 42 42 42
#include <iostream>

using namespace std;

int
main()
{
    const int i = 42;
    auto j = i;        // j is int.
    const auto &k = i; // k is auto int&
    auto *p = &i;      // p is const int *
    const auto j2 = i, // j2 is const int
          &k2 = i;     // k2 is const int&;

    cout << i << " " << j << " " << k << " " << *p << " " << j2 << " " << k2 << endl;
    return 0;
}