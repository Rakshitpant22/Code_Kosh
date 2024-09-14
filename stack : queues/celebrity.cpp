// O(N^3)
bool check(int col,vector<vector<int> >& m, int n){
    for(int i=0;i<n;i++){
        if(i!=col && m[i][col]!=1)return false;
    }
    return true;
}
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) {
       for(int i=0;i<n;i++){
           bool flag=true;
           for(int j=0;j<n;j++){
               if(m[i][j]==1){
                   flag=false;
               }
           }
           if(flag && check(i,m,n)){
               return i;
           }
       }
       return -1;
    }

//O(N^2)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) {
        vector<int>i_know(n,0),knows_me(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==1){
                    i_know[i]++;
                    knows_me[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i_know[i]==0 && knows_me[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

// O(n^2) space= O(n)
    int celebrity(vector<vector<int> >& M, int n) {
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int a=st.top(); st.pop();
        int b=st.top(); st.pop();
        if(M[a][b]==1) st.push(b); // a b ko janta h ie (a is not celebrity)--> but b can so push it
        else st.push(a);
       }
       int ans=st.top(); // predicted ans
       
       int zero=0,ones=0;
       for(int i=0;i<n;i++){
           if(M[ans][i]==0){
               zero++;
           }
           if(M[i][ans]==1){
               ones++;
           }
       }
       if(ones==n-1 && zero==n){
           return ans;
       }
      else  return -1;
      return ans;
       
    }

//most optimal;
class Solution {
  public:
    int celebrity(vector<vector<int>>& m, int n) {
      int top=0,down=n-1;
        
      while(top<down){
          if(m[top][down]==1)top++; // top cannot be a celebrity remove it; 
          else if(m[down][top]==1)down--;
          else top++,down--;  
      }
       
      if(top>down)return -1;
       
      for(int i=0;i<n;i++){
          if(m[top][i]==0 && m[i][top]==1|| i==top) continue;
          else return -1;
      }
      return top;
     
    }
};

    