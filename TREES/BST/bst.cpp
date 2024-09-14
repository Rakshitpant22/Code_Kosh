//! VALIDATE BST
bool solve(TreeNode* root, TreeNode* mini,TreeNode* maxi){
    if(!root)return 1;
    if(mini && mini->val>= root->val)return 0;
    if(maxi && maxi->val<= root->val)return 0;

    return solve(root->left,mini,root) && solve(root->right,root,maxi);

}
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }

//!  MAKE BST from preorder traversal
// brute force is make inorder and use preorder + inorder to make TREE --> which will be a bst
  TreeNode* solve(int &i,vector<int>& preorder,int upperbound){
   if(i==preorder.size()|| preorder[i]>upperbound)return NULL;

   TreeNode* root= new TreeNode(preorder[i]);
   i++;
   root->left= solve(i,preorder,root->val);
   root->right= solve(i,preorder,upperbound);

   return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0,upperbound=1e9;
        return solve(i,preorder,upperbound);
    }