 bool f(int i,string s, unordered_set<string>&st,int n){
        if(i==n)return true;
        if(st.find(s)!=st.end())return true;
       
         for(int size=1;size<n;size++){
            string temp=s.substr(i,size);
            if(st.find(temp)!=st.end() && f(i+size,s,st,n)){
                return true;
            }

         }
         return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return f(0,s,st,n,dp);
        
    }

// Tabulation:

    bool wordBreak(string s, vector<string>& wordDict) {

        int n= s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=1;j<i;j++){
                temp=s.substr(i,j);
                if(st.find(temp)!=st.end() && st.find(temp))return dp[i]=true;
            }
        } 
    }

