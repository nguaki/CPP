/////////////////////////////////////////////////////////////////
//Aug 15, 2016
//Insert into binary search tree.
//trace pre, in, or post.
//OUTPUT
//INORDER
//1
//3
//4
//5
//10
//11
//PRE ORDER
//5
//1
//3
//4
//10
//11
//POST ORDER
//1
//3
//4
//10
//11
//5
//
//May 1, 18   Fixed preOrder(), postOrder() to call itself.
//            This seemed to resolve the problem of incorrect
//            trasversing.
//////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};

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
        root->left = insertBST( root->left, data);
    } else {
        cout << "Insert " << data << " to the right" << endl;
        root->right = insertBST( root->right, data);
    }
    cout << "from insertBST returning root = " << root << endl;
    return root;
}

void inOrder( NODE *root )
{
    if( root == NULL){
        return;
    }
    
    if( root->left != NULL ) inOrder(root->left);
    cout << root->data << endl;
    if( root->right != NULL ) inOrder(root->right);
}
  
void preOrder( NODE *root )
{
    if( root == NULL){
        return;
    }
    
    cout << root->data << endl;
    //inOrder(root->left);
    //inOrder(root->right);
    if( root->left != NULL ) preOrder(root->left);
    if( root->right != NULL ) preOrder(root->right);
}

void postOrder( NODE *root )
{
    if( root == NULL){
        return;
    }
    
    //inOrder(root->left);
    if(root->left != NULL) postOrder(root->left);
    //inOrder(root->right);
    if(root->right != NULL) postOrder(root->right);
    cout << root->data << endl;
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

    cout << "INORDER" << endl;
    inOrder(root);
    
    cout << "PRE ORDER" << endl;
    preOrder(root);
    
    cout << "POST ORDER" << endl;
    postOrder(root);

    return 1;

}