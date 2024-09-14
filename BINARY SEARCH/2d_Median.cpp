// solve calculates no of elements <=  predicted median/(mid) from matrix
int solve(vector<vector<int>> &matrix,int n,int m,int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        int idx=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        cnt+=idx;
    }
    return cnt;
}
    int median(vector<vector<int>> &matrix, int R, int C){
    int median= (R*C)/2; //where actually median needs to be
    int low=1;
    int high=2000;
    
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt_smaller_than_mid=solve(matrix,R,C,mid);
        
        //! If the count of elements smaller than or equal to mid is less than or equal to the median index, it means the current mid is too small, and we need to increase the value of mid by moving low up.
        if(cnt_smaller_than_mid<=median){ 
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
    }