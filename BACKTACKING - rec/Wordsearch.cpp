// ! VIA BFS
class Solution {
    private: 
 bool bfs(int index,int row,int col ,vector<vector<int>>&vis,vector<vector<char>>& board, string word){
        int n= board.size();
        int m=board[0].size();
        int delrow[]={0,0,-1,1};
        int delcol[]={-1,1,0,0};

       if (index == word.size())
    {
        return true;
    }

       vis[row][col]=1;
       for(int k=0;k<4;k++){
            int nrow= row+delrow[k];
            int ncol= col +delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&!vis[nrow][ncol] && word[index]==board[nrow][ncol]){
               if(bfs(index+1,nrow,ncol,vis,board,word)==true)
               {
                   return true;
               }
            }
       }
        vis[row][col]=0;
        return false;


 }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]) // jaha pehla alphabet mil gya word ka vhi sbfs chla do...
                 {
                    bool ans= bfs(1,i,j,vis,board,word);
                    if(ans){
                    return ans;
                    }
                }

            }
        }

        return false;
    }
};