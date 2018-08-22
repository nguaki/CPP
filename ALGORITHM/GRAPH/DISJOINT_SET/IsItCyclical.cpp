//Aug 19, 2018
//Checking if a non-directional graph is cyclical or not.
//Utilizes disjoint algorithm.
//
//Strategy is as follows:
//Go around each edge's vertices.
//Check if each vertices end points have same subset.  If it is, there is a circuit.
//If it is not, put both edges into one subset which point same parent.
//
//After setting ptrIParents as "int & ptrIParents" from "int * ptrIParents", getting this error message:
//IsItCyclical.cpp:53:58: error: invalid types ‘int[int]’ for array subscript
//     return iGetParent( ptrIParents, ptrIParents[iVertexID]);
//
//NEED to revisit and understand more clearly in order to write right comments.
//I got the idea, but this idea seems very illogical to me.  But it works!!!
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct EDGE{
    int iSrc;
    int iDest;
};

struct GRAPH{
    int iNumVertices;
    int iNumEdges;
    EDGE* ptrEdges;
};

GRAPH* 
ptrCreateGraph( int iVertices, int iEdges )
{
    GRAPH* ptrGraph = new GRAPH;
    
    //ptrGraph = (GRAPH *)malloc(sizeof(GRAPH));
    
    ptrGraph->iNumEdges = iEdges;
    ptrGraph->iNumVertices = iVertices;
   
    //ptrGraph->ptrEdges = (EDGE *)malloc(iEdges*sizeof(EDGE));
    ptrGraph->ptrEdges = new EDGE[iEdges];
    
    return ptrGraph;
}


//Recursively get the parent ID.
//Keeps going back until it hits -1.
int 
iGetParent( int * ptrIParents, int iVertexID )
{
    //If parent is -1, the parent ID is the vertexID. 
    if(ptrIParents[iVertexID] == -1 ) return iVertexID;
   
    return iGetParent( ptrIParents, ptrIParents[iVertexID]);
}

//Puts disjointed subsets into one set and declare one parent.
void
vUnionize( int * ptrIParents, int iSrc, int iDest)
{
    int x, y;
    
    x = iGetParent(ptrIParents, iSrc);
    y = iGetParent(ptrIParents, iDest);
    
    ptrIParents[x]  = y;
}
int
iCheckCyclical( GRAPH* ptrGraph) 
{
    int  ptrIParents[ptrGraph->iNumVertices]; 
   
    //ptrIParents = (int *)malloc(sizeof(int)*ptrGraph->iNumVertices);
  
    //memset(ptrIParents, -1, sizeof(int)*ptrGraph->iNumVertices);
    //All parents ID is set to -1.
    memset(ptrIParents, -1, sizeof(ptrIParents));
    
    for(int iEdge=0; iEdge < ptrGraph->iNumEdges; iEdge++)
    {
        int iParentOfSrc = iGetParent( ptrIParents, ptrGraph->ptrEdges[iEdge].iSrc);
        int iParentOfDest = iGetParent( ptrIParents, ptrGraph->ptrEdges[iEdge].iDest);
        
        //If both end points have same parent, that means there is a cicuit.
        if (iParentOfSrc == iParentOfDest) return 1;
        
        vUnionize(ptrIParents, iParentOfSrc, iParentOfDest);
    }
    return 0;
}

int 
main(void)
{
    GRAPH * ptrGraph;
    
    ptrGraph = ptrCreateGraph(4,3);
   
    ptrGraph->ptrEdges[0].iSrc = 0;
    ptrGraph->ptrEdges[0].iDest = 1;
    
    ptrGraph->ptrEdges[1].iSrc = 1;
    ptrGraph->ptrEdges[1].iDest = 2;
    
    ptrGraph->ptrEdges[2].iSrc = 3;
    ptrGraph->ptrEdges[2].iDest = 1;
    
    if( iCheckCyclical(ptrGraph) )
        cout << "It is cyclical" << endl;
    else
        cout << "It is not cyclical" << endl;
    
    GRAPH * ptrGraph1;
    
    ptrGraph1 = ptrCreateGraph(3,3);
   
    ptrGraph1->ptrEdges[0].iSrc = 0;
    ptrGraph1->ptrEdges[0].iDest = 1;
    
    ptrGraph1->ptrEdges[1].iSrc = 1;
    ptrGraph1->ptrEdges[1].iDest = 2;
    
    ptrGraph1->ptrEdges[2].iSrc = 0;
    ptrGraph1->ptrEdges[2].iDest = 2;
    
    if( iCheckCyclical(ptrGraph1) )
        cout << "It is cyclical" << endl;
    else
        cout << "It is not cyclical" << endl;
        
    GRAPH * ptrGraph2;
    
    ptrGraph2 = ptrCreateGraph(4,4);
   
    ptrGraph2->ptrEdges[0].iSrc = 0;
    ptrGraph2->ptrEdges[0].iDest = 1;
    
    ptrGraph2->ptrEdges[1].iSrc = 1;
    ptrGraph2->ptrEdges[1].iDest = 2;
    
    ptrGraph2->ptrEdges[2].iSrc = 2;
    ptrGraph2->ptrEdges[2].iDest = 3;
    
    ptrGraph2->ptrEdges[3].iSrc = 0;
    ptrGraph2->ptrEdges[3].iDest = 3;
    
    if( iCheckCyclical(ptrGraph2) )
        cout << "It is cyclical" << endl;
    else
        cout << "It is not cyclical" << endl;
        
    GRAPH * ptrGraph3;
    
    ptrGraph3 = ptrCreateGraph(5,5);
   
    ptrGraph3->ptrEdges[0].iSrc = 0;
    ptrGraph3->ptrEdges[0].iDest = 2;
    
    ptrGraph3->ptrEdges[1].iSrc = 0;
    ptrGraph3->ptrEdges[1].iDest = 1;
    
    ptrGraph3->ptrEdges[2].iSrc = 1;
    ptrGraph3->ptrEdges[2].iDest = 3;
    
    ptrGraph3->ptrEdges[3].iSrc = 3;
    ptrGraph3->ptrEdges[3].iDest = 4;
    
    ptrGraph3->ptrEdges[4].iSrc = 4;
    ptrGraph3->ptrEdges[4].iDest = 1;
    if( iCheckCyclical(ptrGraph3) )
        cout << "It is cyclical" << endl;
    else
        cout << "It is not cyclical" << endl;
    return 0; 
    return 0; 
}