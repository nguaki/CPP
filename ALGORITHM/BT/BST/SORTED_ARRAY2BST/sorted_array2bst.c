/////////////////////////////////////////////////////////////////
//Aug 25, 2018
//Convert sorted array to bst.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};

NODE*
ptrGenerateNode( int iD )
{
    NODE* ptrTemp;
    
    ptrTemp = new NODE;
    ptrTemp->data = iD;
    ptrTemp->left = ptrTemp->right = NULL;
    
    return ptrTemp;
}

NODE *
insertBST( int iBeginIndex, int iEndIndex, int* iArray )
{
    NODE *node;
    if( iBeginIndex > iEndIndex )
        return NULL;
        
    //What seems so obvious causes a headache.
    //int iMid = ( iEndIndex - iBeginIndex )/2;
    int iMid = ( iEndIndex + iBeginIndex )/2;
    
    node = ptrGenerateNode( iArray[iMid] );
        
    //Keeps generating the a left child node.
    node->left  =  insertBST( iBeginIndex, iMid - 1, iArray );
    node->right =  insertBST( iMid + 1, iEndIndex , iArray );
    
    //Returns the address of a new node.
    return node;   
    
}
NODE *
insertBST_root( NODE *root, int iBeginIndex, int iEndIndex, int* iArray )
{
    NODE *node;
    if( iBeginIndex > iEndIndex )
        return NULL;
        
    //What seems so obvious causes a headache.
    //int iMid = ( iEndIndex - iBeginIndex )/2;
    int iMid = ( iEndIndex + iBeginIndex )/2;
    
    node = ptrGenerateNode( iArray[iMid] );
        
    //Keeps generating the a left child node.
    node->left  =  insertBST_root( root, iBeginIndex, iMid - 1, iArray );
    node->right =  insertBST_root( root, iMid + 1, iEndIndex , iArray );
    
    //Returns the address of a new node.
    return node;   
    
}

void 
inOrder( NODE* root )
{
    if( root == NULL){
        return;
    }
    
    if( root->left != NULL ) 
        inOrder(root->left);
        
    cout << root->data << endl;
    
    if (root->right != NULL )
        inOrder(root->right);
}

int
main()
{
    NODE *root = NULL;
    NODE *root1 = NULL;
    int ia[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    
    
    //Send in begin and ending indices of array.
    root = insertBST( 0, 24, ia );
    inOrder( root );
    cout << "=====================================" << endl;
    root1 = insertBST_root( root1, 0, 24, ia );
    inOrder( root1 );
    
    return 1;
}