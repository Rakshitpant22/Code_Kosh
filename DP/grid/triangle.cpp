//! MEMOIZATION
class Solution {
    private:
    int f(int i,int j,vector<vector<int>>& triangle, int m ,vector<vector<int>>&dp){

        if(dp[i][j]!=-1)return dp[i][j];
        if(i== m-1) return triangle[i][j];
     
        int down= f(i+1,j,triangle,m,dp);
        int diagnol=f(i+1,j+1,triangle,m,dp);
        return dp[i][j]=  min(down,diagnol)+triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int n= triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));  //(as triangle matrix so at last me rows jitna size hoga
        return f(0,0,triangle,m,dp);
    }
};

//! TABULATION 
 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
       vector<vector<int>>dp(m,vector<int>(m,0)); 
       for(int j=0;j<m;j++){
           dp[m-1][j]=triangle[m-1][j];
       }
// ab 2nd last row se chalenge kyuki last row jo base case declare h uski value  dp se lenge
        for(int i= m-2 ; i>=0 ;i--){
            for(int j = i; j>=0; j--){

                int down = dp[i+1][j];
                int diagnol=dp[i+1][j+1];
                 dp[i][j]= min(down,diagnol)+triangle[i][j];

            }
        }
         
        return dp[0][0];
 // last m bootom up ie tabulation ka ulta hoga 
 // memoization m top case f(0,0)thatabulation me dp[0][0]m answer store hoga kyuki hum  bottom (last row )se up= triangle[0][0] pr ja rhe h
    }
};

//!SPACE OPTIMISATION

 int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        vector<int> front(m,0), cur(m,0);
    
    for(int j=0;j<m;j++){
        front[j] = triangle[m-1][j];
    }
    for(int i=m-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = front[j];
            int diagonal = front[j+1];
            
            cur[j] = min(down, diagonal)+triangle[i][j];
        }
        front=cur;
    }
    
    return front[0];