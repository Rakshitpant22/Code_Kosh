class Solution {
    int f(int i,vector<int>& nums, int k,int n){
         if(i==n)return 0;
         
         int len=0;
         int maxi=-1e9;
         int ans=-1e9;
         for(int j=i;j<min(k+i,n);j++){
             len++;
             maxi=max(maxi,nums[j]);
             int sum= len*maxi + f(j+1,nums,k,n);

             ans=max(ans,sum);
         }
         return dp[i]= ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        return f(0,nums,k,n);
    }
};