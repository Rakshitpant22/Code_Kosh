//! max_Height of BT
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l= maxDepth(root->left);    // root kleft jao 
        int r= maxDepth(root->right);   // for right me jao
        return 1 + max(l,r);
    }
};

//! DIAMETER OF TREE:
int dfs(TreeNode* root,int& maxi){
    if(root==NULL){
        return 0;
    }
    int l= dfs(root->left,maxi);
    int r= dfs(root->right,maxi);
    maxi = max(maxi,l+r);
    return  1+max(l,r);

}
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi=0;
       dfs(root,maxi);
       return maxi;
    }
  
//! LCA OF BT
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        
        if(root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
//! LCA OF BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        
       if(root->val < p->val &&   q->val > root->val){
           return  lowestCommonAncestor(root->right,p,q);
       }
       if(root->val > p->val && q->val < root->val){
          return lowestCommonAncestor(root->left,p,q);
          }
         
         return root;  // agr dono if na satisfy ho mtlb p,q left,right m h to lca hmesha parent node hoga
    }
};

//! SAME TREE
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL && q!=NULL||q==NULL && p!=NULL||p->val!=q->val)return false;
         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }

//! balanced Binary tree  -  if(abs(left subtree HEIGHT - Right subtree hieght)<=1) 
int hieght(TreeNode* root){
    if(!root)return 0;
    int l= hieght(root->left);
    int r= hieght(root->right);
    return 1+max(l,r);
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(abs(hieght(root->left)-hieght(root->right))>1)return 0;
        return isBalanced(root->left)&& isBalanced(root->right);
    }
        bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }

//!  CNT total nodes in tree
  int countNodes(TreeNode* root) {
        if(!root)return 0;
        int l= countNodes(root->left);
        int r= countNodes(root->right);
        return 1+l+r;
    }

// less than o(n)time if left h=right h then we return 2^hieght -1 nodes -->this is property of complete binary tree;
// Height Calculation: O(log n) for both left and right heights.
// Node Counting: O(log² n) for the recursive counting.

int lhieght(TreeNode* root){
int h=0;
while(root){
    h++;
    root=root->left;
}
return h;
}
int rhieght(TreeNode* root){
int h=0;
while(root){
    h++;
    root=root->right;
}
return h;
}
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int l=lhieght(root);
        int r=rhieght(root);
        if(l==r){
            return pow(2,l)-1;
        }
        return 1+ countNodes(root->left)+countNodes(root->right);
    }