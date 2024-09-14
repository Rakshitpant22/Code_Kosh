
class Solution {
    private:
    bool detect(int src, vector<int>adj[],int vis[]){
        vis[src]=1;
        queue< pair<int,int>>q;    // pair< value of node, konse order ka node hai >>q
        q.push({src,-1});       // pehle vale k lie parent -1 define krdia.
        
        while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;     
                q.push({it,node});
            }
            else if(parent != it){
                return true;
            }
          }
        }
        return false;
}
        
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
          int vis[V]={0};
         for(int i=0;i<V;i++){
             if(!vis[i]){
              if(detect(i,adj,vis)) return true;
             }
         }
         return false;
         
    }
};
