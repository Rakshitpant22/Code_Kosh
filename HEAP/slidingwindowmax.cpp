 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
         priority_queue<pair<int,int>>pq;
         vector<int>ans;
         
       for(int i=0;i<k;i++){
         pq.push({nums[i],i});
       }
           ans.push_back(pq.top().first);

           for(int i=k;i<n;i++){
               pq.push({nums[i],i});
            // remove all the elments which are not in the current window
            // current window is from [i-k+1 , i]
           
          while(i- pq.top().second >=k){  
           //! pichli line ka mtlb ki agr ith index - top eleemnt ka index k ya k se bda arha to top ko pop krado;
                pq.pop();
            }
               ans.push_back(pq.top().first);
           }
       
       return ans;
    }