https://leetcode.com/problems/kth-missing-positive-number/description/
//! KTH MISSING POSITIVE NUMBER


int findKthPositive(vector<int>& arr, int k) {
     // ex             2 3 4 7 11
    //SUPPOSED ARR     1 2 3 4  5  6 7 8 9 10 11

// no's missing till index i can be found by arr[i]-(i+1); 
// so we can sue binary search as if missing no's at i <k we move to right side
// else to left side

//! optimal -
int n=arr.size();
int low=0,high=n-1;
while(low<=high){
    int mid=low+(high-low)/2;
                         //actual element- element supposed to be at mid index
    int missing_numberstill_mid= arr[mid]-(mid+1);

    if(missing_numberstill_mid < k){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return low+k;
}

//! brute force
     int num=1;
        int i=0,n=arr.size();

        while(i<n && k>0){
           if(arr[i]==num){
            i++;
           }
           else{
            k--;
           }
            num++;
        }
    
      while(k--){
        num++;
      }
      return num-1;