//! Binary Subarrays With Sum

// ^ CONCEPT  Subarray Sum Equals K
// unordered_map<int,int>mpp;
//        int n=nums.size(),ans=0,sum=0;
//        mpp[0]=1;
//        for(auto it:nums){
//         sum+=it;
//         if(mpp.find(sum-k)!=mpp.end()){ 
//~ we are cummulating sum so if we found (sum-goal) in past then there is subarray with (sum==goal)
//~ and no of times the (sum-goal) is seen in past add this to your ans
//             ans+=mpp[sum-k];
//         }
//         mpp[sum]++;
//        }
//     return ans;
   
//! Brute using o(n^2)
//!  APPROACH 1: CUMMILATIVE SUM

    //    int n=nums.size(),ans=0,sum=0;
    //    unordered_map<int,int>mpp;
    //    mpp[0]=1; //~ if whole array sum ==k for that case;
    //    for(auto it:nums){
    //      sum+=it;
    //      if(mpp.find(sum-goal)!=mpp.end()){
    //         ans+=mpp[sum-goal];
    //      }
    //      mpp[sum]++;
    //    }
    //    return ans;

//! :  Normal SLIDING WINDOW (Issue in this code)

    int l=0,r=0,n=nums.size(),ans=0,sum=0;
     while(r<n){
        sum+=nums[r];
        while(l<=r && sum>goal){
            sum-=nums[l];
            l++;
        }
        if(sum==goal)ans++;
        r++;
   }
   return ans;
 // suppose nums=[1,0,1,0,1], goal = 2
          l,r
         [ 1,  0,  1,  0,  1]   sum=0,ans=0

           l   r
         [ 1,  0,  1,  0,  1]   sum=1,ans=0

           l       r
         [ 1,  0,  1,  0,  1]   sum=2 ans=1

           l           r
         [ 1,  0,  1,  0,  1]   sum=2 ans=2

           l               r                                
         [ 1,  0,  1,  0,  1]   sum=3 ans=2   

               l              r
         [ 1,  0,  1,  0,  1]   sum=3 ans=2     // yaha r out of bound chala gaya but ek or subarray hai soans is incorrect

//~ hm yaha valid window milte hi window expand kr rhe h balki hme shrink krke or subarray dekhne chahie
// As we shrink window when sum<=goal
// and we expand window when sum>=goal
//^ so overlapp kr rhe h valid invalid case

// we find the cnt of 0's in prefix
// To solve this issue --> when [ window sum>goal  || nums[l]==0 ] shrink the window

// int l=0,r=0,n=nums.size(),ans=0,sum=0,prefix_zeroes=0;

//      while(r<n){
//         sum+=nums[r];
//         while(l<r && nums[l]==0 || sum>goal){
//             if(nums[l]==0){
//                 prefix_zeroes++;
//             }
//             else{
//                 prefix_zeroes=0;
//             }
//             sum-=nums[l];
//             l++;
//         }
//         if(sum==goal) {
//             ans+= 1+prefix_zeroes;
//         }
//         r++;
//    }
//    return ans;

//^ Most efficient way
int subarrays_sum_atmostgoal(vector<int>& nums, int goal){
    int l=0,r=0,n=nums.size(),cnt=0,sum=0;
    while(r<n){
        sum+=nums[r];   //expand
        while(l<=r && sum>goal){ //shrink
            sum-=nums[l];
            l++;
        }
        cnt+=r-l+1;//no of subarrays bet l & r
        r++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
// We find no of subarrays with at most goal and subtracting it from (goal-1)
return subarrays_sum_atmostgoal(nums,goal)-subarrays_sum_atmostgoal(nums,goal-1);   
    }

//! same question but language diffnt

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

int subbarrays_with_k_odd(vector<int>& nums, int k){
    int l=0,r=0,n=nums.size(),ans=0,cnt=0;//cnt=no of odd elements
    while(r<n){
        if(nums[r]%2)cnt++;
        while(l<=r && cnt>k){
            if(nums[l]%2)cnt--;
            l++;
        }
        ans +=r-l+1;
        r++;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
      // subarrays witk atmost k - subarrays witk atmost k-1 odd nos;
      return subbarrays_with_k_odd(nums,k)-subbarrays_with_k_odd(nums,k-1);
    }

//! Subarrays with K Different Integers -->can also done with this technique;
// shrinkable window
    int calc(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0,ans=0;
        unordered_map<int,int>mpp;

        while(r<n){
            mpp[nums[r]]++;
            while(l<=r && mpp.size()>k){
               mpp[nums[l]]--;
               if(mpp[nums[l]]==0)mpp.erase(nums[l]);
               l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums,k)-calc(nums,k-1);
    }
