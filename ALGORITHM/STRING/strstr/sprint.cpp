#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool bIsSubstr( string sPattern, string sSource )
{
	unordered_map<char, int> um;

	for(int i; i <sSource.length(); i++ )
		um[sSource[i]]++;


    for(int i; i<sPattern.length(); i++)
		if(um[sPattern[i]] == 0 )
			return false;	
		else
			um[sPattern[i]]--;

         return true;
}
         
int
main(void)
{
	bIsSubstr("int", "sprint")	?  cout << "Yes" : cout << "Nope";
	bIsSubstr("aab", "abba")	?  cout << "Yes" : cout << "Nope";
	bIsSubstr("int", "sprnit")	?  cout << "Yes" : cout << "Nope";
}