// Input: nums = [9,4,7,2,10]
// Output: 3
// Explanation:  The longest arithmetic subsequence is [4,7,10].

int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    int res=0;
    vector<vector<int>>dp(n,vector<int>(1001,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
    // max negative value can be 0-500 to make it + add 500 
    // max value can be diff= 500-0 and + 500 == 1000 
        int diff=(nums[i]-nums[j]+500);//sice difference can be negative to making positive
        if(dp[j][diff]>0){
            dp[i][diff]=1+dp[j][diff];
        }
        else {
           dp[i][diff]=2;
        }
        res=max(res,dp[i][diff]);
            }
        }
        return res;
    }