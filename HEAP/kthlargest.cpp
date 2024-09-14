//! heapsort and find arr[n-k] element 
TC= O(nlogn)..
void heapify(vector<int>& nums,int n,int i){
      int largest=i;
      int left=2*i+1;
      int right=2*i+2;

      if(left<n && nums[left]>nums[largest]){
          largest=left;
      }
       if(right<n && nums[right]>nums[largest]){
          largest=right;
      }
       if(largest!=i){
           swap(nums[largest],nums[i]);
           heapify(nums,n,largest);
       }

   }

   void buildheap(vector<int>& nums,int n){
     for(int i=(n-2)/2;i>=0;i--){
         heapify(nums,n,i);
     }
   }

   void heapsort(vector<int>& nums,int n){
        buildheap(nums,n);
       for(int i= n-1;i>=1;i--){
           swap(nums[0],nums[i]);
           heapify(nums,i,0);
       }
   }

    int findKthLargest(vector<int>& nums, int k) {
        int n= nums.size();
        heapsort(nums,n);
       return nums[n-k];
    }

//! Approach 2; Pioroty queue
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int ans=0;
        // kjab tak zero nhi hoga
        while(k--){
            ans=pq.top();
            pq.pop();
        }
        return ans;
}

VVVI
//! MIN HEAP CONCEPT:

//^ K size ka min heap maintain krna ha---> top element remove krna hai or naya element push krna hai--->return pq.top().
  priority_queue<int,vector<int>,greater<int>>pq;

    for(auto it: nums){
        pq.push(it);
        if(pq.size()>k){
            pq.pop();
        }
    }
       return pq.top();
    
    // agr smallest  kth element nikalna  h to max heap maintain kro of size k; last m top ans hoga.. 