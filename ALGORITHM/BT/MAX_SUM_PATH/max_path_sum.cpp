#include <iostream>
#include <climits>

using namespace std;


struct NODE{
    int iData;
    NODE *ptrLeft;
    NODE *ptrRight;
};

NODE *
ptrGenerateNode(int iData)
{
    NODE *ptrNode = new NODE;
   
    ptrNode->iData    = iData;
    ptrNode->ptrLeft  = NULL;
    ptrNode->ptrRight = NULL;

    return ptrNode;
}

void
vTraverseInOrder(NODE* Node)
{
   if( Node == NULL ) return;
   
   vTraverseInOrder(Node->ptrLeft);
    
   cout << Node->iData << endl;
   
   vTraverseInOrder(Node->ptrRight);
    
}

int
iFindPathSum(NODE* Node, int& iMaxPath )
{
   int iLeftPathSum;
   int iRightPathSum;
   int iMaxAtThisNode; 
   int iMaxFromBothSides;
   
   if (Node ==NULL)  return 0;
   
   iLeftPathSum = iFindPathSum(Node->ptrLeft, iMaxPath);
   iRightPathSum =  iFindPathSum(Node->ptrRight, iMaxPath);
   
   //Find out if the sum from each path is greater than the node itself.
   //Lets say left path yields 10 and right path yields 5. The node itself is 20.
   //The max path in this case 10+20=30.
   iMaxAtThisNode = max( max(iLeftPathSum, iRightPathSum) + Node->iData, Node->iData );
   
   //Following line considers total path as the left and right and the node itself.
   //iMaxAtThisNode only considers the max from one path only.
   //Need more illustration.
   //This description contradicts the above statment:
   //Clearly iMaxAtThisNode gets the max from both sides.
   iMaxFromBothSides = max(iMaxAtThisNode, iLeftPathSum+iRightPathSum+Node->iData);
   
   iMaxPath = max(iMaxFromBothSides, iMaxPath);
   
   return iMaxAtThisNode; 
}

int
iFindPathSumUtility(NODE* Node)
{
    int iMaxPath = INT_MIN;
    
    iFindPathSum(Node, iMaxPath );
    
    return iMaxPath; 
}

int
main(void)
{
    NODE *root = ptrGenerateNode(10);
    
    root->ptrLeft = ptrGenerateNode(2);
    root->ptrRight = ptrGenerateNode(10);
    
    root->ptrLeft->ptrLeft = ptrGenerateNode(20);
    root->ptrLeft->ptrRight = ptrGenerateNode(1);
    
    root->ptrRight->ptrRight = ptrGenerateNode(-25);
    
    root->ptrRight->ptrRight->ptrLeft = ptrGenerateNode(3);
    root->ptrRight->ptrRight->ptrRight = ptrGenerateNode(4);
    
    vTraverseInOrder(root);
    cout << "Total Max Path:";
    cout << iFindPathSumUtility(root) << endl;
    
    return 0;
}