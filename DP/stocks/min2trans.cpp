 //  Recursion
 
 int f(int ind,int buy ,int cap,vector<int>& a){
         int n= a.size(); 
        //base case 
        if(cap==0|| ind==n)return 0;
       
        int profit =0;
        if(buy==1){
        profit=max(-a[ind]+f(ind+1,0,cap,a),
                         0+ f(ind+1,1,cap,a));
        }
        else{
          profit=max(a[ind]+f(ind+1,1,cap-1,a),
                         0+ f(ind+1,0,cap,a));
        }
         return profit;
    }
public:
    int maxProfit(vector<int>& a) {

        int n= a.size(); 
        return f(0,1,2,a);
    }


// memoised
class Solution {
    int f(int ind,int buy ,int cap,vector<int>& a, vector<vector<vector<int>>>&dp){
         int n= a.size(); 
        //base case 
        if(cap==0|| ind==n)return 0;
       
        int profit =0;

        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy==1){
     profit= max(-a[ind]+f(ind+1,0,cap,a,dp),
                         0+ f(ind+1,1,cap,a,dp));
        }
        else{
          profit=max(a[ind]+f(ind+1,1,cap-1,a,dp),
                         0+ f(ind+1,0,cap,a,dp));
        }
         return dp[ind][buy][cap]= profit;
    }
public:
    int maxProfit(vector<int>& a) {
        int n= a.size(); 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))); //! 3D DP MEMOIZATION
        return f(0,1,2,a,dp);
    }
};
//! Tabulation 
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n= a.size(); 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       
         for(int ind=n-1;ind>=0;ind--){
             for(int buy=0;buy<=1;buy++){
                 for(int cap=1;cap<=2; cap++){

                     if(buy==1){
                    dp[ind][buy][cap]= max(-a[ind]+dp[ind+1][0][cap],
                                  0+ dp[ind+1][1][cap]);
                     }
                     else{
                      dp[ind][buy][cap]=max(a[ind]+dp[ind+1][1][cap-1],
                                     0+ dp[ind+1][0][cap]);
                     }
                 }
             }
         }
         return dp[0][1][2];
    }
};