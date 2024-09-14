// To find the maximum number of meetings that can be performed in a meeting room.

//! sort accn to the ending time of the meeting
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
  public:
    int maxMeetings(int n, int start[], int end[]) {
      vector<pair<int,int>>v(n);
      for(int i=0;i<n;i++){
          v[i]={start[i],end[i]};
      }
      sort(v.begin(),v.end(),cmp);
      
      int ans=1;
      int prev=v[0].second;
      
      for(int i=1;i<n;i++){
          if(v[i].first > prev){
          ans++;
          prev=v[i].second;
       }
      }
      return ans;
    }