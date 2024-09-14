https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

//brute force-- Dynamic programming
//! very large memory needed
int dp[100001][10001][10001];
int solve(int i,int j,vector<int>& nums, int k){
    if(k==0|| i>j)return 0;

     if(dp[i][j][k]!=-1)return dp[i][j][k];
     
    int takeback=0,takefront=0;
    takefront=nums[i]+solve(i+1,j,nums,k-1);
    takeback= nums[j]+solve(i,j-1,nums,k-1);

    return dp[i][j][k]=max(takeback,takefront);
}
    int maxScore(vector<int>& cardPoints, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,cardPoints.size()-1,cardPoints,k);
    }

//! Optimised Approach

 int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size(),right_idx=n-1;
    int sum= accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
    int maxi=sum;

    for(int i=k-1;i>=0;i--){
        sum-=cardPoints[i];
        sum+=cardPoints[right_idx];
        right_idx--;
        maxi=max(maxi,sum);
    }
    return maxi;
 }