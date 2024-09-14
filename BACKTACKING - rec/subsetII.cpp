//! concept same as combination sum -II
class Solution {
    private:
     void rec(int index,vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){

             ans.push_back(ds);
        
         for(int i=index; i<nums.size();i++){
            if(index<i && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            rec(i+1,nums,ds,ans);
            ds.pop_back();
         }
     }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        rec(0,nums,ds,ans);
        return ans;
    }
};