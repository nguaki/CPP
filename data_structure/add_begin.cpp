/////////////////////////////////////////////////////////////////////////
// Aug 8, 2016
//
// Enters a new node in the beginning. So this would be O(1).
//
// May 1, 2018       Commented the difference between C/C++ in typedef.
/////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
////////////////////////////////////////////////
//Note the difference with C and C++
//In C,  
//    typdef struct NODE
//    {
//         int data;
//         stuct NODE *next;
//    }NODE;
//Now NODE is a legit type of a structure in C.
///////////////////////////////////////////////

struct NODE{
    int data;
    NODE *next;
};

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

/**
 * Traverse and read data.
 */
void traverseLinkedList( NODE *linker )
{
    while( linker != NULL)
    {
        //cout << "hello" << endl;
        cout << linker->data << endl;
        linker = linker->next;
    }
    
    //cout << linker->data << endl;
}

//Prints in order from head to tail.
void traverseUsingRecursive( NODE *linker )
{

    if( linker != NULL )
        cout << linker->data << endl;

    if( linker->next == NULL ){
        return;
    }
    traverseUsingRecursive( linker->next );

}
//Prints reverse: from tail to head.
void traverseReverseUsingRecursive( NODE *linker )
{
    static int count = 0;
    
    if( linker == NULL ){
        return;
    }
    
    count++;
    traverseReverseUsingRecursive( linker->next );
    cout << count << ":" <<linker->data << endl;
    count --;
}

//following causes infinite loop.
//no need for while loop.
void traverseReverseUsingRecursiveWhile( NODE *linker )
{
    static int count = 0;
    NODE *t;
    
    if( linker == NULL ){
        return;
    }
    
    count++;
    
    t = linker;
    while( t != NULL ){
        traverseReverseUsingRecursiveWhile( t->next );
        //t = t->next;
    }
    cout << count << ":" <<linker->data << endl;

}

int
main(){
    
    NODE *head, *temp, *newNode;
    int count, data;
    

    count = 1;
    do{
        cout << "enter a number:" << endl;
        cin >> data;
        
        newNode = createNode(data);

        if( count == 1){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        count++;
    
        traverseLinkedList(head);
        
        cout << "Using recursive" << endl;
        traverseUsingRecursive(head);
        cout << "list reverse using recursive" << endl;
        traverseReverseUsingRecursive(head);
        //traverseReverseUsingRecursiveWhile(head);
        
    }while( data != 0);
     
    
    return 0;
}