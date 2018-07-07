// Aug 8, 2016
//
// Implementation of double linked list.
//
//OUTPUT
//1
//2
//3
//4
//5
//6
//6
//5
//4
//3
//2
//1

#include <iostream>

using namespace std;

struct NODE{
    int data;
    NODE *prev;
    NODE *next;
};

NODE *head, *tail;

NODE* generateNode( int data )
{
    NODE *newNode;
    
    newNode = new NODE();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void addBeginning( int data )
{
    NODE *newNode;
    newNode = generateNode( data );
    
    if(head == NULL){
        head = tail = newNode;
        
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void addEnding( int data )
{
    NODE *newNode;
    newNode = generateNode( data );
    
    if(tail == NULL){
        tail = head = newNode;
        
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void traverseLinkedListForward()
{
    NODE *currentNode = head;
    
    while( currentNode != NULL ){
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

void traverseLinkedListReverse()
{
    NODE *currentNode = tail;
    
    while( currentNode != NULL ){
        cout << currentNode->data << endl;
        currentNode = currentNode->prev;
    }
}

int
main()
{
    addBeginning(3); 
    traverseLinkedListForward();
    cout << endl;
    traverseLinkedListReverse();
    cout << endl;
    addBeginning(2);
    traverseLinkedListForward(); 
    cout << endl;
    traverseLinkedListReverse();
    cout << endl;
    
    addBeginning(1); 
    traverseLinkedListForward(); 
    cout << endl;
    traverseLinkedListReverse();
    cout << endl;
    
    addEnding(4); 
    traverseLinkedListForward(); 
    cout << endl;
    traverseLinkedListReverse();
    cout << endl;
    
    addEnding(5); 
    traverseLinkedListForward();
    traverseLinkedListReverse();
    cout << endl;
    
    addEnding(6); traverseLinkedListForward(); traverseLinkedListReverse();
} 
