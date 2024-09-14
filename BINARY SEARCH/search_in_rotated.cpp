//! basic binary search
int search(vector<int>& nums, int target) {
      
        int low = 0;
        int  high = n-1;
        while( low <= high){
            int mid = low + (high-low)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        return -1;
  }

   
 Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

// here k= target

 int search(vector<int>& arr, int k) {
        int n=arr.size();
           int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;
    
    // TODO : for the dupicate values
       if(arr[mid]==arr[low] && arr[mid]==arr[high]){
           low++;mid--;
           continue;
        } 
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
    }