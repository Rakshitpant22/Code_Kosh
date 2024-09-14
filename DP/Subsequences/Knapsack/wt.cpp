//! if given  wieghts vector,its value, and W the max weight of the bag

//^ TC= O(2^N) SC= O(N)
int f(int ind,vector<int>&weight, vector<int>&value, int W){
	if(ind==0)
	{
		if(weight[0]<=W)return value[0];
		return 0;
	}
	int nottake = 0+ f(ind-1,weight,value,W);
	int take=-1e9;
	if(weight[ind]<=W) take = value[ind]+f(ind-1,weight,value, W-weight[ind]);
	return max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value,  int W) 
{
	return f(n-1,weight,value,W);
}

//!  Memoization   TC=O(N*W) SC=O(N*W)+O(N)

int f(int ind,vector<int>&weight, vector<int>&value,  int W,vector<vector<int>>&dp){
	if(ind==0)
	{
		if(weight[0]<=W)return value[0];
		return 0;
	}
    if(dp[ind][W]!=-1)return dp[ind][W];
	int nottake = 0+ f(ind-1,weight,value,W,dp);
	int take=-1e9;
	if(weight[ind]<=W) take = value[ind]+f(ind-1,weight,value,W-weight[ind],dp);
	return dp[ind][W]= max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
     vector<vector<int>>dp(n,vector<int>(W+1,-1));
	return f(n-1,weight,value,W,dp);

}
//! Tabulation
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
     vector<vector<int>>dp(n,vector<int>(W+1,0));
	for(int i=weight[0]; i<=W; i++){
        dp[0][i] = value[0];
    }
	 for (int ind=1;ind<n;ind++){
		 for(int wt=0;wt<=W;wt++){
			 int nottake = 0+ dp[ind-1][wt];
	int take=-1e9;
	if(weight[ind]<=wt)
	 take = value[ind]+dp[ind-1][wt-weight[ind]];
       dp[ind][wt]= max(take,nottake);
	  
		 }
	 }
	 return dp[n-1][W];
}
