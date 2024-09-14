//! APPROACH 1:
//^ extra size ka mp le rhe h jo decide kr rha h ki jo (index = 1) mark nhi h us recursive call klie usse le slte h 
//^ this takes extra space of that map structure used so TC increases//

class Solution {
    private:
    void perm(vector<int>& arr,int mp[], vector<int>&ds, vector<vector<int>>&ans){
                    if(ds.size()==arr.size()){
                        ans.push_back(ds);
                        return;
                    }
                    for(int i=0;i<arr.size();i++){
                      if(!mp[i]){
                        ds.push_back(arr[i]); 
                        mp[i]=1;
                        perm(arr,mp,ds,ans);
                        ds.pop_back(); 
                        mp[i]=0;
                    }
                }
          }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
      int mp[nums.size()];
        for(int i=0;i<nums.size();i++){
            mp[i]=0;
        }
        set<vector<vector<int>>>sp;
        perm(nums,mp,ds,ans);
        return ans;
    }
};
//!APPROACH 2:
//^ Swapping elements:
class Solution {
    void perm(int index,vector<int>& arr,vector<vector<int>>&ans){
      
      if(index==arr.size()){
          ans.push_back(arr);
          return;
      }
      for(int i=index;i<arr.size();i++){
          swap(arr[index],arr[i]);
          perm(index+1,arr,ans);
          swap(arr[index],arr[i]);
      }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>>ans;
        perm(0,nums,ans);
        return ans;
    }
};

//! IF DUPLICACY NOT ALLOWED IR ARR[1 1 2 3] ABOVE CODE IS NOT SUFFICIENT FOR THAT :

//^ USE SET  --> It will increase time complexity as we are suing extra data structur set;
class Solution {
    private:
    void perm(int index,vector<int>& arr,set<vector<int>>&ans){
      
      if(index==arr.size()){
          ans.insert(arr);
          return;
      }
      for(int i=index;i<arr.size();i++){
          if(i>index && arr[i]==arr[index])continue;
          swap(arr[index],arr[i]);
          perm(index+1,arr,ans);
           swap(arr[index],arr[i]);
      }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         set<vector<int>>ans;
          vector<vector<int>> vec;
        perm(0,nums,ans);


        for(auto it: ans){
            vec.emplace_back(it);
        }
        return vec;
    }
};