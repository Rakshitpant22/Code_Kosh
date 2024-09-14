
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto root=q.front();
            q.pop();
            if(root==NULL)s+="#,";
            else s+=to_string(root->val)+",";
            if(root){
                q.push(root->left);
                q.push(root->right);
            }
        } 
        cout<<s;
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;

        stringstream s(data);
        string temp;
        getline(s,temp,',');

        TreeNode* ans= new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty()){
            auto root=q.front();
            q.pop();

            getline(s,temp,',');
            if(temp=="#"){
                root->left=NULL;
            }
            else{
                root->left=new TreeNode(stoi(temp));
                q.push(root->left);
            }
             getline(s,temp,',');
             if(temp=="#"){
                root->right=NULL;
            }
            else{
                root->right=new TreeNode(stoi(temp));
                q.push(root->right);
            }

        }
       return ans;
    }