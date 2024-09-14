class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      vector<int>distance(V);
      
      for(int i=0;i<V;i++)distance[i]=1e9; // sabhi ko max value assign krdi
      
      distance[S]= 0;    //S =SOURCE NODE
      pq.push({0,S});
      
      while(!pq.empty()){
          int dis = pq.top().first ;
          int node= pq.top().second;
          pq.pop();
          
          for(auto it: adj[node]){ // node --->it ka link h
              int adjnode=it[0];
              int edgewt= it[1];
              if(dis + edgewt < distance[adjnode]){
                  distance[adjnode]= dis+edgewt;
                  pq.push({dis+edgewt,adjnode});  
              }
          }
      }
      return distance;
    }
};


