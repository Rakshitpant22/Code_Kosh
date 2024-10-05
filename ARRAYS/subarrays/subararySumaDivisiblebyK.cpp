int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum%k==0)ans++;
        //     }
        // }

        //! catch in this problem:
        //* [a, , , ,d,b] cummulative sum from a to b = sum1 and rem= sum1%k
        //* [a, , c ,d,b] cummulative sum from a to c = sum2 and sum2%k === rem;

        //* then subarray sum from d to b is divisible by k;


        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0; //cummulative sum
        for(auto it:nums){
            sum+=it;
            int rem= ((sum%k)+k)%k;
            if(mpp.find(rem)!=mpp.end()){
                ans+=mpp[rem];
            }
            mpp[rem]++;
        }
        return ans;
    }