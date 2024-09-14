//~ Min no of steps to reach n-1 idx

//!Most optimal -- Greedy soln
int farthest=0,jumps=0,next_idx=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,nums[i]+i);
        
            if(i==next_idx){
                jumps++;
                next_idx=farthest;
            }
        }
        return jumps;

//! o(n)
vector<int>dp;
int solve(int i,vector<int>& nums,int n){
if(i>=n-1)return 0;
int steps=1e9;

if(dp[i]!=-1)return dp[i];

for(int j=1;j<=nums[i];j++){
    steps=min(steps,1+solve(i+j,nums,n));
 } 
return dp[i]=steps;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(0,nums,n);
    }
    
//! o(n^2) 
 int n=nums.size();
        vector<int>dp(n,1e9);
        dp[0]=0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i] &&i+j<n;j++){
                dp[i+j]=min(dp[i+j],1+dp[i]);
            }
        }
        return dp[n-1];