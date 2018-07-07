//////////////////////////////////////////////////////////
// Aug 15, 16
// Instatiation of array of objects.
// Uses a pointer to the object to traverse.
// OUTPUT:
//size of samp = 4  
//size of temp = 8
//1
//2
//3
//4
//5
//6
//7
//8
//
// Note that size of a class only refers to data, not functions.
// I am not sure why the size of temp is 8. (May 1, 2018: It is like this. sizeof(int) is 4 but
// sizeof(int *) is 8 since the memory address can be 8 bit long. Same reasoning.
//
// May 1, 2018  - Explained why sizeof(*temp) is 8.
////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;

class samp{
    int a;
    public:
        samp(int n){ a=n; }
        int get_a(){ return a; }
};

int
main(){
    samp *temp;

    //This looks weird from C point of view. But this is legit in C++.
    samp ob[4][2] = {
        1,2,
        3,4,
        5,6,
        7,8
    };
    
    temp = &ob[0][0];
    cout << "size of samp = " << sizeof(samp) << endl;  // end up 4
    cout << "size of temp = " << sizeof(temp) << endl;  // end up 8
    for(int i=0; i<8; i++){
        cout << temp->get_a() << endl;
        temp++;
    }
}