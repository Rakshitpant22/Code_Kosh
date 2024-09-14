//!  Find kth smallest/largest element in BST;

//  As bst inorder traversal gives sorted list
  // brute force -> store inorder in vector then  kth_smallest=inorder[k-1] && Kth_largest=inorder[n-k-1] element
  // beter we can use cnt variable and if cnt== k return that 
     //! for smallest we go left ,root,right
     //! for largest we go right ,root,left

//^ kth smallest 

void solve(TreeNode* root, int k,int &ans,int &cnt){
    if(!root)return;
    solve(root->left,k,ans,cnt);
    cnt++; 
    if(k==cnt){
        ans=root->val;
        return;
    }
    solve(root->right,k,ans,cnt);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1,cnt=0;
        solve(root,k,ans,cnt);
        return ans;
    }

//optimal
 int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int ans=-1;
        int cnt=1;

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
               if(cnt==k){
                ans= curr->val;
                break;
               }
               cnt++;
               curr=curr->right;
            }
        }
        return ans;
    }

//^ kth largest
void solve(TreeNode* root, int k,int &ans,int &cnt){
    if(!root)return;
    solve(root->right,k,ans,cnt);
    cnt++; 
    if(k==cnt){
        ans=root->val;
        return;
    }
    solve(root->left,k,ans,cnt);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1,cnt=0;
        solve(root,k,ans,cnt);
        return ans;
    }
