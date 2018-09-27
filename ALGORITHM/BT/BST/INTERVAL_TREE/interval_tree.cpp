//Aug 17, 18
//Inverse tree creation and search algorithm.
#include <iostream>

using namespace std;

struct INTERVAL{
    int iLow;
    int iHigh;
};

//Node info now includes high and low.
struct NODE{
    INTERVAL *ptrINT; //I don't like this pointer.
    int      iMax;
    NODE     *ptrLeft;
    NODE     *ptrRight;
};

//Generates a NODE and assign values.
NODE * 
ptrGenerateNode( INTERVAL stIT )
{
    NODE *ptrNode = new NODE;
    
    ptrNode->ptrINT = new INTERVAL;
    
    ptrNode->ptrINT->iLow = stIT.iLow;
    ptrNode->ptrINT->iHigh = stIT.iHigh;
  
    ptrNode->iMax = stIT.iHigh;
    
    ptrNode->ptrLeft  = NULL;
    ptrNode->ptrRight = NULL;
    
    return ptrNode;
}

//Creates a BST.
//Always returns root.
//sort based on low key.
NODE *
ptrCreateTree( NODE *ptrNode, INTERVAL stINT )
{
    int iLow;
    
    if( ptrNode == NULL ) 
        return ptrGenerateNode( stINT );
        
    iLow = ptrNode->ptrINT->iLow;
    
    if(stINT.iLow < iLow)
        ptrNode->ptrLeft = ptrCreateTree(ptrNode->ptrLeft, stINT);
    else
        ptrNode->ptrRight = ptrCreateTree(ptrNode->ptrRight, stINT);

    //keep track of max.
    if( stINT.iHigh > ptrNode->iMax )    
        ptrNode->iMax = stINT.iHigh;
        
    return ptrNode;
}

void
vTravInOrder( NODE *ptrNode )
{
    if( ptrNode == NULL )  return;
   
    vTravInOrder( ptrNode->ptrLeft );
    
    cout << "(" << ptrNode->ptrINT->iLow << "," << ptrNode->ptrINT->iHigh << "," << ptrNode->iMax << ")" << endl; 
    
    vTravInOrder( ptrNode->ptrRight );
}

bool
bCheckOverLap( INTERVAL *stINT1, INTERVAL stINT2 )
{
    return ( stINT1->iLow <= stINT2.iHigh && stINT2.iLow <= stINT1->iHigh ) ? true : false;    
}

INTERVAL *
stSearchForInterval( NODE *ptrNode, INTERVAL stINT1 )
{
    
    if( ptrNode == NULL ) return NULL;
    
    if( bCheckOverLap(ptrNode->ptrINT, stINT1) ) return ptrNode->ptrINT;
    
    if( ptrNode->ptrLeft != NULL && ptrNode->ptrLeft->iMax >= stINT1.iLow) 
        return stSearchForInterval(ptrNode->ptrLeft, stINT1);
    
    return stSearchForInterval(ptrNode->ptrRight, stINT1);
}

int
main(void)
{
    INTERVAL stINT[] = { {15,20}, {10,30}, {17,19}, {5,20}, {12,15}, {30,40} };
    
    NODE *root = NULL;
   
    size_t usLength = sizeof(stINT)/sizeof(stINT[0]);
    for( size_t i=0; i<usLength; i++ ) 
        root =  ptrCreateTree( root, stINT[i] );
    
    vTravInOrder( root );
    
    INTERVAL *stResult, stTest = {6,7};
    stResult = stSearchForInterval( root, stTest);
    if( stResult != NULL )
        cout << stResult->iLow << "'" << stResult->iHigh << endl;
    return 0;
}