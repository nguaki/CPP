//Aug 26, 18
//Iteration for pre order
//The logic is very different from recursion.
//Here we are dealing with stack.
//The difference here is that right child gets push on the
//stack first and then the left child.
#include <iostream>
#include <stack>

using namespace std;

struct NODE
{
    int iData;
    NODE* ptrLeft;
    NODE* ptrRight;
};

NODE*
ptrGenerateNode(int iD)
{
    NODE* ptrTemp;
    
    ptrTemp = new NODE;
    ptrTemp->iData = iD;
    ptrTemp->ptrLeft = ptrTemp->ptrRight = NULL;
    
    return ptrTemp;
}

void
vPreOrder(NODE* root)
{
    if (root==NULL) return;
    
    cout << root->iData << endl;
    vPreOrder(root->ptrLeft);
    vPreOrder(root->ptrRight);
    
}

void
vPreOrder_iteration(NODE* root)
{
    stack<NODE*> Sptr;
    NODE* ptrTemp;
    
    if (root==NULL) return;
    
    ptrTemp = root; 
    Sptr.push(ptrTemp);
    
    while( !Sptr.empty() )
    {
        ptrTemp = Sptr.top();
        cout << ptrTemp->iData << endl;
        Sptr.pop();
        
        if( ptrTemp->ptrRight != NULL )
            Sptr.push(ptrTemp->ptrRight);
            
        if( ptrTemp->ptrLeft != NULL )
            Sptr.push(ptrTemp->ptrLeft);
    }
}

int
main(void)
{

    NODE* root = ptrGenerateNode(10);
    root->ptrLeft = ptrGenerateNode(5);
    root->ptrRight = ptrGenerateNode(12);
    root->ptrLeft->ptrLeft = ptrGenerateNode(14);
    root->ptrRight->ptrLeft = ptrGenerateNode(21);
    root->ptrRight->ptrRight = ptrGenerateNode(3);
    
    vPreOrder(root);
    cout << "============================" << endl;
    vPreOrder_iteration(root);
    return 0;
}