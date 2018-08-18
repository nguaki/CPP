//Aug 17, 18
//Get top 5 scores from prioritized_queue.
//
//Iterator on PQ doesn't work.  Have to use top() and pop().
//Caused error. 
//for(auto &pqItem: pq ) cout << pqItem << endl;
//for( priority_queue<int>::iterator pqIt = pq.begin(); pq != pq.end(); pq++ )
//    cout << *pqIt << endl;
//
#include <iostream>
#include <queue>

using namespace std;

float
fGetAvgTop5( priority_queue<int> &pq )
{
    int iLen = pq.size();
    int iTop5[5];
    int i;
    float fAvgTop5;
    int iTotal = 0;
    
    cout << "Top 5 scores are" << endl;
    
    for( i=0; i<5; i++ ){
        int iTop = pq.top();
        if(i<5) iTop5[i] = iTop;
        cout << iTop << endl;
        iTotal += iTop;
        pq.pop();
    }
    
    fAvgTop5 = iTotal/5.0;
    
    for( i=0; i<5; i++)  pq.push(iTop5[i]);
    
    cout << "Average of top 5 scores" << endl;
    return fAvgTop5;
}

int
main(void)
{
    priority_queue<int>  pq;
    
    pq.push(50);
    pq.push(40);
    pq.push(30);
    pq.push(20);
    pq.push(10);
    pq.push(100);
    pq.push(90);
    pq.push(80);
    pq.push(70);
    pq.push(60);
   
    cout << fGetAvgTop5( pq ) << endl;
    
    int iNewScore;
    
    cout << "Enter a number:";
    cin >> iNewScore;
    pq.push(iNewScore); 
    
    cout << fGetAvgTop5( pq ) << endl;
    
    return 0;
}