//! optimal
//i for 0 , j=1 and k=2;

void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                j++;i++;
            }
            else if(nums[j]==2){
                swap(nums[k],nums[j]);
                k--;
            }
            else{
                j++;
            }
        }
    }