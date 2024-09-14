class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     // sabse pehle graph bna lo problem ka
      vector<pair<int,int>>adj[n];
      for(auto it: flights){// i--->it
          adj[it[0]].push_back({it[1],it[2]});
      }


       queue<pair<int,pair<int ,int>>>q; //{stops,{source,cost}}
       q.push({0,{src,0}});
       vector<int>distance(n,1e9); // pehle sabko max vale assign krdo distance[] me and src ko =0 value dedo
       distance[src]=0;

       while(!q.empty()){
           auto it = q.front();
           int stops = it.first;
           int node = it.second.first;
           int cost = it.second.second;
           q.pop();

           if(stops>k)continue; //age jane ki jarurt hi nhi hai 

           for(auto it: adj[node]){
               int adjnode = it.first
               int edgewt = it.second;
               if(cost+edgewt < distance[adjnode] && stops<=k){
                   distance[adjnode]=edgewt+cost;
                   q.push({stops+1,{adjnode,cost+edgewt}}); //stops bdhado and {adj node ,min  cost jo aegi } use pass krvado
               }
           }
       }
       if(distance[dst]==1e9)return -1;// dstn not reached;
       return distance[dst];
    }
};