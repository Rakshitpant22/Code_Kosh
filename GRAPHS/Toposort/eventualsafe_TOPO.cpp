class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>indegree(n);
          vector<int>rev[n];

        // adj ko revrse krdo i-->it originally
        //it->i bna do
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }

        // agr indegree 0 ho jae to q me push krdo
        queue<int>q;
        vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
            q.push(i);
    }
    }

        
         while(!q.empty()){
             int node=q.front();
             q.pop();
             safenodes.push_back(node);
             for(auto it : rev[node]){
                 indegree[it]--;
                 if(indegree[it]==0)q.push(it);
             }
         }
         sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};