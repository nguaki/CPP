////////////////////////////////////////////////////////////
// Date: Sep 28, 16
//
// Description:
//   This application reads a text file that has people names and phone numbers.
//   These data are assigned to C++ map DS for a quick retrieval.
//
//Demonstration of  C++ data structure - map.
//  map is strict associative array - requires type definition for key and value.
//
//  It seems like search and insertion time is O(1).
//
//Enter name:che
//11112
//Enter menu choice :
//1. Retrieve phone info 
//2. Exit
//1
//Enter name:choi
//4567
//Enter menu choice :
//1. Retrieve phone info 
//2. Exit
//1
//Enter name:park
//1111
//Enter menu choice :
//1. Retrieve phone info 
//2. Exit

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

/////////////////////////////////////////
//Gets just the name portion of the line.
//
//sLine looks like   james, 7777
string sGetName( const string &sLine ){
    int iPos = sLine.find(',');  //Finds the position of a comma
    
    return( sLine.substr(0,iPos)); //Returns a substr which is up to where 
                                   //comma is.
}

/////////////////////////////////////////
//Gets the phone number portion
//
string sGetPhone( const string &sLine ){
    int iPos = sLine.find(',');
    
    return( sLine.substr(iPos+1) );
}

/////////////////////////////////////////////////////
//Given a name, returns the phone number instantly
//Search is O(1).
void
vGetPhoneInfo( map<string,string> &mpPhoneInfo){
    
    string sName;
    
    cout << "Enter name:";
    cin >> sName;
    
    cout << mpPhoneInfo[sName] << endl;
}

void vShowMenu()
{
    cout << "Enter menu choice :" << endl;
    cout << "1. Retrieve phone info " << endl;
    cout << "2. Exit" << endl;
}

int
main()
{
    map<string, string> mpPhoneInfo;  //Defines a map(Associative array)
    fstream fsPhoneInfo("phonelist"); //Opens a file stream.
    string sLine, sName, sPhoneNumber;
    int iMenuChoice;
    
    
    while(!fsPhoneInfo.eof()){
        
        getline(fsPhoneInfo, sLine);  //Reads a line.  A sample data looks like
                                      //4534, James
        
        sName = sGetName(sLine);
        sPhoneNumber = sGetPhone(sLine);
        
        mpPhoneInfo[sName] = sPhoneNumber;
        
    }

    do{
        vShowMenu();
        cin >> iMenuChoice;
        if( iMenuChoice == 1){
            vGetPhoneInfo(mpPhoneInfo);
        }
        
    }while(iMenuChoice != 2); 
    
    return 0;
    
}