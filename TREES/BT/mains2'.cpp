 //! Children sum Property
 bool solve(Node *root){
    if(!root || !root->left && !root->right)return 1;
    if(root->left && root->right && (root->left->data + root->right->data)!=root->data ||
       root->left && !root->right && root->left->data!=root->data||
       root->right&& !root->left  && root->right->data!=root->data){
           return 0;
       }
       
       return solve(root->left) && solve(root->right);
    }
    int isSumProperty(Node *root)
    {
     return solve(root);
    }

//! Maximum width of binary tree
typedef unsigned long long ll;
        if(!root) return 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll maxWidth = 0;
        
        while(!q.empty()) {
            int size = q.size();
            ll f = q.front().second;
            ll l = q.back().second;
            maxWidth = max(maxWidth, l-f+1);
            
            for(int i=0;i<size;i) {
                TreeNode* curr = q.front().first;
                ll d = q.front().second;
                q.pop();
                if(curr->left) {
                    q.push({curr->left, 2*d+1});
                }
                if(curr->right) {
                    q.push({curr->right, 2*d+2});
                }
            }
        }
        return maxWidth;


//! Maximum path sum
 int maxsum;
 int solve(TreeNode* root){
    if(!root)return 0;
    int l=solve(root->left);
    int r=solve(root->right);

    int below_ans= l+r+root->val;//(1)
    int better_ans=max(l,r)+root->val;//(2)
    int only_root= root->val;//(3)

    maxsum=max(maxsum,max(below_ans,max(better_ans,only_root)));
// return hum sirf (2) ya (3) explore kr skte ha (1) case m or explore ni ho skta;
   return max(better_ans,only_root);
 }

    int maxPathSum(TreeNode* root) {
        maxsum=-1e9;
        solve(root);
        return maxsum;
    }