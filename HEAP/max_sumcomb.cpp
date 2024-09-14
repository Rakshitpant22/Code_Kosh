vector<int>solve(vector<int> &a, vector<int> &b, int c) {
    int n=a.size();
    vector<int>ans;
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());  // for min sort in increasing order
    
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;
    
    pq.push({a[0]+b[0],{0,0}});
    s.insert({0,0});
    
    while(c--){
        int res=pq.top().first;
        ans.push_back(res);
        int i= pq.top().second.first;
        int j= pq.top().second.second;
        pq.pop();
        
        if(!s.count({i+1,j})){
            pq.push({a[i+1]+b[j],{i+1,j}});
            s.insert({i+1,j});
        }
        if(!s.count({i,j+1})){
            pq.push({a[i]+b[j+1],{i,j+1}});
            s.insert({i,j+1});
        }
    
    }
    return ans;
}
