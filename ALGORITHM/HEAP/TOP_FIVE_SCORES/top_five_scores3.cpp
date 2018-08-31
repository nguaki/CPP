//Aug 17, 2018
//Calculate the average score of top 5 test scores of students.
//Uses priority_queue and customized sort.
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct RESULT{
    int id;
    int result;
};

map<int,float>
mapGetTotal_Top5( priority_queue<RESULT>& vRes, map<int,int>&mapCount)  
{
    size_t usSize;
    usSize = vRes.size();
    map<int,float>  mapTotal;
    size_t i;
   
    //for( i=0; i<usSize; i++ )  iCnt[i] = 0;
    
    for( i=0; i<usSize; i++ ){
        RESULT temp;
        temp = vRes.top();
        cout << temp.id << ","  << temp.result << endl;   
        vRes.pop();
        
        if( mapCount[temp.id] < 5 ){
            mapTotal[temp.id] += temp.result;
            mapCount[temp.id]++;
        } 
    } 
    
    for( auto &it : mapTotal )
        mapTotal[it.first] = mapTotal[it.first] / mapCount[it.first];
        
    return mapTotal;
}

//Ability customize the sorting for prioritized_queue.
//ID is in ascending order.
//result is in descending order.
//result being descending order is important since only top 5 will be considered.
bool operator < ( const RESULT& a, const RESULT& b )
{
    if( a.id != b.id ) 
        return a.id > b.id;
    else
        return a.result < b.result;
}

int
main(void)
{
    priority_queue<RESULT>  pq;
    RESULT stRes[12];
    int i;
    map<int,float> mapTotal;
    map<int,int> mapCount;     //Keeps track of the number tests per student ID.
    
    //For student 1, only top 5 should count and the average should be 90. 
    stRes[0] = { 1, 70 };
    stRes[1] = { 1, 80 };
    stRes[2] = { 1, 90 };
    stRes[3] = { 1, 100 };
    stRes[4] = { 1, 110 };
    stRes[5] = { 1, 60 };
    //For student 2, only top 5 should count and the average should be 1.8. 
    stRes[6] = { 2, 2 };
    stRes[7] = { 2, 2 };
    stRes[8] = { 2, 2 };
    stRes[9] = { 2, 2 };
    stRes[10] = { 2, 1 };
    stRes[11] = { 2, 1 };
  
    //Initialization.  Remember there is customized sort.
    //Please see the overload < operator function.
    for( i=0; i<12; i++ ){
        mapCount[stRes[i].id] = 0;
        pq.push(stRes[i]);
    } 
    //Caused error. 
    //for(auto &pqItem: pq ) cout << pqItem << endl;
    //for( priority_queue<int>::iterator pqIt = pq.begin(); pq != pq.end(); pq++ )
    //    cout << *pqIt << endl;
    
   
    mapTotal = mapGetTotal_Top5(pq, mapCount);  
 
    cout << "Average score of top 5 scores:" << endl;
    for( auto &it : mapTotal )
        cout << it.second << endl;
        
    return 0;
}