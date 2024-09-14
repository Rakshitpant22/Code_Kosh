https://www.geeksforgeeks.org/problems/minimum-window-subsequence/0


bool check(int l,int r,string s1, string s2){
      int i=l,j=0;
      while(i<=r && j<s2.size()){
          if(s1[i]==s2[j]){
              i++;
              j++;
          }
         i++;
      }
      return j==s2.size();
  }
    string minWindow(string s1, string s2) {
    
    
        int l=0,r=0,n=s1.size(),m=s2.size(),start_idx=-1,ans=n+1;
         
        while(r<n){
         while(l<=r && check(l,r,s1,s2)){
             if(ans>r-l+1){
                 ans=r-l+1;
                 start_idx=l;
             }
             l++;
         }       
         r++;
        }
        return ans==n+1 ? "":s1.substr(start_idx,ans);
    }