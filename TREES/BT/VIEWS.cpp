 //^ RIGHT VIEW  ---  LEFT VIEW 
 //RIGHT LEFT VIEW CAN ALSO BE DONE BY LEVEL ORDER TRAVERSAL 
  vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if(root==NULL)return res;
     
        q.push(root);
          while(!q.empty()){
              int size= q.size();
              TreeNode *node=NULL;
              for(int i=0;i<size;i++){
                  node = q.front() ;
                  q.pop();
                  if(node->left!=NULL) q.push(node->left);
                  if(node->right!=NULL) q.push(node->right);
                }
                res.push_back(node->val); //LAST NODE KO HI DALEGA 
          }

        return res;

//RECURSION
 void solve(Node *root,int level, vector<int>&res){
        if(!root)return ;
        if(level==res.size()){
            res.push_back(root->data); 
        }                   
        //FOR RIGHT VIEW                   // FOR LEFT VIEW
        solve(root->right,level+1,res);    solve(root->left,level+1,res);   
        solve(root->left,level+1,res);     solve(root->right,level+1,res);   
    }
    vector<int> rightView(Node *root)
    {
       vector<int>res;
       solve(root,0,res);
       return res;
    }

 //^ TOP VIEW 
 //! Vertical line m jo pehla elemnt h vo top view m aega 
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            Node* node=it.first;
            int vertical_position=it.second;
            if(mpp.find(vertical_position)==mpp.end()){//! agr 1st occuring h tabhi map p dalna ha for 1st in a line 
                mpp[vertical_position]=node->data;
            }
            if(node->left)q.push({node->left,vertical_position-1});
            if(node->right)q.push({node->right,vertical_position+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

//^ BOTTOM VIEW
//! bottom view k lie bs vertical line m last element ko lena h 
vector<int>ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            Node* node=it.first;
            int vertical_position=it.second;
            //!update krte jao last m updated vala last hi hoga 
                mpp[vertical_position]=node->data;
           
            if(node->left)q.push({node->left,vertical_position-1});
            if(node->right)q.push({node->right,vertical_position+1});
            
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;

//^ BOUNDARY ORDER TRAVERSAL
  //! LEFT ---> LEAF NODES ---> RIGHT (reverse)

  bool isleafnode(Node *root){
      if(!root->left && !root->right)return 1;
      return 0;
  }
 void add_leaves(Node *root,vector<int>&res){
        if(isleafnode(root)){
            res.push_back(root->data);
        }
        if(root->left!=NULL) add_leaves(root->left,res);
        if(root->right!=NULL) add_leaves(root->right,res);
    }
    void left_nodes(Node *root,vector<int>&res){
       Node*curr= root->left;
       while(curr){
           if(!isleafnode(curr))res.push_back(curr->data);
           if(curr->left)curr=curr->left;
           else curr= curr->right;
       }
    }
    
    void right_nodes(Node *root,vector<int>&res){
        Node* curr=root->right;
        vector<int>temp;
        while(curr){
            if(!isleafnode(curr))temp.push_back(curr->data);
            if(curr->right)curr=curr->right;
            else curr=curr->left;
        }
       for(int i=temp.size()-1;i>=0;i--){
           res.push_back(temp[i]);
       }
    
    } 
public:
    vector <int> boundary(Node *root)
    {
       vector<int>res;
       if(root==NULL)return res;
       if(!isleafnode(root)) res.push_back(root->data);
       left_nodes(root,res);
       add_leaves(root,res);
       right_nodes(root,res);
       return res;
    }
       