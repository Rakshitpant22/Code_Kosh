class Solution {
public:
    int fib(int n) {
       if(n==0)return 0;
       int  prev2=0;
        int prev1=1;
        for(int i=2; i<=n;i++){
        int curri = prev1+prev2;
          prev2=prev1;
          prev1=curri;
        }
        return prev1;
    }
};


//! TRIBONACCI  
class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(n+1);
        if(n==0)return 0;
          int prev1=1;
          int prev2=1;
          int prev3=0;
        for(int i=3;i<=n;i++){
            int curri= prev1+prev2+prev3;
            prev3=prev2;
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
    }
};