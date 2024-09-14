class Solution {
    private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();

         queue<pair<int,int>>q;
         vis[row][col]=1;
         q.push({row,col});

         while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop(); 

         int delrow[] = {-1,0,1,0};
         int delcol[] = {0,-1,0,1};
          for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i]; 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                   && grid[nrow][ncol] == '1' && vis[nrow][ncol]==0 ){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
             }
          }
       }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt=0;
         for(int i=0;i<n;i++ ){
             for(int j=0;j<m;j++){
                 if(grid[i][j]=='1' && vis[i][j]==0){
                 cnt++;
                 bfs(i,j,grid,vis);
                 }
             }
         }
         
         return cnt;
    }
};
// isme hme count krna h islands jo ek group m sath honge to yad RHE KI BFS RECUSRIVLY LGAO or jab jab bfs lgega mtlb 
// alag pair of islands hobge to cnt++ krdo or last m cnt return krvado;;