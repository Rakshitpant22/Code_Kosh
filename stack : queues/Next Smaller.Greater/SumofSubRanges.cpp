// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.

// same conceot as sum of subarray mins
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

// solution = [sum of subarray maximum - sum of subarray manimum]

int MOD = 1e9+7;
vector<int>gNSEL(vector<int>& arr,int n){
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>gNSER(vector<int>& arr,int n){
    vector<int>ans(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>gNLEL(vector<int>& arr,int n){
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>gNLER(vector<int>& arr,int n){
    vector<int>ans(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
   
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        vector<int>NSEL=gNSEL(arr,n);
        vector<int>NSER=gNSER(arr,n);
        vector<int>NLER=gNLEL(arr,n);
        vector<int>NLEL=gNLER(arr,n);
        
        for(int i=0;i<n;i++){
            int l1= i-NSEL[i];
            int r1= NSER[i]-i;
            int l2= i-NLEL[i];
            int r2= NLER[i]-i;

            ans+= arr[i]*((long long)(l2*r2)-(long long)(l1*r1));
        }
       return ans;
    }