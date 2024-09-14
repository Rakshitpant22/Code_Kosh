// ! recursive
class Solution {
public:
int f(int ind,vector<int>& nums){
    if(ind==0)return nums[ind];
    if(ind<0) return 0;

    int pick= nums[ind] +f(ind-2,nums);
    int notpick= 0+ f(ind-1,nums);
    return max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,nums);
    }
};
//! MEMOIZATION
int f(int ind,vector<int>& nums,vector<int>&dp){
    if(dp[ind]!=-1) return dp[ind];
    if(ind==0)return nums[ind];
    if(ind<0) return 0;
    
    int pick= nums[ind] +f(ind-2,nums,dp);
    int notpick= 0 + f(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }

//! TABULATION
 class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
    
       dp[0]=nums[0];
       for(int i=1;i<n;i++){
           int take= nums[i];
           if(i>1) take+=dp[i-2];
           int nottake= 0+dp[i-1];
           dp[i]=max(take,nottake);
       }
        
   return dp[n-1];
    }
};

//! SPACE OPTIMISED

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
       
    for(int i=1;i<n;i++){
           int take= nums[i];
           if(i>1) take+=prev2;
           int nottake= 0+prev1;
           int curri= max(take,nottake);
           prev2=prev1;
           prev1=curri;
       }
       return prev1;
    }
};