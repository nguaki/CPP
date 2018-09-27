//
//Graph Top search 
//Around line 35 is the core of this logic.
//It pushes the vertex ID on a stack.
#include <iostream>
#include <list>
#include <stack>
#include <map>

using namespace std;

struct GRAPH{
    int iVertices;
   
    list<int> *ptrAdj;  //Has structure like ptrAdj[i]={j,k,l}.  This means that
                        //i is from-vertex and j,k,l are to-vertices.
}; 

int iTopSortOrder[10];
map<int, int> mapTopSort;

//
//Recursive function.
//Key is iterating  list<>*ptrAdj.
//
void
vTopSortRecursive( GRAPH* pG, int iVertexID, bool *bVisited, stack<int>& stResult )
{
   bVisited[iVertexID] = true;
  
   //Goes thru all adjacent vertices. 
   for( auto it : pG->ptrAdj[iVertexID]){
       if(bVisited[it] == false) 
            vTopSortRecursive( pG, it, bVisited, stResult );
   }

    //Pushes the vertex ID after all its children adjacent vertices are visited.
    stResult.push(iVertexID);
}

void
vTopSort( GRAPH* ptrGraph )
{
    stack<int> stResult;
    bool bVisited[ptrGraph->iVertices];
    int iTopSortIndex = 0;
    
    for(int i=0; i < ptrGraph->iVertices; ++i )
        bVisited[i] = false;
        
     
    for(int i=0; i < ptrGraph->iVertices; ++i )
        if(bVisited[i] == false )
            vTopSortRecursive( ptrGraph, i, bVisited, stResult );
    
    cout << "Top sort result" << endl;
    while( !stResult.empty() ){
        int iTop = stResult.top();
        cout << iTop << endl;
        //Keeps track of the order of the vertex top sort.
        //mapTopSort[i] = j means ith vertex is in jth order in array.
        mapTopSort[iTop] = iTopSortIndex;
        //Keeps the top sort order in an array.
        iTopSortOrder[iTopSortIndex] = stResult.top();;
        stResult.pop();
        iTopSortIndex++;
    }
}
//All parent ID must come befoe children ID in top sort.
//mapTopSort[i] = j;  means that vertex ID 'i' is in jth place in the order.
bool
bValidateTopSortResult( GRAPH* ptrGraph )
{
    bool bValid=true;
    
    for(int iVertexID=0; iVertexID<ptrGraph->iVertices;iVertexID++)
    {
        for(auto it: ptrGraph->ptrAdj[iVertexID] ){
            if( mapTopSort[iVertexID] > mapTopSort[it] ){
                
                bValid = false;
                cout << "Invalid sort" << endl;
                cout << iVertexID << " must come before " << mapTopSort[it] << endl;
            }
        }
    }
    return bValid;
}

int
main(void)
{
    GRAPH *ptrGraph = new GRAPH;
    ptrGraph->iVertices = 6;
    
    ptrGraph->ptrAdj = new list<int>[6];
    ptrGraph->ptrAdj[5].push_back(2); 
    ptrGraph->ptrAdj[5].push_back(0); 
    ptrGraph->ptrAdj[4].push_back(0); 
    ptrGraph->ptrAdj[4].push_back(1); 
    ptrGraph->ptrAdj[2].push_back(3); 
    ptrGraph->ptrAdj[3].push_back(1); 
    
    vTopSort( ptrGraph );
   
    if (bValidateTopSortResult( ptrGraph ))
        cout << "Sort is valid";
    else
        cout <<"Sort is INVALID";
    
    return 0;
}