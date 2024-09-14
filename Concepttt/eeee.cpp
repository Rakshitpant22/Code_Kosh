#include <iostream>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

    int main() {
    string word1, word2;
    cin >> word1;  
    cin >> word2;  
   
   int n=word1.size(),m=word2.size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++){ //i==0
            dp[0][j]=j;
        }
        for(int i=0;i<=n;i++){ //j==0
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
    int ans= dp[n][m];
    cout<<ans;
    return 0;
}