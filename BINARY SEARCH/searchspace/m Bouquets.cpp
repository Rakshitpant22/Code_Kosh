int solve(vector<int>& bloomDay,int day,int n,int k){
    int bouquets=0,cnt=0;
      for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
            if(cnt==k){
            bouquets++;
            cnt=0;
            }
        }
        else{
            cnt=0;
        }
      }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n)return -1;

        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=1e9;
        
        // O(n^2)
        // for(int day=low;day<=high;day++){ //~ this loop can be implemented by binary search
        //     if(solve(bloomDay,day,n,k)>=m){
        //         ans=min(ans,day);
        //     }
        // }
   

   //~ this has tc = O(n logn )
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquets=solve(bloomDay,mid,n,k);
            if(bouquets>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }