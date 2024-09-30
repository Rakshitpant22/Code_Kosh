https://leetcode.com/problems/design-a-stack-with-increment-operation/description

// Opimal all opeerations in O(1)
class CustomStack {
public:
        vector<int>ans;
        vector<int>increments;
        int n;
    CustomStack(int maxSize) {
         n=maxSize;
    }
    
    void push(int x) {
        if(ans.size()<n){
            ans.push_back(x);
            increments.push_back(0);
        }
    }
    
    int pop() {
        if(ans.empty()){
            return -1;
        }
        int idx=ans.size()-1; //last idx of stack/array

        if(idx>0){
            increments[idx-1] += increments[idx];
        }
        int topValue = ans[idx]+increments[idx];

        ans.pop_back();
        increments.pop_back();

        return topValue;
    }
    
    void increment(int k, int val) {
        int idx=min(k,(int)ans.size())-1;

        if(idx>=0){
            increments[idx] += val;
        }
    }
};


//BRUTE:
class CustomStack {
public:
stack<int>st;
stack<int>temp;

int n;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(st.size()< n){
            st.push(x);
        }
    }
    
    int pop() {
        int res=-1;
        if(!st.empty()){
            res=st.top();
            st.pop();
        }
        return res;
        
    }
    
    void increment(int k, int val) {
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        k = min(k,(int)temp.size());
        while(k--){
            int x= val+temp.top();
            st.push(x);
            temp.pop();
        }

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};
