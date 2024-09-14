class Solution {
    int f(int i,int j, vector<int>& cuts, vector<vector<int>>&dp){
        if(i>j)return 0;
        int mini=1e9;
      if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
        mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts,dp);
    }
};