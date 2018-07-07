#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



template <typename T>
string vPrint_imp(const T &t){
    stringstream ss;
    
    ss << t;
    
    return ss.str();
}

template<typename T>
vector<string> vPrint(T t){
    return {};
}

template <typename T, typename... TRest>
vector<string> vPrint(const T &t, const TRest&... tRest){

    vector<string> vStr;
    stringstream ss;
    
    //ss < t;
    
    vStr.push_back(vPrint_imp(t));
 
    const auto vRest = vPrint(tRest...);
    vStr.insert(vStr.end(), vRest.begin(), vRest.end());   
    return vStr;
}    

    
int
main()
{
    const auto vStr = vPrint("Hello", "Matthew", 112, 56.765, true, 1, 0, "Kansas" );
    
    for( const auto &o : vStr ){
        cout << o << " ";
    }
    
    return 0;
}