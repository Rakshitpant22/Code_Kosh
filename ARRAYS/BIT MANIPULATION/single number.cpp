//* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

//! aprroch for every bit cslculate no of set bits /ones in all array elements
//! at last in specific bit if ones are in multiple of 3 then continue else set that bit
int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++) {
            int cnt_zeroes = 0, cnt_ones = 0;
            for (auto it : nums) {
                if (it & (1 << bit)) {
                    cnt_ones++;
                } else {
                    cnt_zeroes++;
                }
            }
            if(cnt_ones%3!=0){
                ans|= 1<<bit;
            }
        }
        return ans;
    }

//* Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 

  vector<int> singleNumber(vector<int>& nums) {
        long long res=0;
        for(auto it:nums){
            res^=it; // this is xor of two numbers that are appearing once
        }
     // to find the [k = rightmost differentbit] in res(which is xor of 2 differnt integers)
     // ! since xor  of different bits = 1 so based on different bits set in res we can group two numbers
     int k=-1;
     for(int i=0;i<32;i++){
        if(res & (1<<i)){
            k=i;
            break;
        }
     }
    
    // on the basis of rightmost set bit which would only set in 1 integer 2 groups formed 
      int a=0,b=0;
      for(auto it:nums){
        if(it & (1<<k)){
            a^=it;
        }
        else{
            b^=it;
        }
      }
       return {a,b};
    }

//! rightmost set bit  can be found by following
//~ 1. [XOR & (-XOR)] -> only sets the different bit
//~ 2. traverse xor and if (1 & (XOR<<i)) break and this is rightmost set bit
//~ 3. (XOR & (XOR -1)) ^ XOR