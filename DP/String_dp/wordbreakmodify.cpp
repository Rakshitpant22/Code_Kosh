 // remove extra caharacter s from s which are not present in the dictiinonary :
 
 class Solution {
public:
    int f(int i, string s, unordered_set<string>& st, vector<int>&dp) {
        int n= s.size();
        if (i == n) {
            return 0;
        }
     if(dp[i]!=-1)return dp[i];
        int ans = 1e9;

        for (int j = i + 1; j <= n; j++) {
            string cur = s.substr(i, j - i);
            if (st.find(cur) != st.end()) {
                ans = min(ans, f(j, s, st,dp));
            }
            else {
                ans = min(ans, j - i + f(j, s, st,dp));
            }
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
       int n = s.length();
       vector<int>dp(n,-1);
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return f(0, s, st,dp);
    }


};