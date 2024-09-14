// frog can tage 1/2 steps jump from one to another point (indexes in a array)
// Energy given by array difference ..

//^ RECURSIVE
//& TC=O(N)    SC=O(N)   +   O(N)        
     |           |            |
     ^            ^           ^
    rec.time     dp vector    recursion stack space
     
int f(int ind, vector<int> &heights){
   if(ind==0 )return 0;
   int left= f(ind-1,heights)+ abs(heights[ind]-heights[ind-1]);
   int right=1e9;
   if(ind>1) right= f(ind-2,heights)+ abs(heights[ind]-heights[ind-2]);
   return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);    // bcs the answer will be stored at last index after all the iterations...
}

//! DP 

//^ Memoization - top down approach 

// TC= 0(N)   SC= O(N) 
int f(int ind, vector<int> &heights, vector<int>&dp){
   if(ind==0 )return 0;
   if(dp[ind]!=-1)return dp[ind]; // agr dp[ind] has already calculated(in  case of overlapping intervals)
   int left= f(ind-1,heights,dp)+ abs(heights[ind]-heights[ind-1]);
   int right=1e9;
   if(ind>1) right= f(ind-2,heights,dp)+ abs(heights[ind]-heights[ind-2]);
   return dp[ind]=min(left,right); // insted of just return min store int the dp vector
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);  // step 1 declare dp vector with all -1
    return f(n-1,heights,dp);
}

// ^  TABULATION 
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{

vector<int> dp(n,-1);
  dp[0]=0;
  for(int i=1;i<n;i++){
      int right = 1e9;
        int left= dp[i-1] + abs(height[i]-height[i-1]);
        if(i>1)
            right = dp[i-2] + abs(height[i]-height[i-2]);
    
        dp[i]=min(left,right);
  }
  return dp[n-1];
}


//^  SPACE OPTIMISATION  SC: O(1)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
  int prev2=0;
  int prev1=0;
  
    for(int i=1;i<n;i++){
        int left= prev1+abs(heights[i]-heights[i-1]);
        int right=1e9;
        if(i>1)
        right = prev2+abs(heights[i]-heights[i-2]);
          int curri = min(left,right);
          prev2=prev1;
          prev1=curri;
    }
    return prev1;
    
}
