 //! BRUTE FORCE (STL)
 next_permutation(nums.begin(),nums.end());


//! OPTIMAL 
void nextPermutation(vector<int>& nums) {

// traverse from back & where nums[i]>nums[i-1] the idx1=i-1;
// again from back find where nums[i]>nums[idx] then swap(nums[idx],nums[idx2]);
// at last reverse arr from idx+1 to end;

    int idx1=-1,idx2=-1,n=nums.size();
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            idx1=i-1;
            break;
        }
    }
     if(idx1!=-1){
     for(int i=n-1;i>=0;i--){
        if(nums[i]>nums[idx1]){
            swap(nums[i],nums[idx1]);
            break;
        }
      }
     }
     reverse(nums.begin()+idx1+1,nums.end());
    }