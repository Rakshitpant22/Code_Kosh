vector<int>NSER(vector<int>& heights){
    int n=heights.size();
    vector<int>ans(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int>NSEL(vector<int>& heights){
    int n=heights.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
  return ans;
}
vector<int>l=NSEL(heights);
vector<int>r=NSER(heights);
int ans=0;
for(int i=0;i<n;i++){
    ans=max(ans,heights[i]*(r[i]-l[i]-1));
}
return ans;

//! efficient ---> monotonic stack;
int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n ||heights[st.top()]>heights[i])){
                int h=heights[st.top()];
                st.pop();
                int w;
                if(st.empty())w=i;
                else w= i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
        return ans;