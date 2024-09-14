 // WORKS ON directed edge // for undorected make to edges -> & <-
 // if we relax v-1 edges then we get our shortest path
 vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int>distance(n,1e8);
        distance[S]=0; // S = source
        for(int i=0;i<n-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v =it[1];
                int wt =it[2];
                if(distance[u]+wt<distance[v] && distance[u]!=1e8){
                    distance[v]=distance[u]+wt;
                }
            }
        }
        
        // Nth iteration; agr ek or iteration n-1 k bad chli or if condition shi mili mtlb yaha negative cycle hai  return -1;
        //! kyuki non negative cycled graph k lie N-1 iteration (max) me dist[] me shortest path store ho jana chahie
       for(auto it: edges){
           int u = it[0];               
           int v =it[1];                
           int wt =it[2]; 
        if(distance[u]+wt<distance[v] && distance[u]!=1e8){
                  return {-1};
                }
       }
        return distance;
    }