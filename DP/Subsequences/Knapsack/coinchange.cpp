//!RECURSION:dp
recursion TC= >>>O(2^n) SC= >>> O(N)
class Solution {
    private:
    int f(int ind,int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(ind==0){
            if(amount % coins[0]==0)return amount/coins[0];
            else return 1e9;
        }
       if(dp[ind][amount]!=-1)return dp[ind][amount];
        int notpick= 0+f(ind-1,amount,coins,dp);
        int pick= 1e9;
        if(amount>= coins[ind]) pick=1+f(ind,amount-coins[ind],coins,dp);
         return dp[ind][amount]= min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans =  f(n-1,amount,coins,dp);

       if(ans>=1e9)return -1;   // if no coins can be taken by 0 th index;
       return ans;
    }
};


//tabulation  TC= O(N*amount) SC=O(N*amount)    while in memoization sc =O(N)+sc(tabulation) and tc= same as tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)dp[0][target]= target/coins[0];
            else dp[0][target]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notpick=0+dp[ind-1][target];
                int pick= 1e9;
                if(coins[ind]<= target)pick=1+dp[ind][target-coins[ind]];

                dp[ind][target]= min(pick,notpick) ;
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};  
//! Spa
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0) , curr(amount+1,0) ;
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)prev[target]= target/coins[0];
            else prev[target]=1e9;
        }
       for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notpick=0 + prev[target];
                int pick= 1e9;
                if(coins[ind]<= target)pick=1+curr[target-coins[ind]];

                curr[target]= min(pick,notpick) ;
            }
            prev=curr;
       }
        int ans=prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};  


// ^ IF PROBLEM STATES THAT GIVE THE TOTAL SUBSEQUENCES FROM COINS THAT WILL MAKE UP TO THE GIVEN AMOUNT :
//! here we will return 1 /0 as in counting we return 1/0;

class Solution {
    private:
    int f(int ind,int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(ind==0){
            if(amount % coins[0]==0)return 1;
            else return 0;
        }
       if(dp[ind][amount]!=-1)return dp[ind][amount];
        int notpick= f(ind-1,amount,coins,dp);
        int pick= 0;
        if(amount>= coins[ind])pick=f(ind,amount-coins[ind],coins,dp);
         return dp[ind][amount]= pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};


//! tabulation
class Solution {
   
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
         for(int target=0;target<=amount;target++){
             if(target % coins[0]==0) dp[0][target]= 1;
             else dp[0][target]=0;
         }

             for(int ind=1;ind<n;ind++){
                 for(int target=0;target<=amount;target++){
                     int notpick= dp[ind-1][target];
                     int pick=0;
                     if(target>=coins[ind])
                     pick = dp[ind][target-coins[ind]];
                    dp[ind][target]= pick + notpick;
                 }
             }
        return  dp[n-1][amount];
         
    }
};