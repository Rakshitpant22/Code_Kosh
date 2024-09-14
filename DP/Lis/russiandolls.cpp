//!vvvIMP

class Solution {
public:
// ye function islea ki taki kahi esa given array ho :(2,3),(4,5),(4,6);
//! to is case me sorting ese define krvadi

static bool comp(vector<int> &a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    else{
        return a[0]<b[0];
    }
}

//!and baaki k lie question me condition hai for [(a,b),(c,d)]---> a<c and b<d
CATCH:
//! sorting ki vjeh se a<c(pehle solve hogyi) for rest check conditions by for loop 

    int maxEnvelopes(vector<vector<int>>& nums) {
         int n= nums.size();
         sort(nums.begin(),nums.end(),comp);
         vector<int>ans;
         ans.push_back(nums[0][1]);

          for(int i=1;i<n;i++){
              if(nums[i][1]>ans.back()){
                  ans.push_back(nums[i][1]);
              }
              else{
                  auto index= lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin();
                  ans[index]= nums[i][1];
              }
          }
          return ans.size();

    }
};