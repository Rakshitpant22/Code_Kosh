//! https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Trie {
    public:
        struct TrieNode {
            TrieNode* children[10];
            bool isEndOfWord;
        };

        TrieNode* getNode() {
            TrieNode* newNode = new TrieNode();
            newNode->isEndOfWord = false;
            for (int i = 0; i < 10; i++) {
                newNode->children[i] = NULL;
            }
            return newNode;
        }
        TrieNode* root;

        Trie() { 
        root = getNode(); 
        }
       
       void insert(string word){
        TrieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'0';

            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isEndOfWord=true;
       }

     int isprefix(string word){
        TrieNode* crawler=root;
        int len=0;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'0';
            if(crawler->children[idx]==NULL){
                return len;
            }
            len++;
            crawler=crawler->children[idx];
        }
          return len;
       }

    };



class Solution {
    public: 
     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int i=0;i<arr1.size();i++){
        trie.insert(to_string(arr1[i]));
        }

        int ans=0;
        for(auto it:arr2){
           ans=max(ans,trie.isprefix(to_string(it)));
        }
        return ans;
    }
};