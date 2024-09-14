//^  PREORDER
void rec(Treenode* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    ans.push_back(root->val);
    rec(root->left,ans);
    rec(root->right,ans);
}
 vector<int> preorderTraversal(TreeNode* root){
        vector<int>ans;
        rec(root,ans);
        return ans;
    }
//! Iterative
 vector<int> preorderTraversal(TreeNode* root) {
stack<TreeNode*>st;
vector<int>ans;
if(root==NULL)return ans;
st.push(root);
while(!st.empty()){
    auto root= st.top();
    st.pop();
    ans.push_back(root->val);
    if(root->right!=NULL){
        st.push(root->right);
    }
    if(root->left!=NULL){
        st.push(root->left);
    }
}
return ans;
}
//! Morris
// same as flatten linked list + store in vector 
 TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        vector<int>ans;
        while(root){
            ans.push_back(root->val);
            root=root->right;
        }
        return ans;





//^  INORDER

//!  Iterative
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*>st;
    vector<int>ans;
    if(root==NULL)return ans;

    while(true){
    if(root!=NULL){
     st.push(root);
     root=root->left;
    }
        else
            if(st.empty()==true)break;
            auto root=st.top();
            st.pop();
            ans.push_back(root->val);  
            root=root->right;
              }
        }
    return ans;

//!  Morris  
  TreeNode* curr=root;
        vector<int>ans;

        while(curr){
            if(curr->left){
                TreeNode* prev=curr->left;
                TreeNode* temp=prev;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr;
                curr->left=NULL;
                curr=temp;
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;





//^ POSTORDER

//! Iterative 
 //2 stacks 
vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        if(root==NULL)return ans;
        st1.push(root);
        while(!st1.empty()){
            auto root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->right!=NULL){
                st1.push(root->right);
            }
            if(root->left!=NULL){
                st1.push(root->left);
            }
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
//1 stack
     stack<TreeNode*>st;
        vector<int>ans;
        if(!root)return ans;
        st.push(root);

        while(!st.empty()){
            auto root=st.top();
            st.pop();
            ans.push_back(root->val);

            if(root->left){
                st.push(root->left);
            }
            if(root->right){
                st.push(root->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;




//^ LEVEL ORDER TRAVERSAL

  vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>ans;  // answer store krega 
      if(root==NULL)  return ans;
      queue< TreeNode*>q;
      q.push(root);
          while(!q.empty()){
              int size= q.size();
              vector<int>level;
              while(size--){
                  TreeNode *node = q.front() ;
                  q.pop();
                  if(node->left!=NULL) q.push(node->left);
                  if(node->right!=NULL) q.push(node->right);
                  level.push_back(node->val);
                }
                ans.push_back(level);
          }
    }



//^ VERTICAL ORDER TRAVERSAL

vector<vector<int>> verticalTraversal(TreeNode* root) {
     //!  map< VERTICAL,map< LEVEL,mutiset<node_values;
     //^ mutiset is used instead of set bcs tree can have duplicate values also:

     //! queue<pair<ROOT,pair<X,Y>>>q;

        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* node= p.first;
            int x=p.second.first; //! vertical location
            int y=p.second.second;//! horizontal location
            nodes[x][y].insert(node->val);

            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto it: nodes){
            vector<int>col;
            for(auto q:it.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }



//^ ALL IN ONE TRAVERSAL 
void allTraversal(TreeNode* root,vector<int>&pre, vector<int>&in,vector <int>&post){
  stack <pair<TreeNode*,int>>st;
  st.push({root,1});
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({it.first -> left,1});
      }
    }
    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({it.first ->right,1});
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}

