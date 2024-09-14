Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with
 itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
//^  is question m y count krna h kinti baar elements lene h to make n in form of squares:

class Solution {
    int f(int n){
        if(n<=0)return 0;

        int ans= 1e9;
        for(int i=1;i*i<=n;i++){
            int score=i*i;
            int cnt=1+f(n-score);
            ans= min(cnt,ans);
        }
        return ans;
    }
public:
    int numSquares(int n) {
        return f(n);
    }
};

//^ ques 2:

 Given two positive integers n and x.
Return the number of ways n can be expressed as the sum of the xth power of unique positive integers,
Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.

//! isme cnt krne h ways tobase case m 1 0 return krvanege

 int f(int i,int n,int x){
    if(n<0)return 0;
    if(n==0)return 1;
    if(pow(i,x)>n)return 0;

    int score= pow(i,x);
    int nottake= f(i+1,n,x);
    int take= f(i+1,n-score,x);
    return take + nottake;
 }

main(int n,int x){
    return f(1,n,x);
}