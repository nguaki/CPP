//Aug 22, 2018
//In order to understand subsets, please refer to note.
//e.g.  {2,{1,3}}  means the distance it takes to vertex #2 by going through vertex
//#1 and #3.
//{1,3} can be expanded to {3,{1,{}} or {1, {3,{}}}.
//What this means is that vertex 3 is reached thru vertex 1 which comes from the original source.
//What this means is that vertex 1 is reached thru vertex 3 which comes from the original source.
//
//Time complexity is 2^^n+ n^^2
//Spatial complexity is also 2^^n+ n^^2

#include <bits/stdc++.h>
using namespace std;

struct Index{
    int currVertex;
    set<int> vertexSet;
};

//Returns data looks like { {}, {1}, {2}, {3], {1,2}, {1,3}, {2,3}, {1,2,3}.
//Its like an array of something where something is unfixed size of sorted numbers.
vector<set<int> > generateSubsets(vector<int> vec)
{
    int n=vec.size();
    int pow_set_size=pow(2,n);
    vector<set<int> > v;
    for(int counter = 0; counter < pow_set_size; counter++)
    {
        set<int> s;
        for(int j = 0; j < n; j++)
        {
            //This is the heart of this code.
            //counter goes 0 to 2^^n where n is number of vertices - 1.
            //It does & bit operation.
            //It also does bit left shift.
            //If it is non-zero, the vertex ID will be inserted.
            if(counter & (1<<j))  s.insert(vec[j]);
        }
        v.push_back(s);
    }
    return v;
}
//Customized sort order.
struct compare{
    bool operator()(Index a,Index b){
        return a.currVertex<b.currVertex;
    }
};

//Traveling salesman algorithm
int tsp(int dist[4][4])
{
    //weird map DS.
    //key value is a struct.
    //It looks something like   map[{2,{1,3}] = 4;
    //The value is the distance.
    map<Index,int,compare> m;
    
    vector<set<int> > allSets=generateSubsets(vector<int>{1,2,3});
   
    //allSets data looks like { {}, {1}, {2}, {3], {1,2}, {1,3}, {2,3}, {1,2,3}.
    //s can be any of the members.
    for(auto s:allSets){
        for(int currVertex=1;currVertex<4;currVertex++){
            //If vertex ID is in the member, go to next one.
            if(s.find(currVertex)!=s.end())  continue;
            
            //Intersting way to assign data.
            Index index={currVertex,s};
            
            int minCost=INT_MAX;
            int minPrevVertex=0;

            //Copies the set.
            set<int> copySet=s;
            for(auto prevVertex:s){
                
                //Lets say copySet was {1}. By delete 1 from it will have an empty set. {}
                copySet.erase(prevVertex);
                int cost=dist[prevVertex][currVertex]+m[{prevVertex,copySet}];
                copySet.insert(prevVertex);
                
                if(cost<minCost){
                    minCost=cost;
                    minPrevVertex=prevVertex;
                }
            }
            if(s.size()==0){
                minCost=dist[0][currVertex];
            }
            m[index]=minCost;
            cout << minPrevVertex << endl;
        }
    }
    vector<int> v{1,2,3};
    set<int> s(v.begin(),v.end());
    set<int> copySet=s;
    int minCost=INT_MAX;
    int minPrevVertex=0;
    for(auto prevVertex:s){
        copySet.erase(prevVertex);
        int cost=dist[prevVertex][0]+m[{prevVertex,copySet}];
        copySet.insert(prevVertex);
        if(cost<minCost){
            minCost=cost;
            minPrevVertex=prevVertex;
        }
    }
    cout << minPrevVertex << endl;
    
    return minCost;
}

int main()
{
    int dist[4][4]={{0,1,15,6},
                    {2,0,7,3},
                    {9,6,0,12},
                    {10,4,8,0}};
    cout<<tsp(dist);
}