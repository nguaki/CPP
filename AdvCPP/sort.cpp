//Sep 28, 16
//Demonstration of vector data structure and sort() algorithm.
//And also the demonstration of the power of template <typename T>.
//
//
//OUTPUT
//4  6  2  4  5  8  9  0  2  55  
//0  2  2  4  4  5  6  8  9  55  
//In  the  beginning  God  created  the  heaven  and  the  earth  
//God  In  and  beginning  created  earth  heaven  the  the  the  
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//This demonstrates the power of templates by
//displaying both the integer and strings.
template <typename T>
void 
vDisplay(const vector<T> &vcValues){
    
    for(int i=0; i<vcValues.size();i++){
        cout << vcValues[i] << "  ";
    }
    cout << endl;
}

int
main()
{
    const int ciSize = 10;
    int iValues[] = { 4, 6, 2, 4, 5,8,9,0,2,55};
    
    //I am not going to argue, but second parameter is important.
    vector<int> vecValues(iValues, iValues+ciSize);
    
    //Below line compiles okay but does not generate a good result.
    //This demonstrates the importance of second parameter.
    //vector<int> vecValues(iValues, iValues);
    
    vDisplay(vecValues);
    
    //You would think vDisplay.sort() since OO.  But the only way to sort vectors is using
    //sort() built-in function.
    sort( vecValues.begin(), vecValues.end() );
    
    vDisplay(vecValues);
    
    string sValues[] = { "In", "the", "beginning", "God", "created",
                         "the", "heaven", "and", "the", "earth" };
                             
    //Intersting way to construct an array of string.
    vector<string> vec_sValues(sValues, sValues+ciSize);
    
    vDisplay(vec_sValues);
    
    sort( vec_sValues.begin(), vec_sValues.end());
    
    vDisplay(vec_sValues);
    
    return 0;
}