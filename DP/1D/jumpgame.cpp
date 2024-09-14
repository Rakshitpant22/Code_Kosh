//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the
//array represents your maximum jump length at that position. Return min steps to reach end position;
intf(int i,vectot<int>&nums,int n){
        if(i==n-1)return true;

        int jump= i + nums[i];
       int mini= 1e9;
        for(int j=i+1;j<=min(n,jump);j++){
        int ans= 1+f(j,nums,n);  //steps

         mini= min(mini,ans);
        }
      
        return mini;;
    }
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        return f(0,nums,n);
    }