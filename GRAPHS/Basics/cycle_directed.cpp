class Solution {
    private:
    bool dfs(int node,int V, int vis[],int pathvis[],vector<int> adj[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if ((dfs(it,V,vis,pathvis,adj))==true)return true;
            }
            
            // if node has been prev visited.But it has to be visited on same path.mtlb cycle hai .
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
      
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       int vis[V] ={0};
       int pathvis[V]={0};
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfs(i,V,vis,pathvis,adj)==true)return true;
           }
       }
       return false;
    }
};

