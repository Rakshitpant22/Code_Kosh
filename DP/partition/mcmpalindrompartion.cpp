// RECURSION CODE
 TC= exponential 
class Solution {
    bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int f(int i,string s){
         int n= s.size();

   if(i==n)return 0;

   int mincuts=1e9;
   for(int j=i;j<n;j++){
    if(isPalindrome(i,j,s)){
        int cost= 1+f(j+1,s);
    mincuts=min(mincuts,cost);
    }
   }
   return mincuts;
}
public:
    int minCut(string s) {
        
        int n= s.size();
        return f(0,s) -1;
    }
};

// Tabulation
   TC=O(n*n) SC=O(n)
  int minCut(string s) {
        int n= s.size();
        vector<int>dp(n+1,0);
     for(int i=n-1;i>=0;i--){
      int mincuts=1e9;
      for(int j=i;j<n;j++){
          if(isPalindrome(i,j,s)){

         int cost=1+dp[j+1];
          mincuts=min(mincuts,cost);

      }
      dp[i]=mincuts;
  }
         
    }
      return dp[0]-1;
    }