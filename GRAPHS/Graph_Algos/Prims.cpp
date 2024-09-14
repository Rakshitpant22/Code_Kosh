 //!Here adj[i] of size 2, where the first denotes the end of the edge and the second  denotes the edge weight.

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //{wt,node}
        
        pq.push({0,0});// hume edwt ka sum. s mtlb hai islea parent ko heap m carry nhi kr rhe;
        int sum=0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int node= it.second;
            int wt= it.first;
            
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int adjnode= it[0];
                int edgwt= it[1];
                if(!vis[adjnode]){
                    pq.push({edgwt,adjnode});
                }
            }
        }
        return sum;
    }