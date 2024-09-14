//! Design a HashMap without using any built-in hash table libraries.
//~ 1. Understand the Basics
// 	•	A hashtable is a data structure that stores key-value pairs.
// 	•	It uses a hash function to map keys to indices in an array (bucket array).
// 	•	Handles collisions using techniques like chaining (linked lists) or open addressing.

// //~ 2. Choose the Hash Function
//  •	The hash function should distribute keys uniformly across the buckets to avoid clustering.
//  •	A simple example: hash = key % array_size.

//~ 3. Handle Collisions
	//^ •	Chaining: Store multiple elements in a single bucket using a linked list.
	//^ •	Open Addressing: Find the next available slot using methods like linear probing or quadratic probing.
    // linear me agar us hash bucket m hai koi to usse just next p value jaegi and for quadratic its uses function for same
    // but open addressing still have issues (we further use double hashing for that)

//! LOAD FACTOR:(LF)
// It is defined as the ratio of the number of elements (keys) in the hash table to the total number of slots (buckets) in the table.
//*  Load Factor =(Number of Elements or (keys) in the Table) / (Total Number of Bucket)
//  Suppose you have a hash table with 100 buckets (slots), and you’ve inserted 50 elements. The load factor would be:
//  LF = 50/100 = 0.5
//* IDEAL RANGE : 0.7 to 0.75 (IF GREATER THEN REHASHING IS TO BE DONE)ie:size inc kro bucket increase then rehash

	//•	Need: The load factor is essential for maintaining the balance between efficient operation and memory utilization in a hash table.
	//•	Function: It controls when to resize the table and how to manage collisions, ensuring the hash table continues to operate near  O(1)  time complexity for most operations.
	//• A low load factor reduces the likelihood of collisions (when two different keys hash to the same index). Fewer collisions mean that the average time complexity for operations remains close to  O(1) , which is the ideal for hash table performance.
	//• Without controlling the load factor, the hash table could become too full, leading to many collisions. This would degrade the performance to  O(n)  in the worst case, especially if using techniques like chaining or open addressing.


//! APPROACH 1 considerations:

// For not very large data ie key can max be 10^6
// key represent index and value = value
// here we can define array of size +1  tc=o(1) but sc is more moreover this is valid for 0=<key<= size or key is not in ex string etc:


//! APPROACH 2 :(optimal)
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <utility> // for std::pair
using namespace std;

class HashMap{ //key,value
	vector<list < pair <int,int> > >buckets;
	int size=10000;
	int count;  // Tracks the number of elements in the HashMap

    public:
	HashMap(){
	buckets.resize(size);
	count=0;
	}

	void put(int key, int value) {
        int bucket_no = key%size; //hash key
        auto & chain = buckets[bucket_no]; 

        for(auto& it:chain) { //if key and value already found in bucket
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.__emplace_back(make_pair(key, value)); //else create new in (list)
		count++;
		//! In vector this can be done via == chain.emplace_back(make_pair(key, value)); 
    } 
	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
        int bucket_no = key%size;
        auto& chain = buckets[bucket_no];
        if(chain.empty()) //agr us key ki chain hi khaali hai to
            return -1;

        else{         //else us chain m iterate krunga or us key ko dhundunga
        for(auto& it:chain) {  
            if(it.first == key)
                return it.second;
          }
		}
        return -1;
    }
	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
        int bucket_no = key%size;
        auto& chain = buckets[bucket_no];
        
        /*Traditional way to remove from a list*/
        for (auto it=chain.begin(); it!=chain.end(); ) {
            if(it->first == key) {
                chain.erase(it);
				count--;
                return;
            }
            it++;
        }
	}
        
        /*Smart way to remove from a list*/
        //chain.remove_if([key](auto it) { return it.first == key; });

		int mapsize() const {
        return count;  // Return the number of elements in the HashMap
    }
};
	int main() {
    HashMap a1;
    a1.put(1, 4);
    a1.put(9, 4);

    cout <<a1.mapsize() << endl;  
    cout << a1.get(1) << endl;  
    a1.remove(1);

    cout <<a1.mapsize() << endl; 
    cout << a1.get(1) << endl; 

    return 0;
}

//!   USES	
//~	• Database Indexing: 
//    Hash tables are used for indexing data in databases. This allows for fast retrieval of records based on a key.
//~ • Caching:
//    Hash tables are the backbone of various caching mechanisms, including those in web servers, where they store sessions, user data, etc.
//~	• Symbol Table in Compilers:
//    Hash tables are used to store variables, functions, and object names in compilers.
//~ • DNS Resolution: 
//    Hash tables are used in DNS resolvers to quickly translate domain names to IP addresses.
//~ • Load Balancers: 
//    Hash tables can be used in load balancers to store and quickly retrieve session information.
//~ • Social Media Platforms: 
//    Platforms like Facebook use hash tables to store and retrieve user data, posts, and relationships efficiently.
