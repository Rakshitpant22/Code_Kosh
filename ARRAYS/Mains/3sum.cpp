// BRUTE 
tc= o(n^3* log(no of triplets))
sc= 2(o(n))
set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp= {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                    }
                }
            }
        }
         vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    

// OPTIMAL APPROACH ---  2 POINTERS

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
        int n= nums.size();
        int sum;
         int j,k;
        for(int i=0;i<n;i++){
            
          if(i>0 && nums[i]==nums[i-1])continue;
          j=i+1;
          k= n-1;
          while(j<k){
              sum= nums[i]+ nums[j] + nums[k];
              if(sum<0){
                  j=j+1;
              }
              else if(sum>0){
                  k=k-1;
              }
              else{
                  vector<int>temp= {nums[i],nums[j],nums[k]};
                  ans.push_back(temp);
                  j++;
                  k--;
                  while(j<k && nums[j]==nums[j-1])j++;
                  while(j<k && nums[k]==nums[k+1])k--;
              }
          }
        }
   return ans;
    }

