//! IMP QUESTION : 

 int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int n= nums.size();
        if(n==0)return 0;
        int ans;

        for(auto it:s){
            if(s.find(it-1)==s.end()){ // if no we r considering does have any no before it 
                int cnt=1;
                int x= it;

                while(s.find(x+1)!= s.end()){
                    x=x+1;
                    cnt=cnt+1;

                }
                ans=max(ans,cnt);
            }
        }
       return ans;
    }