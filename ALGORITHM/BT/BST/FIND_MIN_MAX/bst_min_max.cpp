/////////////////////////////////////////////////////////////////
// Aug 7, 18
//
//
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
        //What this is saying is to create a child node to 
        //the left of parent.
        //The root->left is linking the child node from the parent's left Node ptr.
        root->left = insertBST( root->left, data);
    } else {
        root->right = insertBST( root->right, data);
    }
    return root;   //Must return the same root all the time.
                   //See the output to confirm that this is the case.
}

int 
iFindMin( NODE *root)
{
    NODE *current;
    
    current = root;
    
    /**
     * 
    This generates infinite loop since 
    while(current != NULL)
    {
        cout << "hello" <<endl;
        if(current->left != NULL)
            current = current->left;
    }
    **/
    
    /*The following works. */
    /*
    while(current != NULL)
    {
        if(current->left != NULL)
            current = current->left;
        else
            break;
    }
    */
    while(current->left != NULL)
    {
        if(current->left != NULL)
            current = current->left;
    } 
    return current->data; 
}

int 
iFindMax( NODE *root)
{
    NODE *current;
    
    current = root;
    
    while(current->right != NULL)
    {
        if(current->right != NULL)
            current = current->right;
    } 
    return current->data; 
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

    cout << "Minumum is " << iFindMin(root) << endl;
    cout << "Maximum is " << iFindMax(root) << endl;
    
    return 1;

}