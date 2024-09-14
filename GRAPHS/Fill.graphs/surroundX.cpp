//APROACH 1 : BFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int n=board.size();
       int m= board[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       queue<pair<int,int>>q;
         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j< m; j++)
            {
                if(i== 0 || j==0 || i== n-1|| j== m-1){ // for boundary 
                    if(board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }      
    }
        
       int delrow[]={0,0,-1,1};
       int delcol[]={-1,1,0,0};
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow= row+ delrow[i];
                int ncol= col+ delcol[i];
      
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && !vis[nrow][ncol]
               && board[nrow][ncol]== 'O'){
                  q.push({nrow,ncol});
                  vis[nrow][ncol]=1;
            }
         } 
    }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]= 'X';
                }
            }
            
        }
    } 
    
};



// APPROACH 2 : USING DFS:
class Solution {
public:
void dfs(int row,int col, vector<vector<char>>& board,vector<vector<int>>&vis,int delrow[],int delcol[]){
      int n = board.size();
        int m = board[0].size();
       vis[row][col]=1;
       for(int i=0;i<4;i++){
           int nrow= row+delrow[i];
           int ncol=col+delcol[i];
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
           && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
               dfs(nrow,ncol,board,vis,delrow,delcol);
           }
       }
}

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[]={0,0,-1,1};
       int delcol[]={-1,1,0,0};
       vector<vector<int>>vis(n,vector<int>(m,0));

        // traverse first rows
        for(int j=0;j<m;j++){
            //for fisrt row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis,delrow,delcol);
            }
             if(!vis[n-1][j] && board[n-1][j]=='O'){
                 dfs(n-1,j,board,vis,delrow,delcol);
             }
        }
       // for first coloumn and last colpumn
        for(int i=0;i<n;i++){
            //for fisrt row
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis,delrow,delcol);
            }
             if(!vis[i][m-1] && board[i][m-1]=='O'){
                 dfs(i,m-1,board,vis,delrow,delcol);
             }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
            }
        
    }
};



