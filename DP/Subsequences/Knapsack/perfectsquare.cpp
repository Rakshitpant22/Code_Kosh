 class Solution {
public:
int f(int n){
    if(n<=0)return 0;

    int ans=1e9;
    for(int i=1;i*i<=n;i++){
        int square=i*i;
        int cnt=1+ f(n-square);
        ans=min(ans,cnt);
    }
    return ans;
}
    int numSquares(int n) {
       return f(n);
    }
};
