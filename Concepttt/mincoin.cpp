#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
int n,x;
cin>>n>>x;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
 // memset(dp,1e9,sizeof(dp)); memset can only change value to -1 0 only 
 vector<vector<int> >dp(n+1,vector<int>(x+1,1e9));
 
for(int i=0;i<=x;i++){
    if(i%arr[0]==0){
        dp[0][i]=i/arr[0];
    }
}

for(int i=1;i<n;i++){
    for(int tar=0;tar<=x;tar++){
         int nottake = dp[i - 1][tar];
         int take=1e9;
          if (tar >= arr[i]) {
                take = 1+dp[i][tar- arr[i]];
            }
        dp[i][tar] = min(take,nottake);
    }
}
int res = dp[n-1][x];
if(res==1e9)cout<<-1;
else cout<<res;
}




//int solve(int i,int target,vector<int>&arr){
// if(i==0){
//     if(target%arr[0]==0)return target/arr[0];
//     else return 1e9;
// }
// if(dp[i][target]!=-1)return dp[i][target];
// int nottake= 0+solve(i-1,target,arr);
// int take=1e9;
// if(target>=arr[i]){
//     take = 1+solve(i,target-arr[i],arr);
// }
// return dp[i][target]=min(take,nottake);
// }