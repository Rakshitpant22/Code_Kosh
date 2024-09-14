class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch: s){
            if(ch=='(' || ch=='[' ||ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()){return false;}/// if has to {,[,( bracket return false;
                if((ch==']'&&st.top()=='[')||
                (ch=='}'&&st.top()=='{')||
                (ch==')'&&st.top()=='(')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
      
       return (st.empty()==true);
    }
};