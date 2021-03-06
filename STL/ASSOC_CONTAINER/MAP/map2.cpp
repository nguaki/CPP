//////////////////////////////////////////////////////////////////////////////////
// Oct 5, 16
// Demonstration of find() method of map data structure.
// Also demonstrates iterator.

//Enter name:matthew                                                                                                       
//found                                                                                                                    
//score: 100                                                                                                               
//average score:82      
//
//Illustrates that map DS keeps in the ascending order of key.
//
//abc   79
//matthew   100
//xyz   80
//yyy   70
//
//Jul 8,18   implemented auto printing.
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>

using namespace std;

int
main()
{
    //Identify key type and value type.
    map<string, int> mpGrades;
    
    //Assign map DS.
    mpGrades["matthew"] = 100;
    mpGrades["xyz"] = 80;
    mpGrades["abc"] = 79;
    mpGrades["yyy"] = 70;
    
    for( auto &it : mpGrades ){
        cout << it.first << "   "  << it.second << endl;  //second refers to value.
     }
    string sName;
    cout << "Enter name:";
    cin >> sName;
    
    //Try to find a key.
    //If it is not found, it returns mpGrades.end().
    if(mpGrades.find(sName) != mpGrades.end())
    {
        cout << "found" << endl;
        cout << "score: " << mpGrades[sName] << endl;
    } 
    else 
    {
        cout << "Not found" << endl;
    }
    
    int iTotalScore = 0, iCount = 0;
    double dAvgScore;
    
    //Use iterator to iterate through the map DS.
    map<string,int>::iterator itGrades = mpGrades.begin();
    
    while( itGrades != mpGrades.end()){
        iTotalScore += itGrades->second;  //second refers to value.
        itGrades++;   //Post increment operator is used to move to the next data. 
        iCount++;
    }
    
    cout << "average score:" << (double)(iTotalScore/iCount) << endl;

    iTotalScore = 0;
    iCount = 0;
    for( auto &it : mpGrades ){
        iTotalScore += it.second;  //second refers to value.
        iCount++;
     }
    
    cout << "average score:" << (double)(iTotalScore/iCount) << endl;
    return 0;
}