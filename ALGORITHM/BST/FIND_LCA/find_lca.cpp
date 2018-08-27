/////////////////////////////////////////////////////////////////
//Aug 25, 2018
//Find LCA of a BST.
//Least common ancestor both recusively or iteratively.
//////////////////////////////////////////////////////////////////////
#include <iostream>
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
    
}
NODE *insertBST( NODE *root, int data )
{
    //NODE *temp;
    if( root == NULL )
        root = ptrGenerateNode( data );
        
    else if( data <= root->data ){
        cout << "Insert " << data << " to the left" << endl;
        //What this is saying is to create a child node to 
        //the left of parent.
        //The root->left is linking the child node from the parent's left Node ptr.
        root->left = insertBST( root->left, data);
    } else {
        cout << "Insert " << data << " to the right" << endl;
        root->right = insertBST( root->right, data);
    }
    cout << "from insertBST returning root = " << root << endl;
    return root;   //Must return the same root all the time.
                   //See the output to confirm that this is the case.
}

void inOrder( NODE *root, int& size )
{
    if( root == NULL){
        return;
    }
    
    if( root->left != NULL ) inOrder(root->left, size);
    cout << root->data << endl;
    size++; //Keeps track of how many nodes were visited.
    if( root->right != NULL ) inOrder(root->right, size);
}
 
NODE*
ptrFind_LCA( NODE* node, int m, int n)
{
    
    if (m < node->data && n < node->data)    
        //ptrTemp = ptrFind_LCA(node->left, m,n);
        node = ptrFind_LCA(node->left, m,n);
    else if (m > node->data && n > node->data)    
        //ptrTemp = ptrFind_LCA(node->right, m,n);
        node = ptrFind_LCA(node->right, m,n);
    else
        return node;
}
NODE*
ptrFind_LCA_iteratively( NODE* node, int m, int n)
{
    while( node != NULL )
    {
        if ( m < node->data && n < node->data)    
            node = node->left;
        else if (m >node->data && n >node->data)    
            node = node->right;
        break;
    }    
    return node;
}

int
main()
{
    NODE *root = NULL;
    
    root = insertBST( root, 5);
    cout << root <<endl;
    cout << "=============================" <<endl;

    root = insertBST( root, 10);
    cout << root <<endl;
    cout << "=============================" <<endl;
    root = insertBST( root, 3);
    cout << root <<endl;
    cout << "=============================" <<endl;
    root = insertBST( root, 4);
    cout << root <<endl;
    cout << "=============================" <<endl;
    root = insertBST( root, 1);
    cout << root <<endl;
    cout << "=============================" <<endl;
    root = insertBST( root, 11);
    cout << root <<endl;
    root = insertBST( root, 13);

    cout << "INORDER" << endl;
    int size;
    size = 0;
    inOrder(root, size);
    cout << "tree size is :" << size << endl;
    
    NODE* ptrTemp;
    cout << "LCA is : ";
    ptrTemp = ptrFind_LCA( root, 1, 4);
    cout << ptrTemp->data << endl; 
    assert(ptrTemp->data == 3);
    ptrTemp = ptrFind_LCA( root, 3, 13);
    cout << ptrTemp->data << endl; 
    assert(ptrTemp->data == 5);
    
    ptrTemp = ptrFind_LCA_iteratively( root, 1, 4);
    cout << ptrTemp->data << endl; 
    assert(ptrTemp->data == 3);
    ptrTemp = ptrFind_LCA_iteratively( root, 3, 13);
    cout << ptrTemp->data << endl; 
    assert(ptrTemp->data == 5);
    return 1;

}