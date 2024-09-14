https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

//! Number of Substrings Containing All Three Characters

int numberOfSubstrings(string s) {
int l=0,r=0,ans=0,n=s.size();
        unordered_map<char,int>mpp;

        while(r<n){
            mpp[s[r]]++;
            while(l<=r && mpp.size()==3){
    //! agr ek index tak sare char mil gye to usse aage vale sare subarrays bhi ans m included honge;
                ans+=n-r; 
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }

https://leetcode.com/problems/permutation-in-string/description/
//! Permutation in String
 bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp1,mpp2;
        for(auto it:s1){
            mpp1[it]++;
        }
        // kind of fixed length sliding window of len=s1.size();
        int l=0,r=0,n=s2.size(),m=s1.size();
        if(m>n)return false;
        while(m--){
            mpp2[s2[r]]++;
            r++;
        }
        if(mpp1==mpp2)return true;

        while(r<n){
            mpp2[s2[r]]++;
            mpp2[s2[l]]--;
            if(mpp2[s2[l]]==0)mpp2.erase(s2[l]);
            if(mpp1==mpp2)return true;
            r++;
            l++;
        }
        return false;
    }