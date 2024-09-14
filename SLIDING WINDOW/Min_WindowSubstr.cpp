https://leetcode.com/problems/minimum-window-substring/

//! Approach
1. store all the  char , freq  of the string (t) into map 
2. required no of unique char needed will be size of the map
3. traverse string s using sliding window and if char in s found in map decrese its freq , whenever freq of some char ==0 means that char is completed
4. if all char found required==0 then find start idx and min length substr; and reduce window size to find more small substr
5. while shrinking window if s[l]is found in map the inc in required


string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto it:t){
            mpp[it]++;
        }
        int l=0,r=0,n=s.size(),window_size=1e9,start_idx=-1;
        int required= mpp.size(); // unique char req in s
        
        while(r<n){
            if(mpp.count(s[r])){
                mpp[s[r]]--;
                if(mpp[s[r]]==0)required--;
            }

            while(l<=r && required==0){
                if(window_size>r-l+1){
                    window_size=r-l+1;
                    start_idx=l;
                }
                if(mpp.count(s[l])){
                    mpp[s[l]]++;
                    if(mpp[s[l]]>0)required++;
                }
                l++;
            }
            r++;
        }
        return start_idx==-1?"": s.substr(start_idx,window_size);
    }