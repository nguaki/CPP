//Aug 17, 18
//Returns map DS.
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct RESULT{
    int id;
    int scores;
};

map<int,int>
mapGetTotal( vector<RESULT>&vRes)  
{
    map<int,int>  mapTotal;
    
    for(auto &it: vRes) mapTotal[it.id] += it.scores;
    
    return mapTotal;
}

int
main(void)
{
    vector<RESULT> vRes;
    RESULT stRes[12];
    map<int,int>  mapTotal;
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
    
    for( i=0; i<12; i++ )  vRes.push_back(stRes[i]);
    
    mapTotal = mapGetTotal(vRes);  
   
    cout << mapTotal[1] << endl;
    cout << mapTotal[2] << endl;
    
    return 0;
}