//9:35
//9:54
#include <iostream>

using namespace std;

struct NODE{
    int  iData;
    NODE *pRightChild;
    NODE *pLeftChild;
};

//Each function call has its own stack and root.
//There are huge layers of stacks.
//This functions always returns the same root.
NODE *
pInsertBST( NODE *root, int iData )
{
    if( root == NULL ){
        root = new NODE;
        root->iData = iData;
        root->pRightChild = NULL;
        root->pLeftChild  = NULL;
    }else if( iData < root->iData)
        root->pLeftChild = pInsertBST(root->pLeftChild,iData);
    else
        root->pRightChild = pInsertBST(root->pRightChild,iData);
        
    return root;
}

//Huge layers of stack.
//Very mind boggling to trace these manually how these stacks work.
void
vTraversInOrder( NODE *root )
{
    if( root == NULL ) return;
    
    if( root->pLeftChild != NULL ) vTraversInOrder( root->pLeftChild );
    cout << root->iData << endl;
    if( root->pRightChild != NULL ) vTraversInOrder( root->pRightChild );
}

void
vTraversPreOrder( NODE *root )
{
    if( root == NULL ) return;
    
    cout << root->iData << endl;
    if( root->pLeftChild != NULL ) vTraversPreOrder( root->pLeftChild );
    if( root->pRightChild != NULL ) vTraversPreOrder( root->pRightChild );
}
void
vTraversPostOrder( NODE *root )
{
    if( root == NULL ) return;
    
    if( root->pLeftChild != NULL ) vTraversPostOrder( root->pLeftChild );
    if( root->pRightChild != NULL ) vTraversPostOrder( root->pRightChild );
    cout << root->iData << endl;
}

NODE *
bSearch( NODE *root, int iData )
{
    if( root == NULL ){
        return NULL;
    }
    if( iData == root->iData ){
        return root;
    }
    
    if( iData < root->iData && root->pLeftChild != NULL)
        return bSearch(root->pLeftChild, iData);
    
    //else if( iData > root->iData && root->pRightChild != NULL)
        return bSearch(root->pRightChild, iData);
        
}

int
main(void)
{
    NODE *root;
    
    root = pInsertBST( root, 5);
    root = pInsertBST( root, 10);
    root = pInsertBST( root, 3);
    root = pInsertBST( root, 4);
    root = pInsertBST( root, 1);
    root = pInsertBST( root, 11);
    
    cout << "---------------------------------" << endl;
    vTraversInOrder( root );
    cout << "---------------------------------" << endl;
    vTraversPreOrder( root );
    cout << "---------------------------------" << endl;
    vTraversPostOrder( root );
    
    if( bSearch(root, 10) != NULL ) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    if( bSearch(root, 5) != NULL ) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    if( bSearch(root, 100) != NULL ) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    if( bSearch(root, 11) != NULL ) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    if( bSearch(root, 500) != NULL ) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 1;
}
