// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]

int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=0,ans=0,cnt=0;
        while(r<n){
            if(nums[r]==0)cnt++;
            while(l<=r && cnt>k){
                if(nums[l]==0)cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }