https://leetcode.com/problems/all-oone-data-structure/description/

//! Brute Force
class AllOne {
public:
unordered_map<string,int>mpp;
    AllOne() {
        
    }
    
    void inc(string key) {
        mpp[key]++;
    }
    
    void dec(string key) {
          if(mpp[key]==1){
            mpp.erase(key);
          }
          else{
          mpp[key]--;
          }
    }
    
    string getMaxKey() {
        int maxi=-1e9;
        string a="";
        for(auto it:mpp){
            if(it.second>maxi){
                maxi=it.second;
                a=it.first;
            }
        }
        return a;
    }
    
    string getMinKey() {
        int mini=1e9;
        string a="";
        for(auto it:mpp){
            if(mini>it.second){
                mini=it.second;
                a=it.first;
            }
        }
        return a;
    }
};

//! Optimal