// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

typedef long long ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int startinindex=-1,n=nums.size();
       int mini_idx=-1;
       int maxi_idx=-1;
       ll ans=0;

       for(int i=0;i<n;i++){
        if(nums[i]>maxK || nums[i]<minK){
            startinindex=i; //isse pehle vala valid hi ni hoga to ye naya starting pt hai
        }
        if(nums[i]==minK)mini_idx=i;
        if(nums[i]==maxK)maxi_idx=i;

        ans+= (ll)max(0,min(mini_idx,maxi_idx)-startinindex);
       }
       
       return ans;
    }