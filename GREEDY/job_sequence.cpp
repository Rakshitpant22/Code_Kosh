   //! TC= O(n logn)+ O(n* max_deadline)
   static bool cmp(Job &a,Job &b){
        return a.profit>b.profit;
    }
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int profit=0,cnt=0;
        
        int max_deadline=-1;
        for(int i=0;i<n;i++){
            max_deadline=max(max_deadline,arr[i].dead);
        }
        vector<int>v(max_deadline+1,-1);
        
        for(int i=0;i<n;i++){
            // check any slot left that is less than deadline found
            for(int j=arr[i].dead;j>0;j--){ //! This extra loop can be reduced to O(1) by DSU
                if(v[j]==-1){
                    v[j]=arr[i].id;
                    profit+=arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt,profit};
    } 

//! Most Optimised 
int findParent(){
    
}