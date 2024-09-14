 // !brute/better
   TC: O(N^2) SC=0(1);

 int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int maxi= -1e9;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+= nums[j];
                maxi= max(maxi,sum);
            }
        }
        return maxi;
    }

//! KADANE'S ALGO
TC=O(N) SC=O(1)

        int n =nums.size();
        int sum=0;
        int maxi=-1e9;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum>maxi){
                maxi=sum;
            }
        
        if(sum<0){
            sum=0;
        }
        }
    
        return maxi;
    