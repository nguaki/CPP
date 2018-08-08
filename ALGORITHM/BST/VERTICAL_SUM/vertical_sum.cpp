/////////////////////////////////////////////////////////////////
//Aug 8, 18
//-2  1
//-1  3
//0  18
//1  10
//2  11
//3  13
//
//The variable hd must be an argument to a function, it cannot be a global
//variable.  In recursive function, the state of each stack frame is preserved.
//Functional argument is preserved inside the stack frame.
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>

using namespace std;

map<int,int> mpVertSum;

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
/////////////////////////////////////////////////////////////////////////////
//Aug 8, 18
//Having hd(horizontal distance) in the arguements preserves the hd value per
//stack frame.  
/////////////////////////////////////////////////////////////////////////////
void inOrder( NODE *root, int hd )
{
    if( root == NULL){
        return;
    }
    
    if( root->left != NULL ){
        inOrder(root->left, hd-1);
    }
    cout << "Horizontal Distance " << hd << "   ";
    //Add up the vertical sum.
    mpVertSum[hd] += root->data;
    
    cout << root->data << endl;
    if( root->right != NULL ){
        inOrder(root->right, hd+1);
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
    root = insertBST( root, 9);
    root = insertBST( root, 11);
    root = insertBST( root, 13);
    
    //2nd argument is the hd (horizontal distance) of the root.
    inOrder(root, 0);
   
    for( auto &mp: mpVertSum )
        cout << mp.first << "  " << mp.second << endl;
    return 1;

}