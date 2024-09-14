https://leetcode.com/problems/longest-repeating-character-replacement/description/

int characterReplacement(string s, int k) {
        int l=0,r=0,ans=0,maxi=0,n=s.size();
        unordered_map<char,int>mpp;

        while(r<n){
            mpp[s[r]]++;
            maxi=max(maxi,mpp[s[r]]);//keeps track of most freq element 
            while(l<=r && ((r-l+1)-maxi)>k){  //((r-l+1)-maxi)>k  ==> if (current window length - most_freq_char)= remaing char that are not freq 
            //we have to change these much to mostfreqchar so it must be < k;
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
}

//! O(26*n)== O(n)
int characterReplacement(string s, int k) {
    int n = s.size();
    int ans = 0;
    // Iterate over all possible target characters ('A' to 'Z')
    for (char target = 'A'; target <= 'Z'; target++) {
        int l = 0, r = 0, cnt = 0;

        while (r < n) {
            // If the current character is not the target, increment cnt
            if (s[r] != target) cnt++;

            // If the count of different characters exceeds k, shrink the window
            while (cnt > k) {
                if (s[l] != target) cnt--;
                l++;
            }

            // Calculate the maximum length of the valid window
            ans = std::max(ans, r - l + 1);
            r++;
        }
    }

    return ans;
}