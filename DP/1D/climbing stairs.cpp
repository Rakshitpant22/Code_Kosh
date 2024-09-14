 Solution {
public:
    int climbStairs(int n) {
   // memoiazation
     vector<int>dp(n+1); //since at start from 0 to nth (kyuki 0 se 1 bhi ja stke hai)
       if(n<=2)return n;
       dp[0]=0;
       dp[1]=1;
       dp[2]=2;
       for(int i= 3;i<=n;i++){
       dp[i]= dp[i-1]+dp[i-2];
       }
       return dp[n];


// 
       vector<int>dp(n+1); //since at start from 0 to nth 
    
       int prev1= 1;
      int  prev2= 0;
       for(int i= 1;i<=n;i++){
       int curri = prev1+prev2;
       prev2=prev1;
       prev1=curri;
      
       }
       return prev1;
    }
};