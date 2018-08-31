/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>

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

//Aug 7, 2018
//C++ is fantastic!!!
//All these amazing data structure and objects make programmer's job
//so enjoyable.
void
vTraverseLevel(NODE *root)
{
    queue<NODE *> Q;
    
    //Initiates queue with the root.
    Q.push(root);
    
    while(!Q.empty()){
        NODE *temp;
        
        //Get the front of the queue.
        temp = Q.front();
        //Push its left child node to the queue.
        if(temp->left != NULL) Q.push(temp->left);
        //Push its right child node to the queue.
        if(temp->right != NULL) Q.push(temp->right);
        //Print out the data.
        cout << temp->data << endl;
        //Pop it out.
        Q.pop();
    }
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
    root = insertBST( root, 13);

    vTraverseLevel(root);
    return 1;

}