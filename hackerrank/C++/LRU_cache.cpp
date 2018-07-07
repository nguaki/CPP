//Hackerrank
//
// pure_virtual.cpp 
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    
  public:
    LRUCache( int iCap )
    { 
        cp = iCap;
        head = tail = NULL;
    }
    
    //set() - Set/insert the value off the key, if present, otherwise add the key as the most recently used key. 
    //If the cache has reached its capacity, it should replace the least recently used key with a new key.
    void set(int iKey, int iValue){

        if (mp.size() == 0)
		{
			Node* temp = new Node(iKey, iValue);
			head = tail = temp;
			mp[iKey] = temp;
			return;
		}

		map<int, Node*>::iterator it;
        
        // If node found.
		if ((it = mp.find(iKey)) != mp.end())
		{
			Node* temp = it->second;
			temp->value = iValue;
            
            //If the node is the last one.
			if (tail == temp && tail->prev != NULL) tail = tail->prev; //if tail->prev = null, then single element
			
            //Unlink the node from linked list.
            if(temp->prev!=NULL)
				temp->prev->next = temp->next;
			if(temp->next!=NULL)
				temp->next->prev = temp->prev;

			//Insert the node between the head and the 1st node.
            temp->next = head;
			temp->prev = NULL;
			//head->prev = temp;  //<==Why is this important!!!
			head = temp; //re-assign head
		}
        
        //If the number of nodes hit capacity.
		else
		{
			Node* temp = new Node(NULL, head, iKey, iValue); //new node created
			mp[iKey] = temp; //assigned to map at the beginning
			//head->prev = temp;  // <==== Why is this needed?
			head = temp; 
			if (mp.size()>cp) // delete last element as per link list
			{
				temp = tail->prev;
				if (temp != NULL)
					temp->next = NULL;
				mp.erase(tail->key);
				delete tail;
				tail = temp;
			}
		}
	}

    
       //////////////////////////////////////////////////////////////////////////////
       //get() - Get the value (will always be positive) of the key if the key 
       //exists in the cache, otherwise return -1. Then make that key as the most recently used key.
       int get( int iKey ){
                
        if(mp.find(iKey) != mp.end())
            return mp[iKey]->value;    // <=== After this is used, doesn't it have to move the node to the top of the node?

         else
            return -1;
       }
       
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
