// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). 
// Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.


vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis,int n,int m){
 vis[i][j]=1;
 bool flag=true;
 
 if(grid1[i][j]!=1){
    flag= false;
 }
 for(auto it:dir){
    int nrow=i+it[0];
    int ncol=j+it[1];
    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid2[nrow][ncol]==1 && !vis[nrow][ncol]){
        if(!dfs(nrow,ncol,grid1,grid2,vis,n,m)){
            flag=false;
        }
    }
 }
return flag;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                   if(dfs(i,j,grid1,grid2,vis,n,m)){
                    cnt++;
                   }
                }
            }
        }
        return cnt;
    }



//! Wrong code
//~This is wrong as dfs must check for all the cells of grid 2 are valid island in grid 1 to ensire that we must traverse all the cells of grid 2;
//~
bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int n, int m) {
    vis[i][j] = 1;

    // If the corresponding cell in grid1 is not land, return false
    if (grid1[i][j] != 1) {
        return false;
    }

    bool isSubIsland = true;

    // Explore all 4 possible directions
    for (auto it : dir) {
        int nrow = i + it[0];
        int ncol = j + it[1];
        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid2[nrow][ncol] == 1 && !vis[nrow][ncol]) {
            // If any DFS call returns false, mark the whole island as not a sub-island
            if (!dfs(nrow, ncol, grid1, grid2, vis, n, m)) {
                isSubIsland = false;
            }
        }
    }
    return isSubIsland;
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
  
                   if(dfs(i,j,grid1,grid2,vis,n,m)){
//! Yaha ques m hme pura island of grid 2 p check krna h and if its valid inc cnt of islands               
//!  Ye jab jab dfs true return krega tab cnt bdha rha h 
                    cnt++;
                   }
                }
            }
        }
        return cnt;
    }