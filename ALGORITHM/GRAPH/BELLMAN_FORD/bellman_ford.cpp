//Aug 22, 2018
//Shortest route algo.
//Detects negative cycle.
#include <iostream>
#include <climits>

using namespace std;

struct EDGE{
    int iSrc;
    int iDest;
    int iWeight;
};

struct GRAPH{
    int iV;
    int iE;
    
    EDGE *ptrEdges;
};

GRAPH *
ptrGenerateGraph(int iNumVertices, int iNumEdges)
{
    GRAPH*  ptrGraph = new GRAPH;
    
    ptrGraph->iV = iNumVertices;
    ptrGraph->iE = iNumEdges;
    
    ptrGraph->ptrEdges = new EDGE[iNumEdges];
    
    return ptrGraph;
}

void
vBellmanFord(GRAPH* ptrGraph, int iSrc, int* iShortDist, int* iParent)
{
    int iNumVertices = ptrGraph->iV;
    int iNumEdges = ptrGraph->iE;
    int i, j;
    
    for( i=0; i< iNumVertices; i++)
        iShortDist[i] = INT_MAX;
        
    iShortDist[iSrc] = 0;
    iParent[iSrc] = 0;
    
    //Goes thru N-1 times.
    //Each time, hoping to improve on route.
    for( i = 1; i <= iNumVertices - 1; ++i ) 
        for( j = 0; j < iNumEdges; ++j )
        {
            int u;
            int v;
            int w;
            u = ptrGraph->ptrEdges[j].iSrc;
            v = ptrGraph->ptrEdges[j].iDest;
            w = ptrGraph->ptrEdges[j].iWeight;
            
            if( iShortDist[u] != INT_MAX && iShortDist[u]+w < iShortDist[v] ){
                iShortDist[v] = iShortDist[u] + w;
                iParent[v] = u;
            }
        }
    //If there is further improvement, there is a negative cycle detected.
    for( j = 0; j < iNumEdges; ++j )
    {
        int u;
        int v;
        int w;
        u = ptrGraph->ptrEdges[j].iSrc;
        v = ptrGraph->ptrEdges[j].iDest;
        w = ptrGraph->ptrEdges[j].iWeight;
            
       if( iShortDist[u] != INT_MAX && iShortDist[u]+w < iShortDist[v] ){
           cout << "Negative cycle detected" << endl;
        }
    }
}

void
vDisplayResults( int* iShortDist, int* iParent, int iNumOfVertices )
{
   for( int i=0; i<iNumOfVertices; i++ )
       cout << i << "  " << iShortDist[i] << "  parent is " << iParent[i] << endl;
}

int
main(void)
{
    int iV = 5;
    int iE = 8;
    
    GRAPH*  graph = ptrGenerateGraph(iV, iE);
    int  iShortDist[iE];
    int  iParent[iE];
    
    // add edge 0-1 (or A-B in above figure)
    graph->ptrEdges[0].iSrc = 0;
    graph->ptrEdges[0].iDest = 1;
    graph->ptrEdges[0].iWeight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->ptrEdges[1].iSrc = 0;
    graph->ptrEdges[1].iDest = 2;
    graph->ptrEdges[1].iWeight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->ptrEdges[2].iSrc = 1;
    graph->ptrEdges[2].iDest = 2;
    graph->ptrEdges[2].iWeight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->ptrEdges[3].iSrc = 1;
    graph->ptrEdges[3].iDest = 3;
    graph->ptrEdges[3].iWeight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->ptrEdges[4].iSrc = 1;
    graph->ptrEdges[4].iDest = 4;
    graph->ptrEdges[4].iWeight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->ptrEdges[5].iSrc = 3;
    graph->ptrEdges[5].iDest = 2;
    graph->ptrEdges[5].iWeight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->ptrEdges[6].iSrc = 3;
    graph->ptrEdges[6].iDest = 1;
    graph->ptrEdges[6].iWeight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->ptrEdges[7].iSrc = 4;
    graph->ptrEdges[7].iDest = 3;
    graph->ptrEdges[7].iWeight = -3;
 
    vBellmanFord(graph, 0, iShortDist, iParent);
    
    vDisplayResults( iShortDist, iParent, iV  );
    
    iV = 4;
    iE = 4;
    
    GRAPH*  graph1 = ptrGenerateGraph(iV, iE);
    
    // add edge 0-1 (or A-B in above figure)
    graph1->ptrEdges[0].iSrc = 0;
    graph1->ptrEdges[0].iDest = 1;
    graph1->ptrEdges[0].iWeight = 1;
 
    // add edge 0-2 (or A-C in above figure)
    graph1->ptrEdges[1].iSrc = 1;
    graph1->ptrEdges[1].iDest = 2;
    graph1->ptrEdges[1].iWeight = 3;
 
    // add edge 1-2 (or B-C in above figure)
    graph1->ptrEdges[2].iSrc = 2;
    graph1->ptrEdges[2].iDest = 3;
    graph1->ptrEdges[2].iWeight = 2;
    
    graph1->ptrEdges[3].iSrc = 3;
    graph1->ptrEdges[3].iDest = 1;
    graph1->ptrEdges[3].iWeight = -6;
    
    vBellmanFord(graph1, 0, iShortDist, iParent);
    
    vDisplayResults( iShortDist, iParent, iV  );
    return 0;
}