//! CNT SUBARRAYS WITH SUM == K
int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       int n=nums.size(),ans=0,sum=0;
       mpp[0]=1;
       for(auto it:nums){
        sum+=it;
        if(mpp.find(sum-k)!=mpp.end()){ 
        // we are cummulating sum so if we found sum so if we found sum-goal in past then there is subarray with sum==k
            ans+=mpp[sum-k];
        }
        mpp[sum]++;
       }
     return ans;
    }


//! LONGEST SUBARRAY WITH SUM == K
Given an array arr containing n integers and an integer k. 
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.
array contains positive + negagtive integers

// APPROACH 1: brute 
        int ans=0;
      for(int i=0;i<n;i++){
          int sum=0;
          for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                ans=max(ans,j-i+1);
            }
          }
      }
      return ans;

//! OPTIMAL - IF ARRAY CONTAINS (POSITIVES + NEGATIVES BOTH)
//~ Searching in the map: Inside the loop, the mpp.find(sum - k) operation takes O(log n) time on average
/// TC=O(n logn)
int longestSubarrayWithSumK(vector<int> nums, long long k) {
      unordered_map<int,int>mpp;
      int ans=0;
      long long sum=0;
      mpp[0]= -1;
      
      for(int i=0;i<nums.size();i++){
         sum+= (long long)nums[i];
      
         if(mpp.find(sum-k) != mpp.end()){
             ans=max(ans,i-mpp[sum-k]);
         }
         if(mpp.find(sum) == mpp.end()){ //as we want longest so store only 1st occourence of sum only
           mpp[sum] = i;
         }
      }
      return ans;
}


//! OPTIMAL - IF CONTAINS ONLY POSITVES AND ZEROES --> (sliding window)
// TC - O(n)
/int longestSubarrayWithSumK(vector<int> nums, long long k) {
    int n=nums.size();
    long long sum=0;
    int i=0,j=0,ans=0;
   
    while(j<n){
      sum+=(long long)nums[j];
      while(i<=j && sum>k){
        sum-=(long long) nums[i];
        i++;
      }
      if(sum==k){
        ans=max(ans,j-i+1);
      }
      j++;
    }
    return ans;
}


