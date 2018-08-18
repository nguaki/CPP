//Aug 17, 2018
//Customize sort order for prioritized_queue
//Populate struct data onto prioritized_queue.
#include <iostream>
#include <queue>

using namespace std;

struct RESULT{
    int id;
    int result;
};

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
    
    stRes[0] = { 1, 70 };
    stRes[1] = { 1, 80 };
    stRes[2] = { 1, 90 };
    stRes[3] = { 1, 100 };
    stRes[4] = { 1, 110 };
    stRes[5] = { 2, 70 };
    stRes[6] = { 2, 80 };
    stRes[7] = { 2, 90 };
    stRes[8] = { 2, 100 };
    stRes[9] = { 2, 110 };
    stRes[10] = { 2, 40 };
    stRes[11] = { 2, 50 };
 
    for( i=0; i<12; i++ ) pq.push(stRes[i]);
   
    for( i=0; i<12; i++ ){
        RESULT temp;
        temp = pq.top();
        cout << temp.id << ","  << temp.result << endl;   
        pq.pop();
    } 
    //Caused error. 
    //for(auto &pqItem: pq ) cout << pqItem << endl;
    //for( priority_queue<int>::iterator pqIt = pq.begin(); pq != pq.end(); pq++ )
    //    cout << *pqIt << endl;
    
   
    
    return 0;
}