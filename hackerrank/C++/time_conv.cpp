//Hackerrank.com
// Title: Time Conversion
//
// Date: Oct 5, 2016
//
//Given a time in -hour AM/PM format, convert it to military (-hour) time.

//Note: Midnight is  on a -hour clock, and  on a -hour clock. Noon is  on a -hour clock, and  on a -hour clock.

//Input Format

//A single string containing a time in -hour clock format (i.e.:  or ), where  and .


#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    
    string time;
    cin >> time;
    
    string sHour = time.substr(0,2);
    string sMin  = time.substr(3,2);
    string sSec  = time.substr(6,2);
    string sME   = time.substr(8);

    //if( sME.compare("PM") == 0  && atoi(sHour.data()) < 12){
    if( sME.compare("PM") == 0  && stoi(sHour) < 12){
        //int iMHour = atoi(sHour.data()) + 12;
        int iMHour = stoi(sHour) + 12;
        stringstream ss;
        ss << iMHour;
        
        //sHour[0] = ss.str()[0];
        //sHour[1] = ss.str()[1];
        sHour = ss.str();
    }
    //if( sME.compare("AM") == 0 && atoi(sHour.data()) == 12 ){
    if( sME.compare("AM") == 0 && stoi(sHour) == 12 ){
        sHour = "00";
    }
    
    cout << sHour << ":"  << sMin << ":" << sSec <<  endl;
    return 0;
}