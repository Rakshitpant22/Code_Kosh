class Solution {
void f(int open ,int close, vector<string>&ans, string temp){
        if(open==0 &&close==0){
            ans.push_back(temp);
            return;
        }
        if(open>0) f(open-1,close,ans, temp + "(");

        if(close>0 && close>open) f(open ,close-1,ans,temp+")");
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(n,n,ans,"");
        return ans;
    }
};