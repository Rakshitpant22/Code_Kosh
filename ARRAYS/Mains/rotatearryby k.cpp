 //  ! REVERSE BY K PLACES 

 void reverse(int start,int end,vector<int>& nums){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k%=n;
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);
    }


QUES 2:
//! first element ko last bnana ha basically 
ex[1,2,3,4,5]----> output: [2,3,4,5,1]

vector<int> rotateArray(vector<int>& nums, int n) {
    int start= nums[0];
    for(int i=0;i<n-1;i++){
        nums[i]=nums[i+1];
    }
    nums[n-1]=start;

    return nums;

   
}