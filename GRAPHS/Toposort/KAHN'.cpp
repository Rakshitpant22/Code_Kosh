//! KAHN'S ALGORITHM
//^ TOPOSORT USING BFS/ KAHN'S ALGO
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
    //  Indegree ko bnane k lie 
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){ //i--->it
	            indegree[it]++;
	        }
	    }
	    
    // agr kisi ka indegre[i]==0 h to use q me push krdo
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
// jabtak q empty na ho ---> q me se pop krate jao (or vector m sath sath store krte chlo)--> or agr nikalte hue uski adj me dekho --> or uski indegree -- krdo
// jaha bhi indegree-- krte hue 0 ho jae us indegree[i] ko queue m push krdo.

	    vector<int>ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
                
	        }
	    }
	    return ans;
	   
	}
};

