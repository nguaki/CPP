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
vPostOrder(NODE* root)
{
    if (root==NULL) return;
    
    vPostOrder(root->ptrLeft);
    vPostOrder(root->ptrRight);
    cout << root->iData << endl;
    
}

void
vPostOrder_iteration(NODE* root)
{
    stack<NODE*> Sptr1;
    stack<NODE*> Sptr2;
    NODE* ptrTemp;
    
    if (root==NULL) return;
    
    ptrTemp = root; 
    Sptr1.push(ptrTemp);
    
    while( !Sptr1.empty() )
    {
        ptrTemp = Sptr1.top();
        Sptr1.pop();
        
        Sptr2.push(ptrTemp);
        
        if( ptrTemp->ptrLeft != NULL )
            Sptr1.push(ptrTemp->ptrLeft);
            
        if( ptrTemp->ptrRight != NULL )
            Sptr1.push(ptrTemp->ptrRight);
    } 
    
    while( !Sptr2.empty() )
    {
        ptrTemp = Sptr2.top();
        cout << ptrTemp->iData << endl;
        Sptr2.pop();
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
    
    vPostOrder(root);
    cout << "============================" << endl;
    vPostOrder_iteration(root);
    return 0;
}