 //! FIND MIN ELEMENT IN ROTATED SORTED ARRAY 
 int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;

        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){// mid can also not be min
                low=mid+1;
            }
            // as mid is less than high so mid can be min element also
            else{
                high=mid;
            }
        }
        return nums[low];
 }
//~ jaha p min element milga utni baar sorted array right times rotate hua haa



//! FIND PEAK ELEMENT 
// arr[-1]= -inf && arr[n]= -inf 
int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;

        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
            else if(nums[low]<=nums[mid] && nums[mid]<=nums[mid+1]){//means if mid>low and mid+1>=mid so its incesing part only shrink search space to low+1
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }