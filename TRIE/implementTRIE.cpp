struct TrieNode { 
TrieNode* children[26];
bool isEndOfWord;
};

class Trie {
public:

//function to create new Node
TrieNode* getTrieNode(){
    TrieNode* newNode = new TrieNode();
    newNode->isEndOfWord = false;

    for(int i=0;i<26;i++){
      newNode->children[i]=NULL;
    }
    return newNode;
}

   TrieNode* root;

    Trie() {
      root = getTrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(int i=0;i<word.size();i++){
            char ch= word[i];
            int idx= ch-'a';

            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getTrieNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isEndOfWord = true;  // reached end of the word
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(int i=0;i<word.size();i++){
            char ch= word[i];
            int idx= ch-'a';

            if(crawler->children[idx]==NULL){
               return false;
            }
            crawler=crawler->children[idx];
        }
        if(crawler!=NULL && crawler->isEndOfWord==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        int i;
        for(i=0;i<prefix.size();i++){
            char ch= prefix[i];
            int idx= ch-'a';

            if(crawler->children[idx]==NULL){
               return false;
            }
            crawler=crawler->children[idx];
        }
        if(i==prefix.size()){
            return true;
        }
        return false;
    }
};