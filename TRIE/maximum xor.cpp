//^ BIT TRIE IMPLEMENTATION

//!TC= O(n Log(maximum no))
//!= O(nlog(32))

class Solution {
class Trie{
public:
struct TrieNode{
    TrieNode* left;
    TrieNode* right;
};
TrieNode* getNode(){
    TrieNode* newNode= new TrieNode();
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
  TrieNode* root;

  Trie(){
    root=getNode();
  }

void insert(int num){
  TrieNode* crawler = root;
  for(int i=31;i>=0;i--){ // will start from the most significant 31st to 0th bit
    int ith_bit = 1 & (num >> i);

    if(ith_bit==0){
        if(crawler->left==NULL){
        crawler->left = new TrieNode();
        }
        crawler=crawler->left;
    }
    else{
        if(crawler->right==NULL){
        crawler->right = new TrieNode();
        }
        crawler=crawler->right;
     }
   }
  }

  int getmax(int num){ 
   TrieNode* crawler = root;
   int ans=0; // the integer which get from trie with which num ^ is maximum

   for(int i=31;i>=0;i--){
    int ith_bit= 1 & (num >> i);

    if(ith_bit==0){
        if(crawler->right){
            ans= ans | (1<<i);
            crawler=crawler->right;
        }
        else{
            crawler=crawler->left;
        }
    }
    else{
        if(crawler->left){
            crawler=crawler->left;
        }
        else{
             ans= ans | (1<<i);
            crawler=crawler->right;
        }
     }
   }
  return ans^num;
 }
};

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto it:nums){
            trie.insert(it);
        }
        int ans=-1e9;
        for(auto it:nums){
            ans=max(ans,trie.getmax(it));
        }
        return ans;
    }
};