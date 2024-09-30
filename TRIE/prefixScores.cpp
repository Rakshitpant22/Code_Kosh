// for every word calculate the prefix score\
// prefix score = no of prefix string of a word that are present in array & store cnt in array

words = [ "abc", "ab", "bc", "b" ] ans = [ 5, 4, 3, 2 ]

    ex abc-- a(2), ab(2), abc(1) = 2 + 2 + 1 = 5 
        ab-- a(2), ab(2) = 2 + 2 = 4 
        bc-- b(2), ab(1) = 2 + 1 = 3 
        b-- b(2) = 2

        ans = [ 5, 4, 3, 2 ]

 // BRUTE FORCE
     //  unordered_map<string,int>mpp;
    
     // for(int i=0;i<n;i++){
     //     string temp="";
     //     for(auto it:words[i]){
     //         temp+=it;
     //         mpp[temp]++;
     //     }
     // }
     // vector<int>res(n,0);

     // for(int i=0;i<n;i++){
     //     string temp="";
     //     int ans=0;
     //     for(auto it:words[i]){
     //         temp+=it;
     //         if(mpp.count(temp)){
     //             ans+=mpp[temp];
     //         }
     //     }
     //     res[i]=ans;
     // }
     // return res;                                                                                                

 //! Optimal
 class Trie
{
public:
    struct TrieNode
    {
        TrieNode *children[26];
        bool isEndOfWord;
        int prefixcnt;
    };
    // function to create new Node
    TrieNode *getTrieNode()
    {
        TrieNode *newNode = new TrieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    TrieNode *root;

    Trie()
    {
        root = getTrieNode();
    }

    void insert(string word)
    {
        TrieNode *crawler = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
            {
                crawler->children[idx] = getTrieNode();
            }
            crawler = crawler->children[idx];
            crawler->prefixcnt++;
        }
        crawler->isEndOfWord = true; // reached end of the word
    }

    int prefixScore(string prefix)
    {
        TrieNode *crawler = root;
        int cnt = 0;
        int i;
        for (i = 0; i < prefix.size(); i++)
        {
            char ch = prefix[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
            {
                break;
            }
            crawler = crawler->children[idx];
            cnt += crawler->prefixcnt;
        }
        return cnt;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();
        Trie trie;
        for (int i = 0; i < n; i++)
        {
            trie.insert(words[i]);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = trie.prefixScore(words[i]);
        }

        return ans;
    }
};