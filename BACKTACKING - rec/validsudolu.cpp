class Solution {
public:

  bool isvalid(vector<vector<char>>& board,int row,int col,char c){
      for(int i=0;i<9;i++){
          if(board[i][col]==c)return false;
           if(board[row][i]==c)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
      }
      return true;
  }
// main function...
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
         for(int j=0;j < board[0].size() ;j++){
             if(board[i][j]=='.')continue;
             char c= board[i][j];
             board[i][j]='.';
             if(!isvalid(board,i,j,c))return false;
             board[i][j]=c;
         }
        }
        return true;
    }
};