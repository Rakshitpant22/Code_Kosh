unordered_map<TreeNode*,TreeNode*>parent;
//! pehle undirected tree bna lia for traversing bavk from root to parent
void undirect(TreeNode* root){
if(!root)return ;

if(root->left) parent[root->left]=root;
undirect(root->left);

if(root->right)parent[root->right]=root;
undirect(root->right);
}

//! Apply BFS
void bfs( TreeNode* target, int k,vector<int>&res){
queue<TreeNode*>q;

q.push(target);
unordered_set<int>visited;
visited.insert(target->val);

while(!q.empty()){
  int size=q.size();
  if(k==0)break;

  while(size--){
      TreeNode* node=q.front();
      q.pop();

      if(node->left!=NULL && !visited.count(node->left->val)){
      q.push(node->left);
      visited.insert(node->left->val);
      }

      if(node->right!=NULL &&!visited.count(node->right->val)){
      q.push(node->right);
      visited.insert(node->right-> val);
      }

      if(parent.count(node) && !visited.count(parent[node]->val)){
      q.push(parent[node]);
       visited.insert(parent[node]->val);
      }
    }
    k--;
  }
  while(!q.empty()){
      auto root= q.front();
      res.push_back(root->val);
      q.pop();
  }
}
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      undirect(root);
      vector<int>res;
      bfs(target,k,res);
      return res;
    }