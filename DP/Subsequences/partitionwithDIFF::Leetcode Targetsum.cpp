

#include <bits/stdc++.h>
int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
   
     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken) ;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    //Checking for edge cases
    if(totalsum-d<0) return 0;
    if((totalsum-d)%2==1) return 0;
    int s2= (totalsum-d)/2;
     vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return  f(n-1,s2,arr,dp);
}
// same concept use kia subset cunt krne ka simple but main fucntion k andr changes made are:

//* LOGIC USED :  S1 AND S2 are subsets   
 S1 + S2 = totalsum
 S1 - S2 = difference/D  
 -    -    -
 -------------------------
  0  + 2 S1 = totalsum - D
 -------------------------

 If we calculate the total sum of elements of the array (say totalsum), we can say that:
S1 = totalsum – S2  

we can say that--> S2 = (totSum – D)/2    

//! target ko s2=(totalsum-D)/2 pass krdia  (COUNT SUBSET BASIC PROBLEM MAI)


//& base cases check krne pdenge pehle 
1.As the array elements are positive integers including zero, we dont want to find the case when S2 is negative or
  we can say that totSum is lesser than D, therefore if totSum<D, we simply return 0.

2.S2 cant be a fraction, as all elements are integers, therefore if totSum – D is odd, we can return 0.

 1. totalsum -d >0 mtlb sare posotive ho
 2.( totalsum-d ) even ho 



//^ Partition Equal Subset Sum:
// SAME LOGIC JUST PASS TOTALSUM/2 as TARGET...

 bool canPartition(vector<int>& nums) {
       int n=nums.size();
       int totalsum=0;
       for(int i=0;i<n;i++){
           totalsum+= nums[i];
       }
       if(totalsum%2!=0)return false;
       int k =totalsum/2;
       return f(n,nums,k);

    }

    
