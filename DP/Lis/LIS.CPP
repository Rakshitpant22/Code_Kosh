// Recursion  TC= 2^n  and SC = 0(n) auxilliary stack space
class Solution
{
private:
    int f(int ind, int prev, vector<int> &nums, int n){
        if (ind == n)
            return 0; // base case

        int length = 0 + f(ind + 1, prev, nums, n); // not take
        if (prev == -1 || nums[ind] > nums[prev])
            length = max(length, 1 + f(ind + 1, ind, nums, n)); // take
        return length;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return f(0, -1, nums, n);
    }
};


//! BINARY SEARCH

nt lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<int>temp;

           for(auto it: nums){
               if(temp.empty() || it> temp[temp.size()-1]){
                   temp.push_back(it);
               }
           
           else{
               auto index= lower_bound(temp.begin(),temp.end(),it);
               *index= it; // or temp[index]=it;
           }
       }
       return temp.size();
    }
//! no of longest increasing 
 int n= nums.size();
        vector<int>dp(n,1),count(n,1);
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(nums[i]>nums[j]){
                   if(dp[j]+1==dp[i]){
                       count[i]+=count[j];
                   }
                   else if(dp[j]+1>dp[i]){
                       dp[i]=1+dp[j];
                       count[i]=count[j];
                   }
               } 
           }
       }
       int maxi=*max_element(dp.begin(),dp.end());
       int res=0;
       for(int i=0;i<n;i++){
           if(dp[i]==maxi){
               res+=count[i];
           }
       }
       return res;
    

    
    //! Maximum sum increasing LIS public : int maxSumIS(int arr[], int n)
{
    int maxsum[n];
    for (int i = 0; i < n; i++)
    {
        maxsum[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && maxsum[i] < maxsum[j] + arr[i])
                maxsum[i] = maxsum[j] + arr[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, maxsum[i]);
    }
    return ans;
}