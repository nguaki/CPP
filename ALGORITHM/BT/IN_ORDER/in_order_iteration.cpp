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
inOrder(NODE* root)
{
    if (root==NULL) return;
    
    inOrder(root->ptrLeft);
    cout << root->iData << endl;
    inOrder(root->ptrRight);
    
}

void
inOrder_iteration(NODE* root)
{
    stack<NODE*> Sptr;
    NODE* ptrTemp;
    
    if (root==NULL) return;
    
    ptrTemp = root; 
    Sptr.push(ptrTemp);
    while( !Sptr.empty() )
    {
        while( ptrTemp->ptrLeft != NULL )
        {
            ptrTemp=ptrTemp->ptrLeft;
            Sptr.push(ptrTemp);
        }
    
        ptrTemp = Sptr.top();
        cout << ptrTemp->iData << endl;
        Sptr.pop();
       
        if( ptrTemp->ptrRight != NULL )
        {
            ptrTemp=ptrTemp->ptrRight; 
            Sptr.push(ptrTemp);
        }
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
    
    inOrder(root);
    cout << "============================" << endl;
    inOrder_iteration(root);
    return 0;
}