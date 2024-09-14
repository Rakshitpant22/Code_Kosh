 https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 Given a string s, find the length of the longest substring without repeating characters.

//!O(n^2)
 int lengthOfLongestSubstring(string s) {
        int ans=0,n=s.size();

        for(int i=0;i<n;i++){
            set<char>st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                if(st.size()==j-i+1){
                    ans=max(ans,(int)st.size());
                }
            }
        }
        return ans;
 }

//! Optimal 1
int lengthOfLongestSubstring(string s) {
        int ans=0,n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mpp;

        while(r<n){
            mpp[s[r]]++;
            while(l<=r && mpp.size()!=r-l+1){ //  while(l<=r && mpp[s[r]]>1)
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
           if(mpp.size()==r-l+1) ans=max(ans,r-l+1);
           r++;
        }
        return ans;
    }

//! OPTIMAL 2
    int lengthOfLongestSubstring(const std::string& s) {
    int ans = 0, n = s.size();
    int l = 0, r = 0;
    int freq[128] = {0};  // Array for ASCII characters

    while (r < n) {
        freq[s[r]]++;
        while (freq[s[r]] > 1) {
            freq[s[l]]--;
            l++;
        }
        ans = std::max(ans, r - l + 1);
        r++;
    }
    return ans;
}