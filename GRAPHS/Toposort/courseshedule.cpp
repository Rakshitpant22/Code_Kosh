
/* QUESTION: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
/* 
^You are given an array prerequisites where prerequisites[i] = [ai,bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

//! ek yehi question same but [ai, bi] indicates that you must take course ai first if u want to take course bi
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites ) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
		// yaha hum link bna rhe ha taki fir hum kahn lga sake
            adj[it[1]].push_back(it[0]);  //! uske lie adj[it[0]].push_back(it[1]) krdenge
        }
		
         vector<int>indegree(numCourses);
	    for(int i=0;i<numCourses;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<numCourses;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int>ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	   if(ans.size()== numCourses)return true;
       return false;
	   
    }