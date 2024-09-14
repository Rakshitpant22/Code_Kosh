Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


// if starting from end ex f(n-1,m-1) represents that steps req to convert string1 to string2.
   i,j = s1 index , s2index   respectively

//! Matching case
 if the s1==s2 -->means no steps is required kyuki pehle se hi equal hai, s1,s2 ko age bdha do
    if(s1[i]==s2[j])return 0+f(i-1,j-1)

//! No matching case

//^ case 1 = insert 
   ex s1=horse  and s2=ros we hypothetically insert 's' in s1 so matching case bngya to [j] reduce hoga not [i] bcs 
   we hypothetically insert in s1;
   so insert = 1+ f(i,j-1);

//^ case2= delete 
   ex  s1=horse s2=ros  --> delete 'e'in s1 the matching happens so here i reduces so 1+ f(i-1,j);

//^ case 3 =replace  
      1+f(i-1,j-1);

    //! for minimum steps we do min of 3 cases

//!  BASE CASES


//^ If s1 got exausted----> return j+1;
  explanation -- s1= horse
                 s2= ros

        suppose function call is f(-1,1)--->means s1 ko -1 (mtlb empty string)se s2 banane k min operations kitne honge;;
        to it is j+1;  (The  whole s2 upto j);;

//^ If s2 got exausted----> return i+1;


RECURSION:
class Solution {
    int f(int i,int j,string s1, string s2){
      //BASE CASES  
      if(i<0)return j+1;
        if(j<0)return i+1;

    //MATCH 
        if(s1[i]==s2[j])return f(i-1,j-1,s1,s2);
    
    // IF NOT MATCH RETURN MIN OF 3 OPERATIONS..
        
         return  1+ min(f(i-1,j-1,s1,s2), min(f(i-1,j,s1,s2),f(i,j-1,s1,s2)));

    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(n-1,m-1,word1,word2);
    }
};
 
 // TABULATION
  class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
         for(int i=0;i<=n;i++)dp[i][0]= i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
               
                 if(word1[i-1]==word2[j-1]) dp[i][j]= dp[i-1][j-1];

                 else
                  dp[i][j]= 1+ min (dp[i-1][j-1] ,min(dp[i-1][j],dp[i][j-1]));
                 
             }
         }
         return dp[n][m];
    }
};