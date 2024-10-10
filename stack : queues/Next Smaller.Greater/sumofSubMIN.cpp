https://leetcode.com/problems/sum-of-subarray-minimums/description/
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are   3,   1,   2,   4,    1,     1,    2,       1,       1,        1
Sum is 17.

//BRUTE
int sumSubarrayMins(vector<int>& arr) {
int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=1e9;
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                ans+= mini;
            }
        }
return ans;
    }

//! Optimal -

//approach:
kisi index p khade h to l = no of elements smaller than arr[idx] to left 
                        r = no of elements smaller than arr[idx] to right 
and therefore  arr[idx] would be min in (l+1)*(r+1) subarrays

class Solution {
public:
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
   
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum=0;
      
      vector<int>NSEL= gNSEL(arr,n);
      vector<int>NSER= gNSER(arr,n);


         for(int i=0;i<n;i++){
           long long ls = i - NSEL[i];
           long long lr = NSER[i] - i;

           long long ways=ls*lr; //total subarrays with min as arr[i]
           
           sum += (arr[i]* ways)%MOD;
       }
       return sum;
    }
};
