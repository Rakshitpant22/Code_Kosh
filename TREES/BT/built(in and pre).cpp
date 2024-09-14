//!  from INORDER AND PREORDER
public:
int preindex=0;
TreeNode* build(vector<int>& preorder, vector<int>& inorder,int instart,int inend){
    if(instart>inend)return NULL;
     TreeNode* root= new TreeNode(preorder[preindex]);
     preindex++;

     int i=instart;
     for(;i<=inend;i++){
         if(inorder[i]==root->val){
             break;
         }
     }
         root->left= build(preorder,inorder,instart,i-1);
         root->right=build(preorder,inorder,i+1,inend);

         return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return build(preorder,inorder,0,n-1);
      
    }

// !from INORDER AND POSTORDER

public:
 TreeNode* built(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int poststart,int postend){
     if(instart>inend) return NULL;
     
     TreeNode* root= new TreeNode(postorder[postend]);
            int i=instart;
              for(; i<=inend; i++) {
            if(inorder[i] == root->val) {
                break;
            }
        }
         int leftsize= i-instart;
         int rightsize= inend-i;
     
   root->left= built(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1);
   root->right= built(inorder,postorder,i+1,inend,postend-rightsize,postend-1);
     return root;

 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
       return built(inorder,postorder,0,n-1,0,n-1);

    }