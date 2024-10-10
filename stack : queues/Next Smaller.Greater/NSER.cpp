//! NGER
vector<int> ans(n, -1);
stack<int> st;

for (int i = n - 1; i >= 0; i--)
{
    while (!st.empty() && st.top() <= arr[i])
    {
        st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
}
return ans;

//! NGEL
vector<int> ans(n, -1);
stack<int> st;

for (int i = 0; i <n ; i++)
{
    while (!st.empty() && st.top() <= arr[i])
    {
        st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
}
return ans;

//! NSER
vector<int> ans(n, -1);
stack<int> st;

for (int i = n - 1; i >= 0; i--)
{
    while (!st.empty() && st.top() >= arr[i])
    {
        st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
}
return ans;

//! NSEL
vector<int> ans(n, -1);
stack<int> st;

for (int i = 0; i <n ; i++)
{
    while (!st.empty() && st.top() >= arr[i])
    {
        st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
}
return ans;