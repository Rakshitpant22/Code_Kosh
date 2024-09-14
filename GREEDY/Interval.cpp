 //! Merge overlapping intervals
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n=intervals.size();
      sort(intervals.begin(),intervals.end());
       vector<vector<int>>ans;
       for(int i=0;i<n;i++){
           if(ans.empty() || inintervals[i][0]>ans.back()[1]){
               ans.push_back(intervals[i]);
           }
        
           else{
               ans.back()[1]=max(ans.back()[1],intervals[i][1]);
           }
       }   
       return ans;
    }

//! Non-overlapping Intervals
//~ Approach 1= find the ans by merging overlapping intervals then (intial size-ans size)= Is minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

//~ Approach 2: basically its N meeting in 1 room 
// bcs in that question we want max meeting in 1 room without overlapping 
// so find max intervals that are not overlapping amd total -max is minimum no of intervals to delete to make non overlapping intervals;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];  //sort by ending time
        });

        int prev=intervals[0][1],ans=1; //ans= non overlapping intervals;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=prev){
                ans++;
                prev=intervals[i][1];
            }
        }
        return n-ans;


