Single Element in a Sorted Array
https://leetcode.com/problems/single-element-in-a-sorted-array/description/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.

//! Approach : tc=O(log n)

int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
    // base cases hard coded
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];

//kisi bhi array m agr except 1 all elements are appearing 
// agr (even,odd) ke combination pe same element hue to unique element right side m milega else left side array ke
       
       int low=0,high=n-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]!=nums[mid-1] &&nums[mid]!=nums[mid+1])return nums[mid];

        //if (even,odd)have same then go to right side
        if(mid%2==0 && nums[mid]==nums[mid+1]||
           mid%2==1 && nums[mid]==nums[mid-1]){
                low=mid+1;
           }

        else{
            high=mid-1;
         }
       }
       return -1;
    }
