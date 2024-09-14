//! INSERT Node in BST --> will always be at some leaf 

    // Recursive
      TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(!root)return new TreeNode(x);
        else if(root->val<x) root->right=insertIntoBST(root->right,x);
        else root->left=insertIntoBST(root->left,x);
        return root;
      }
       
   // Iterative
TreeNode* insertIntoBST(TreeNode* root, int x) {
        TreeNode* curr = root;
        while(true){
            if(curr->val<x){
                if(curr->right)curr=curr->right;
                else {
                curr->right=new TreeNode(x);
                break;
                }
            }
            else if(curr->val>x){
                if(curr->left)curr=curr->left;

                else{
                curr->left=new TreeNode(x);
                break;
                } 
            }
        }
        return root;
    }

//! DELETE Node in BST of value==x
// In deletion we simply first find the node with value x;(to be deleted);
  // Case1= if(node->left==NULL) then we simple return root->right;
  // Case2= if(node->right==NULL) then we simple return root->left; 
  // Case3= if(have both left and right)--> in this case we have to find INORDER SUCCESOR of x then replace them and then 

int get_successor(TreeNode* root, int x){
    root=root->right;
    int succ=root->val;
    while(root->left){
        root=root->left;
        succ=root->val;
    }
    return succ;
}
    TreeNode* deleteNode(TreeNode* root, int x) {
        if(!root)return root;

        if(root->val<x){
            root->right=deleteNode(root->right,x);
        }
        else if(root->val>x){
            root->left=deleteNode(root->left,x);
        }
        else{ // found the node with key=x
            if(!root->right){
                return root->left;
            }
            else if(!root->left){
                return root->right;
            }
            else{
                root->val=get_successor(root,x);
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }