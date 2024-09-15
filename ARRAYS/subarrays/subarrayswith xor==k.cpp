int solve(vector<int> &a, int k) {
    int n= a.size();
     map<int, int> mpp; //declaring the map.
     int xr=0;
     mpp[xr]++; //setting the value of 0.
     int cnt = 0;
 
    for (int i = 0; i < n; i++) {
        xr ^= a[i];

        int x = xr ^ k;

        if(mpp.find(x)!=mpp.end()){
           cnt += mpp[x];
        }
        mpp[xr]++;
    }
    return cnt;
}