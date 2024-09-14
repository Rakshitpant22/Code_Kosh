//! PROBLEM
Given a set of non-negative integers and a value sum, the task is to check if there is a subset of the given 
set whose sum is equal to the given target=K. 


//! recursion

#include <bits/stdc++.h>
bool f(int ind, int k, vector<int> &arr) {
           if(ind == 0){  // base case= agr hum 0th index p pohch gye to..
            if(k==0 && arr[0]==0) return 2; // agr arr m 0's bhi present hai or target 0 chahie to y possible hai ki uska subset bhi bne
            if(k==0 || k == arr[0]) return 1; 
            return 0;
    }

  bool notpick = f(ind - 1,  k, arr);
  bool pick = false ;
  if(k>=arr[ind])
  pick = f(ind - 1,  k - arr[ind], arr);
  return pick | notpick;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}

//! memoization
#include <bits/stdc++.h>
bool f(int ind, int k, vector<int> &arr, vector<vector<int>>&dp) {
  if (k == 0)return true;
  if (ind == 0)return (arr[0] == k);
   
   if(dp[ind][k]!=-1)return dp[ind][k];
  bool notpick = f(ind - 1,  k, arr,dp);
  bool pick = false ;
  if(k>=arr[ind])
  pick = f(ind - 1,  k - arr[ind], arr,dp);
  return dp[ind][k]= pick | notpick;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
//! Tabulation 
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notpick = dp[ind - 1][target];
        bool pick = false ;
  if(target>=arr[ind]) pick = dp[ind - 1][target - arr[ind]];
   dp[ind][target]= pick | notpick;

        }
    }
    return dp[n-1][k];
}