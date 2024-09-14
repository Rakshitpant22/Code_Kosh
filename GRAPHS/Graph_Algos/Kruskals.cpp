
class Solution {   
public:
	vector<int>parent,rank;
    int find(int x){
    if(x==parent[x])return x;

    return parent[x]=find(parent[x]);
    }
    
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent!=y_parent){
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
              parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
}
    int spanningTree(int n, vector<vector<int>> v[])
    {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(auto it:v[i]){
                ans.push_back({i,it[0],it[1]});
            }
        }
        // catch: min weight se start krte jao or union krte jao (ans min cost hi aegaa)
        sort(ans.begin(),ans.end(),[&](auto &a,auto &b){
            return a[2]<b[2];
        });
        
        int sum=0;
        for(auto it:ans){
            if(find(it[0])!=find(it[1])){
                Union(it[0],it[1]);
                sum+=it[2];
            }
            else continue;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
