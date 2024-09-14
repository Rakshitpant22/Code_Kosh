class Solution{
    public:

    string findOrder(string dict[], int n, int k) {
        vector<vector<int>>adj(k);

        for(int i=0;i<n-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            int idx1=0,idx2=0;
            while(idx1<s1.size() && idx2<s2.size()){
            if(s1[idx1]!=s2[idx2]){
                adj[s1[idx1]-'a'].push_back(s2[idx2]-'a');
                break;
            }
            else{
                idx1++;idx2++;
             }
           }
        }
        
        vector<int> topo=toposort(k,adj);
        string ans="";
        for(auto it:topo){
            ans+=(it+'a');
        }
        //cout<<ans;
        return ans;
        
    }
    
    vector<int> toposort(int V, vector<vector<int>>&adj) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){ //i--->it
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
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
    
}