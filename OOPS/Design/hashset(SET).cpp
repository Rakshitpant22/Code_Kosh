class MyHashSet {
public:
    int numBuckets;
    vector<list<int>> buckets;

    int getHashValue(int key) {
        return key%numBuckets;
    }
    
    MyHashSet() { //constructor
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
    }
    
    void add(int key) {
        int index = getHashValue(key);
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr == buckets[index].end()) //if not found 
            buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr != buckets[index].end()) //if  found 
            buckets[index].erase(itr);
    }
    
    bool contains(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        return itr != buckets[index].end();
    }
};

