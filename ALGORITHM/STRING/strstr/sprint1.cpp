#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool
bIsSubstr( string pattern, string source )
{
    if(source.find(pattern) != string::npos)
      return true; 
    else
      return false; 
     
    
} 
int
main(void)
{
    assert(bIsSubstr( "int", "sprint" )==true);
    assert(bIsSubstr( "nti", "sprint" )==false);
    assert(bIsSubstr( "xxx", "sprint" )==false);
    
    return 0;
}