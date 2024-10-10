// column wise bulding ka size calculate krle largest rect in histogrAM

class Solution {
public:
int solve(vector<int>&heights){
 int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n ||heights[st.top()]>heights[i])){
                int h=heights[st.top()];
                st.pop();
                int w;
                if(st.empty())w=i;
                else w= i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1') grid[0][i]=1;
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j]=='1'){
                    grid[i][j]=1+grid[i-1][j];
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
          res=max(res,solve(grid[i]));
        }
        return res;
    }
};