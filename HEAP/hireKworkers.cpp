 cost[] array given cost of worker, hme k workers lene h and choose min in groups of p(from start) and (from end)
 
   long long totalCost(vector<int>& costs, int k, int p) {
   int n= costs.size();
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;

        int i=0;int j=n-1;
        long long ans=0;

        while(k--){
            while(pq1.size()<p && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<p && i<=j){
                pq2.push(costs[j--]);
            }
        
         int a= pq1.size()>0?pq1.top():1e9;
         int b= pq2.size()>0?pq2.top():1e9;

         if(b>=a){
             ans+=a;
             pq1.pop();
         }
         else{
             ans+= b;
             pq2.pop();
         }
        }
        return ans;
      }
        
    