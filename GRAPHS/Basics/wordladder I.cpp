class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue<pair<string,int>>q;
       q.push({beginWord,1});
       unordered_set<string>s(wordList.begin(),wordList.end()); // taki hum baad m delete kr pae to prevent duplicacy
       s.erase(beginWord);       
       

       while(!q.empty()){
           string word= q.front().first;
           int steps= q.front().second;
           q.pop();
          if(word == endWord)return steps; 
          // Kyuki sare char k lie traverse kr rhe hai:
          for(int i=0;i<word.size();i++){
              char original = word[i];
              
              for(char ch = 'a'; ch<='z' ;ch++ ){
                  word[i]=ch;
                  if(s.find(word)!= s.end()){// if exists in the set
                      s.erase(word);
                      q.push({word,steps+1});
                  }
              }
              word[i] = original;  // taki second letter k lie vohi word dubara ajaee.
          }
       }
       return 0;
    }
};