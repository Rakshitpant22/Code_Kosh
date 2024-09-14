Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence 
(i.e. subarray). The subsequence must be strictly increasing.

Example:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element 4.

//! APPROACH 1:
class Solution {
    int f(int i,int prev,vector<int>& nums,int n, vector<vector<int>>&dp){
        if(i==n)return 0;
   if(dp[i][prev+1]!= -1)return dp[i][prev+1];
        int len= 0 + f(i+1,prev,nums,n,dp);

        if(prev==-1 || nums[i]>nums[prev]&& i-prev==1)
        len= max(len, 1+f(i+1,i,nums,n,dp));
        return dp[i][prev+1]=len;
    }
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};

//! Approach 2 : 

int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==0)return nums[0];
        vector<int>dp(n,1);
  
  int maxi=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && i-j==1){
                    dp[i]=max(dp[i],dp[j]+1);
                }

              maxi= max(maxi,dp[i]);
            }
        }
        return maxi;
    }
// ! Approach 3----> greedy; KADANE'S TYPE:
        int n=nums.size();
        int cnt=1;int ans=0;
       for(int i=1;i<n;i++){
           if(nums[i]>nums[i-1]){
               cnt++;
           }
           else{
               ans= max(cnt,ans);
               cnt=1;
           }
       }
       return max(ans,cnt);
    