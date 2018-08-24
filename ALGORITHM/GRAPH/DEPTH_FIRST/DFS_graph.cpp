//Graph Depth first search 
#include <iostream>
#include <list>

using namespace std;

struct GRAPH{
    int iVertices;
   
    list<int> *ptrAdj;  //Has structure like ptrAdj[i]={j,k,l}.  This means that
                        //i is from-vertex and j,k,l are to-vertices.
}; 

//
//Recursive function.
//Key is iterating  list<>*ptrAdj.
//
void
vGraph_DFSearch( GRAPH *pG, bool *bVisited, int iVertexID )
{
   cout << iVertexID << endl;
   bVisited[iVertexID] = true;
   
   for( auto it : pG->ptrAdj[iVertexID]){
       if(bVisited[it] == false) 
            vGraph_DFSearch( pG, bVisited, it );
   }
}

void
vResetVisited(bool* bVisted)
{
   for(int i=0; i<5; i++)  bVisted[i] = false;
}

int
main(void)
{
    GRAPH *ptrGraph = new GRAPH;
    ptrGraph->iVertices = 5;
    bool bVisted[5] = {false, false, false, false, false};
    
    ptrGraph->ptrAdj = new list<int>[5];
    ptrGraph->ptrAdj[0].push_back(1); 
    ptrGraph->ptrAdj[0].push_back(2); 
    ptrGraph->ptrAdj[1].push_back(2); 
    ptrGraph->ptrAdj[2].push_back(0); 
    ptrGraph->ptrAdj[2].push_back(3); 
    ptrGraph->ptrAdj[3].push_back(3); 
    ptrGraph->ptrAdj[4].push_back(1); 
    
    for(int i=0; i<5;i++){
        cout << "Depth First Search from vertex " << i << endl;
        vGraph_DFSearch( ptrGraph, bVisted, i );
        cout << "===============================" << endl;
        vResetVisited(bVisted);
    } 
    
    return 0;
}