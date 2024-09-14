PROBLEM:
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


class Solution {
     private:
    int f(int ind1,int ind2,string &text1, string &text2){
       if(ind1<0||ind2<0)return 0;

//  MATCHING CASE
       if(text1[ind1]==text2[ind2])         
       return 1 + f(ind1-1,ind2-1,text1,text2);

// NON MATCHING CASE
       return max(f(ind1-1,ind2,text1,text2),f(ind1,ind2-1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m= text2.size();
        int n= text1.size();
        return f(n-1,m-1,text1,text2);
    }
};

//! Tabulation 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

         if(text1[i-1]==text2[j-1])     dp[i][j] =  1 + dp[i-1][j-1];
         

       else    dp[i][j]= max (dp[i-1][j], dp[i][j-1]);

            }
        }
        return dp[n][m];
        
    }
};

//! SPACE OPTIMISED
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<int>prev(m+1,0), curr(m+1,0);
       
        for(int j=0;j<=m;j++)prev[j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

         if(text1[i-1]==text2[j-1])     curr[j] =  1 + prev[j-1];
         

          else    curr[j]= max (prev[j], curr[j-1]);

            }
            prev=curr;
        }
        return prev[m];
        
    }
};

//! FOR LONGEST COMMON SUBSTRING :  
//^ the change is in the non matching condition where in subsequence we do swiching 1by1 on [i-1][j] /[i][j-1] here we cant do
//^ bcs the longest common SUBSTRING is req so its must be lagataar..


class Solution {

    private:
    string reverseStr(string& s)
      {
     int p = s.length();

    for (int i = 0; i < p/ 2; i++)
        swap(s[i], s[p - i - 1]);
        return s;
     }
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
       string s2= reverseStr(s);


        int n= s1.size();
        int m= s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

         if(s1[i-1]==s2[j-1])     dp[i][j] =  1 + dp[i-1][j-1];
         
          else    dp[i][j]= max (dp[i-1][j], dp[i][j-1]);
          ans= max(ans,dp[i][j]);

            }
        }
       
        return ans;
    }
};