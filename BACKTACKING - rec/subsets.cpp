class Solution {
   void subs(int index,vector<int>& arr,vector<vector<int>>&ans,vector<int>&ds ){
        if(index == arr.size()){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(arr[index]);
        subs(index+1,arr,ans,ds);
        ds.pop_back() ;
        subs(index+1,arr,ans,ds);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        subs(0,nums,ans,ds);
        return ans;
    }
};
