
class Solution {
    private:
   bool dfs(int node, int parent, vector<int> adj[],int vis[]){
       vis[node]=1;
       for(auto it:adj[node]){
           if(!vis[it]){
               if(dfs(it,node,adj,vis)==true)return true;
           }
           else if(parent!=it)return true;
       }
       return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
           if(dfs(i,-1,adj,vis)==true)
           return true;
        }
    }
    return false;
    }
};


   