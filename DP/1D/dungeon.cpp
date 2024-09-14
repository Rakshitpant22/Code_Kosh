 int f(int i,int j,vector<vector<int>>& dungeon,int n,int m, vector<vector<int>>&dp){
  if(i>=n||j>=m)return 1e9;
        
        if(dp[i][j]!=-1)return dp[i][j];

        int down= f(i+1,j,dungeon,n,m,dp);
        int right=f(i,j+1,dungeon,n,m,dp);
        int res= min(down,right);

        if(res==1e9){ // mtlb end of grid pohchgye to:
        res= 1;
        }

      int ans=0;
         if(res-dungeon[i][j]>0){
            return ans= res-dungeon[i][j];
        }
        else{
            ans=1;
        }
         return dp[i][j]=ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n= dungeon.size();
        int m= dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   return f(0,0,dungeon,n,m,dp);
    }