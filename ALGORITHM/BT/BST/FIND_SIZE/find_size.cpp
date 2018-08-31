/////////////////////////////////////////////////////////////////
//Aug 25, 2018
//May 1, 18   Fixed preOrder(), postOrder() to call itself.
//            This seemed to resolve the problem of incorrect
//            trasversing.
//Aug 7,18    Added more comments.
//
//Aug 25,18   Using in-order sort to come up with tree size.
//////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};

//Aug 7, 2018
//In order this program to work, this function must
//return same address of root.
//Tough hurdle to tracing recursive function is that
//each stack frame has different set of variables and its
//values.
//The argument root is misleading. When this is called for the 
//first time in the cycle of recursion, root really means the root.
//Howeve
NODE *insertBST( NODE *root, int data )
{
    //NODE *temp;
    if( root == NULL ){
        root = new NODE;
        root->data = data;
        root->left = root->right = NULL;
    }
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
    
    return 1;

}