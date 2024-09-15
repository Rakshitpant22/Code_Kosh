// BRUTE FORCE:
 tc=O(N^2) sc=O(1)

vector<int> twoSum(vector<int>& nums, int target) {
       int a,b=0;
       for(int i=0;i<nums.size()-1;i++){
           for(int j=i+1;j<nums.size();j++){
               if(nums[i]+ nums[j]==target){
                   a=i;
                   b=j;
               }
           }
       }
           return{a,b};
       }

// BETTER: or optimal  using hashing
        map<int,int>m;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int a= nums[i];
            int more= target-a;

            if(m.find(more)!= m.end()){ 
//! Is line ka mtlb hai ki map me [ more ] ko find krte hue hum end tk nhi pohche (mtlb more beech m mil ya h)
               return{m[more],i};
            }
            m[a]=i;
        }
        return {-1,-1};

TC=O(n* log n )  SC=o(n)



