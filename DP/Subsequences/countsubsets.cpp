
//! count no of subsets with the given target...

// MEMOIZATION   
TC= O(N*K) SC=O(N*K)+O(N)  
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)  return 1;
    
    if(ind == 0)   return arr[0] == target;
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}
//! TABULATION

TC= O(N*K) SC= O(N*K)

int findWays(vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
        if(arr[0]<=k)dp[0][arr[0]]=1;

	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
	int notTaken = dp[ind-1][target];
    int taken = 0;
    if(arr[ind]<=target)
    taken = dp[ind-1][target-arr[ind]];
        
    dp[ind][target]= notTaken + taken;
		}
	}
      return dp[n-1][k];
}
