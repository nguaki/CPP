/////////////////////////////////////////////////////////////////
//Aug 24, 18  Finding height of a tree recursively.
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
//However, the 2nd iteration of the recursion, it is not root.
//It is actually, just a node.
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

//Height of the current node is simply maximum height of left tree 
//or right tree + 1.
//Keep doing this until the node is a left.
//If the node is a leaf, this becomes the base line.
//The height of the node is 0.  So it has to return -1 since the
//function returns at least 1.
//Although this looks simple, but there is a lot going on recursively.
int
iCalHeight( NODE *root )
{
    
   if( root == NULL ) return -1;
   
   return( max(iCalHeight(root->left),iCalHeight(root->right) ) + 1);
    
}

int
main()
{
    NODE *root = NULL;
    
    root = insertBST( root, 5);
    root = insertBST( root, 10);
    root = insertBST( root, 3);
    root = insertBST( root, 4);
    root = insertBST( root, 1);
    root = insertBST( root, 11);
    root = insertBST( root, 15);

    cout << iCalHeight(root) << endl;;
    
    return 1;

}