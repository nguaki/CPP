/////////////////////////////////////////////////////////////////
//Aug 25, 2018
//Find the leftmost and rightmost nodes of a tree.
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
    
}
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

void inOrder( NODE *root, int& leaves_cnt )
{
    if( root == NULL){
        return;
    }
    
    if( root->left != NULL ) inOrder(root->left, leaves_cnt);
    cout << root->data << endl;
    if( root->left == NULL and root->right == NULL ) leaves_cnt++; //Keeps track of how many nodes are leaves.
    
    if( root->right != NULL ) inOrder(root->right, leaves_cnt);
}

void 
vPrintLeftRightMostNodes(NODE* root)
{
    // Traversing level by level
    queue<NODE*> q;
    queue<NODE*> temp;
    q.push(root);
 
    while (!q.empty()) {
        NODE* n;
 
        // Compute sum of nodes and
        // count of nodes in current
        // level.
        int sum = 0, count = 0;
        bool bFirstInLevel = true;
        bool bOneNOnly = false;
        while (!q.empty()) {
            n = q.front();
            if(bFirstInLevel){
                bFirstInLevel = false;     
                cout<< n->data << endl;
                if (q.size() ==1) bOneNOnly = true;
            }
            q.pop();
            sum += n->data;
            count++;
            if (n->left != NULL)    //temp is setting up for next level
                temp.push(n->left);
            if (n->right != NULL)
                temp.push(n->right);
        }
        //The last one in the level.
        if (bOneNOnly == false ) cout<< n->data << endl;
        
        q = temp;//Transfer all data for next level.
        
        //Erase all data from temp.
        while(!temp.empty())
            temp.pop();
            
    }
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
    int leaves_cnt = 0;
    inOrder(root, leaves_cnt);
    
    cout << "Left and right most nodes\n";
    vPrintLeftRightMostNodes(root);
    
    return 1;

}