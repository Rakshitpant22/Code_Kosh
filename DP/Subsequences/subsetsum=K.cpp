class Solution {

    private:
    bool subsetSumToK( int k, vector<int> &arr) {
        int n=arr.size();int totalsum= 0;
        for(int i=0;i<n;i++)totalsum+=arr[i];
    vector<vector<bool>>dp(201,vector<bool>(totalsum+1,0));
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
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum= 0;
        for(int i=0;i<n;i++)totalsum+=nums[i];
        if(totalsum%2!=0)return false;
        int target=totalsum/2;
         return subsetSumToK(target,nums);
    }
};