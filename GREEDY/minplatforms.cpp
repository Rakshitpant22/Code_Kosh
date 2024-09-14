//!  O(n logn)
int findPlatform(int arr[], int dep[], int n)
    {
     sort(arr,arr+n);
    sort(dep,dep+n);
    
    int i=0,j=1,platforms=1,ans=1;
    while(i<n && j<n){
        if(dep[i]<arr[j]){
            platforms--;
            i++;
        }
        else if(dep[i]>=arr[j]){
            platforms++;
            j++;
        }
        ans=max(ans,platforms);
    }
    return ans;
}

//! O(n) , sc=O(n)
//since time in 24 hr format so max time can be 2359 

    vector<int> arrival(2360,0);
    vector<int> departure(2360,0);
    for(int i=0; i<n; i++){
    	    arrival[arr[i]]++;
    	    departure[dep[i]]++;
    	}
     int ans=0, count=0;
     for(int i=0; i<2360; i++){
         count+=arrival[i];
         ans=max(ans, count);
         count-=departure[i];
     }
     return ans;
