
//!  RECURSION  
class Solution {
    private:
    int f(int i,int j,vector<vector<int>>& matrix){
         int m = matrix.size();
       
      //! return max value krdo agr col limit se age jata ha  (kyuki use min path chahie or humne col se matrix bhar chala jae to max value di h )
    if(j<0 ||j>=m )return 1e9;  //  col hi limit s bhar ja slte h kyuki row agr 0 ho jati h to vo base case sambhal lega
    if(i==0)return matrix[0][j]; // bases cases
    
    int up=f(i-1,j,matrix);
    int leftd=f(i-1,j-1,matrix);
    int rightd=f(i-1,j+1,matrix);
    return matrix[i][j]+ min(up,min(leftd,rightd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
             int mini = 1e9; // min negative bhi ho skta h to isle ma x s max value p assign krdia 
  

        for(int j=0;j<m;j++){    // hume last row p jana h koi bhi col MIN/MAX answe d skta h to sbme s min ans lena hai
            mini =min(mini,f(m-1,j,matrix));
           
        }
        return mini;
    }
};

//!  MEMOIZATION
 private:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
          int m= matrix.size();
          int n= matrix[0].size();
         
         if(j<0||j>=n)return 1e9;
          if(i==0)return matrix[0][j];
    
        if(dp[i][j]!=-1)return dp[i][j];
           int up= f(i-1,j,matrix,dp);
           int ld= f(i-1,j-1,matrix,dp);
           int rd= f(i-1,j+1,matrix,dp);

           return dp[i][j]= min(up,min(ld,rd))+matrix[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,f(m-1,i,matrix,dp));
        }
        return mini;
    }

//!  TABULATION

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
       for(int j=0;j<m;j++)dp[0][j]=matrix[0][j];

           for(int i=1;i<m;i++){
               for(int j=0;j<n;j++){

             int up = matrix[i][j] + dp[i-1][j];
            
            int ld= matrix[i][j];
            if(j-1>=0) ld+= dp[i-1][j-1];
            else ld+= 1e9;
            
            int rd= matrix[i][j];
            if(j+1<m) rd+= dp[i-1][j+1];
            else rd += 1e9;
               dp[i][j]=min(up,min(ld,rd));

               }
           }
           int mini =1e9;
           for(int j=0;j<m;j++){
                mini=min(mini,dp[m-1][j]);
           }

            return mini;
    }
};

