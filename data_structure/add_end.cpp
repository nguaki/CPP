////////////////////////////////////////////////////
//Aug 8, 2016
//
// Adds a new node at the end of the linked list.
// Looks like O(1).
//
/////////////////////////////////////////////////////
#include <iostream>

using namespace std;
    
struct NODE
{
    int  data;
    NODE *next;
};
    
void traverseLinkedList( NODE *currentNode )
{
    while( currentNode != NULL)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

//Creates a node and r  eturning the address of a node.
NODE* createNode( int data )
{
    //Create a new node.
    NODE *temp;
    
    temp = new NODE();
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

int 
main()
{
    NODE *head, *tail, *newNode;
    int  count, data;
    
   //Start a new linked list with the user inputting the data. 
    head = NULL;
    count = 1;
    do
    {
        cout << "Enter a number:";
        cin  >> data;
            
        //create a new node;
        newNode = createNode( data );

        if( count == 1 ){
            head = tail = newNode;

        } else {
            tail->next = newNode;
            tail = newNode;
        }
        traverseLinkedList(head);

        count ++;
    }while( data != 0 );
    
    return 0;
 
}