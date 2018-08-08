/////////////////////////////////////////////////////////////////
//Aug 15, 2016
//Insert into binary search tree.
//trace pre, in, or post.
//
//Note that same root has returned from this recursive function.
//from insertBST returning root = 0x2387c20
//0x2387c20
//=============================
//Insert 10 to the right
//from insertBST returning root = 0x2387c40
//from insertBST returning root = 0x2387c20
//0x2387c20
//=============================
//Insert 3 to the left
//from insertBST returning root = 0x2387c60
//from insertBST returning root = 0x2387c20
//0x2387c20
//=============================
//Insert 4 to the left
//Insert 4 to the right
//from insertBST returning root = 0x2387c80
//from insertBST returning root = 0x2387c60
//from insertBST returning root = 0x2387c20
//0x2387c20
//=============================
//Insert 1 to the left
//Insert 1 to the left
//from insertBST returning root = 0x2387ca0
//from insertBST returning root = 0x2387c60
//from insertBST returning root = 0x2387c20
//0x2387c20
//=============================
//Insert 11 to the right
//Insert 11 to the right
//from insertBST returning root = 0x2387cc0
//from insertBST returning root = 0x2387c40
//from insertBST returning root = 0x2387c20
//0x2387c20
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
//Aug 7,18    Added more comments.
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
    root = insertBST( root, 13);

    cout << "INORDER" << endl;
    inOrder(root);
    
    cout << "PRE ORDER" << endl;
    preOrder(root);
    
    cout << "POST ORDER" << endl;
    postOrder(root);

    return 1;

}