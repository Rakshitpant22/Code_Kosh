class Solution {
    int area(int row, int col,  vector<vector<char>>& matrix ,vector<vector<int>>&dp){
        int m=matrix.size();
        int n=matrix[0].size();
        if(row >= m || col >=n || matrix[row][col] == '0')
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int right =    1 + area(row,col+1,matrix,dp);
        int below =    1 + area(row+1,col,matrix,dp);
        int diagonal = 1 + area(row+1,col+1,matrix,dp);
        
        return dp[row][col] = min(right,min(below,diagonal));
    }
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans = 0;
       vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n ;j ++){
                if(matrix[i][j] == '1'){
                    ans = max(ans, area(i,j,matrix,dp));;
                }
            }
        }
        return ans*ans;
    }
    
};