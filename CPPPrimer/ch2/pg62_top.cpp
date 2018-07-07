//50 50 50
 #include <iostream>

using namespace std;

int
main()
{
    int i = 50;
    int &ri1 = i;
    const int &ri2 = i;
    
    cout << i << " " << ri1 << " " << ri2 << " " << endl;
    
    ri1 = 100;

    //compilation error
    //error: assignment of read-only reference ‘ri2’
    ri2 = 200;
    return 0;
}