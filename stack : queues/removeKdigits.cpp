//! IMP
//! Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){ // hme aage ki digits min chahie to jabtak aage ki badi h & k>0 pop krte jao
                st.pop();
                k--;
            }
            st.push(num[i]);
      }
      while(k>0 && !st.empty()){ // if more k are remaning  ex k=2 num="2345"
        st.pop();
        k--;
      }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end()); //stack s order reverse hogya tha 
        
       //remove trailing zeroes
        while(ans.size()>1 && ans[0]=='0'){
            ans.erase(ans.begin());
        }
        return ans.empty()? "0" : ans;
    }
};