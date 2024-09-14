//kuch nhi bs 2 baar lis ki chalado ek baar dp1 jo front s start horha h or dp2 jo last index se;

 int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1),dp2(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dp2[i]= max(dp2[i],1+dp2[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>=2&&dp2[i]>=2)// mountain bhi tobnna chahie::
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return n-ans;
    }
         
    //  here we are subtracting from n because we are calculating max/longest length of mountain in given array 
   // and we only need that number of element which are required to make longest mountain so rest of them are don't
  //  needed so we will subtract from total length of array and removed element  is also total numbers of element to
 //   remove from array to make mountain 
      







  