//  To maximize total tips, they must distribute the orders such that:

// A can handle at most x orders
// B can handle at most y orders
// Given that x + y ≥ n, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders.

//! approach1 -- DP
long long dp[101][101][101];
long long solve(int idx, int x, int y, vector<int>& arr, vector<int>& brr, int n) {
    if (idx == n) return 0;  // Base case: no customers left
    
    if (dp[idx][x][y] != -1) return dp[idx][x][y];  // Check if already computed

    long long tipA = 0, tipB = 0;

    if (x > 0) {  // Assign to waiter A
        tipA = arr[idx] + solve(idx + 1, x - 1, y, arr, brr, n);
    }
    if (y > 0) {  // Assign to waiter B
        tipB = brr[idx] + solve(idx + 1, x, y - 1, arr, brr, n);
    }
    return dp[idx][x][y] = max(tipA, tipB);
}

long long maxTip(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
    memset(dp, -1, sizeof(dp));  // Initialize memoization array with -1
    return solve(0, x, y, arr, brr, n);
}

//! Optimal approach-- GREEDY 
 long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int,int>>v; // difference of profits and its index:
        for(int i=0;i<n;i++){
            v.push_back({abs(arr[i]-brr[i]),i});
        }
        sort(v.rbegin(),v.rend()); // in decreasing order to maximise more profit;
        
        long long  totaltip=0;
        
        for(int i=0;i<n;i++){
            int idx=v[i].second;
            if(arr[idx]>brr[idx]){
                if(x>0){
                totaltip+=arr[idx];
                x--;
                }
                else{
                totaltip+=brr[idx];
                y--;
                }
            }
            
            else{
                if(y>0){
                    totaltip+=brr[idx];
                    y--;
                }
                else{
                    totaltip+=arr[idx];
                    x--;
                }
            }
        }
        return totaltip;
    }