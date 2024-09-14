#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;

int dp[101][1000001];

int solve(int target,vector<int>&arr,int n){
// if(i==0){
//     if(target%arr[0]==0)return 1;
//     return 0;
// }
// if(dp[i][target]!=-1)return dp[i][target];
// int nottake= solve(i-1,target,arr);
// int take=0;
// if(target>=arr[i]){
//     take= solve(i,target-arr[i],arr);
// }
// return dp[i][target]=(take+nottake)%MOD;
// }
 for (int i = 0; i <= target; i++) {
        if (i % arr[0] == 0) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (j >= arr[i]) {
                take = dp[i][j- arr[i]];
            }
            dp[i][j] = (take + nottake) % MOD;
        }
    }

    return dp[n - 1][target];
}


int main(){
int n,x;
cin>>n>>x;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
memset(dp,0,sizeof(dp));
cout<<solve(x,arr,n);
return 0;
}