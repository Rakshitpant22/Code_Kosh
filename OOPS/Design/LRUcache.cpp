//! LRU cache

// An LRU Cache evicts the least recently used item when the cache reaches its maximum capacity. The two main operations required are:

// 	1.	get(key): Fetches the value of the key if the key exists in the cache, otherwise returns -1.
// 	2.	put(key, value): Inserts or updates the value if the key exists. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

//! HOW:
// •	Doubly Linked List: To maintain the order of usage (most recently used at the front, least recently used at the back).
// •	HashMap: To provide O(1) access to the cache items.

//^ SUMMARY ::
// we are using head & tail as -1 initially 
// we have function delete _node(node address) & insert_after_HEAD(node address)
//  map to store key along with linked list node data 

//! 1. for get function
// we have to get key from map then if present --> (delete_node(map[node_adress])) --> insert_after_HEAD(head);
//! 2. for put function
// we have to get key from map then if present 
//    CASE 1: If present in map --> take node_address(let be x)--> assign value to it --->delete_node(x)--> insert_after_HEAD(node);
//    CASE 2: If key not present in map:
//      case2.1: If cache capacity is full--> take address of tail's prev --> delete that node (from map too)--> create new node-->store key in map--> insert_after_HEAD(node)
//      case2.2: If cache capacity is not full-->create new node-->store key in map--> insert_after_HEAD(node);

//! IMPLEMENTATION:

#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;

class LRU_Cache{

class Node{
    public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
      }
};
Node* head= new Node(-1,-1);
Node* tail= new Node(-1, -1);

int capacity;
unordered_map<int,Node*>mpp;//for storing key and node's address

public:
LRU_Cache(int capacity){
this->capacity=capacity;
head->next=tail;
tail->prev=head;
}
~LRU_Cache() { //~ The destructor is necessary for cleaning up resources, preventing memory leaks, and ensuring that your LRU Cache operates efficiently and correctly.
        Node* node = head;
        while (node) {
            Node* next = node->next;
            delete node;
            node = next;
        }
}
void add_node(Node* newnode){
 Node* temp=head->next;    //origianlly jo head s agla tha 
 newnode->next=temp; //usle badle nenode ko vha lana ha
 newnode->prev=head;
 head->next=newnode;
 temp->prev=newnode;
}

void delete_node(Node* delnode){
  Node* delnode_next= delnode->next;
  Node* delnode_prev= delnode->prev;
  delnode_prev->next= delnode_next;
  delnode_next->prev= delnode_prev;
}

int get(int key){
 if(mpp.find(key)!=mpp.end()){
    Node* node= mpp[key];
    int ans= node->value; // store ans in variable for returning 

    mpp.erase(key);       //delete from lru's position 
    delete_node(node);

    add_node(node);      // place in front of cache
    mpp[key]=head->next;

    return ans;
 }
 return -1; //if key not present
}

void put(int key,int val){
 if(mpp.find(key)!=mpp.end()){ // if key already exist's in the map
    Node* existing_node= mpp[key];    
    mpp.erase(key);  
    }
    if(mpp.size()==capacity){ //cache full
        Node* node= tail->prev;
        delete_node(node);
        mpp.erase(node->key);
    }    
    //ye to krna hi ha both cases me 
    Node* x= new Node(key,val); 
    add_node(x);
    mpp[key]=head->next;
}

};

int main()
{
LRU_Cache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Returns 1
    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl; // Returns -1 (not found)
    cache.put(4, 4); // Evicts key 1
    cout << cache.get(1) << endl; // Returns -1 (not found)
    cout << cache.get(3) << endl; // Returns 3
    cout << cache.get(4) << endl; // Returns 4
    return 0;
}



//! USES
//~ •  Web Caching: 
//     Stores recently accessed web pages to quickly retrieve them on subsequent requests, reducing load times and server demand.
//~ •  Database Query Caching:
//     Keeps results of frequent queries to minimize database load and speed up response times.
//~    Operating Systems: 
//     Manages memory by keeping frequently accessed pages in faster storage (RAM) and swapping out less used pages to disk.
//~ •  Content Delivery Networks (CDNs):
//     Caches popular content close to users to reduce latency and server load.
//~ •  Mobile Applications: 
//     Caches API responses to minimize data usage and enhance user experience.


