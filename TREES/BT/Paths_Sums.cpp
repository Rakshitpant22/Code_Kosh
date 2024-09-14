//! return true if root node to any leaf node has sum== target
bool solve(TreeNode* root, int target){
    if(!root)return 0;
    if(!root->left && !root->right && root->val-target==0)return 1;
    return solve(root->left,target-root->val) || solve(root->right,target-root->val);
    
}
    bool hasPathSum(TreeNode* root, int targetsum) {
        return solve(root,targetsum);

}
//! path sum 2-->
// return all root-to-leaf paths where the sum of the node values in the path equals targetSum.

void solve(TreeNode* root, int target,vector<int>&ds,vector<vector<int>>&ans){
    if(!root)return;
    if(!root->left &&!root->right&& target-root->val==0){
        ds.push_back(root->val);
        ans.push_back(ds);
        ds.pop_back();
        return ;
    }
        ds.push_back(root->val);
        solve(root->left,target-root->val,ds,ans);
        solve(root->right,target-root->val,ds,ans);
        ds.pop_back();
    
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(root,targetSum,ds,ans);
        return ans;
    }
//! path sum 3 -->
//Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along  
//the path equals targetSum.
//The path does not need to start or end at the root or a leaf, but it must go downwards 

long long solve(TreeNode* root,long long sum,int target){
if(!root)return 0;
if(root->val+sum==target)return 1+solve(root->left,sum+root->val,target)
                                 +solve(root->right,sum+root->val,target);
return solve(root->left,sum+root->val,target)+solve(root->right,sum+root->val,target);
}
void allways(TreeNode* root,int target,long long &ans){
    if(!root)return ;
    ans+=solve(root,0,target);
    allways(root->left,target,ans);
    allways(root->right,target,ans);
}
    int pathSum(TreeNode* root, int targetSum) {
        long long ans=0;
        int sum=0;
        allways(root,targetSum,ans);
        return ans;
    }