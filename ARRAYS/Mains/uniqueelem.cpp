 
//! BY HASHMAPS
TC: O(N)
SC: O(N)
 
 int singleNumber(vector<int>& nums) {
     unordered_map<int,int>m;
        for(auto it: nums){
            m[it]++;
        }
        for(auto it: m){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
 }
 
 //! BY SORTING
 TC: O(NlogN)
  SC: O(1)

   sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            if(nums[i]!=nums[i-1])
            return nums[i-1];
        }
        return nums[nums.size()-1];

//! XOR 

      int unique= 0;
        for( auto it:nums)
        unique^=it;
        return unique;
