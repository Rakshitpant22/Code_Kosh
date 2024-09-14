 //! FRUITS INTO BASKETS
 //! longest subarry having at most 2 different integers
  int totalFruit(vector<int>& fruits) {
        // basically find max subarray having atmost 2 diffnt elements(fruits)
        int n=fruits.size(),l=0,r=0,ans=0;
        unordered_map<int,int>mpp;

        while(r<n){
            mpp[fruits[r]]++;
            while(l<=r && mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }