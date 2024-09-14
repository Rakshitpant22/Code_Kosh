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