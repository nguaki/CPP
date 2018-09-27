//Sep 24, 2018
//Faster and easier way to convert one type to another.
//Don't need to remember atoi, itoa, stoi ...
//All you need is to remember lexical_cast<int>.
#include <string>
#include <array>
//#include "boost\lexical_cast.hpp"   This is for windows
#include <boost/lexical_cast.hpp>

using namespace std;

using boost::lexical_cast;
using boost::bad_lexical_cast;

int
main()
{
    int iVal = 23;
    
    string str = lexical_cast<string>(iVal);
    cout << str << endl;
   
    str = "Message: " + lexical_cast<string>('A') + "=" + lexical_cast<string>(34.5);
    cout << str << endl;
   
    
    //Required -std=c++11
    array<char, 64> msg = lexical_cast<array<char,64>>(23);
    
    //for(int i=0; i<msg.sizeof(); i++ ){
    //    cout << msg[i] << endl;
    //}
    //    cout << msg << endl;
    
    iVal = lexical_cast<int>("3456");
    cout << iVal << endl;
    
    try{
        iVal = lexical_cast<int>("56.78");  
    }catch(bad_lexical_cast &e){
        cout << "Exception caught: " << e.what() << endl;
    }
    
    iVal = lexical_cast<int>("5678xx");   //bad
    iVal = lexical_cast<int>("5678xx",4);   //good only 4 char will be converted
    return 0;
}