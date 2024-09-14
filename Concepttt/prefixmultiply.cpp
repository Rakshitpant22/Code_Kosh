//Given an integer array nums, return an array answer such that answer[i] 
//is equal to the product of all the elements of nums except nums[i].
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

TC= 3*O(n) SC= 2*O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n= nums.size();
      vector<int>prefix;
      int product=1;
      prefix.push_back(product);

      for(int i=0;i<n-1;i++){
          product*=nums[i];
          prefix.push_back(product);
      }
  
      vector<int>suffix;
      int pr=1;
      suffix.push_back(pr);
      for(int i=n-2;i>=0;i--){
          pr*= nums[i+1];
          suffix.push_back(pr);
      }
       reverse(suffix.begin(),suffix.end());
     
       for(int i=0;i<n;i++){
           nums[i]=suffix[i]*prefix[i];
       }
       return nums;
    }
};