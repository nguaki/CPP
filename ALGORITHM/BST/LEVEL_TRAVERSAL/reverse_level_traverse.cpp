/////////////////////////////////////////////////////////////////
//Aug 26, 18
//
//Understanding of Binary tree  DS.
//Understanding of application of stack and Queue.
//The intricate relationship between tree traversal and stack and queue.
//The key of this traversal is going to right child first and pushing it
//to the stack.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <stack>

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

void
vTraverseLevelReverse(NODE *root)
{
    queue<NODE *> Q;
    stack<NODE *> S;
    
    //Initiates queue with the root.
    Q.push(root);
    S.push(root) ;
    
    while(!Q.empty()){
        NODE *temp;
        
        temp = Q.front();
        Q.pop();
        cout << "popping from Q" << temp->data << endl; 
        if(temp->right != NULL){
            Q.push(temp->right);
            S.push(temp->right);    
            cout << "push to stack S" << temp->right->data << endl;
        } 
        
        if(temp->left != NULL){
            Q.push(temp->left);
            S.push(temp->left);
            cout << "push to stack S" << temp->left->data << endl;
        } 
    } 
        
    while(!S.empty())    //Print out the data.
    {
       NODE* ptrNode;
       ptrNode = S.top();
       
       cout << ptrNode->data << endl;
       S.pop(); 
    }
}
void
inOrder( NODE* root )
{
    if (root == NULL) return;
    
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}
int
main()
{
    NODE *root = NULL;
    
    root = insertBST( root, 5);
    root = insertBST( root, 2);
    root = insertBST( root, 7);
    root = insertBST( root, 1);
    root = insertBST( root, 3);
    root = insertBST( root, 6);
    inOrder(root);
    
    vTraverseLevelReverse(root);
    return 1;

}