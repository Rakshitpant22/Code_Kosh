//! TC= O(N) AND SC=O(N)
class BSTIterator {
public:
vector<int>inorder;
int i=-1;
    BSTIterator(TreeNode* root) {
        TreeNode* curr=root;
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
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    
    int next() {
        i++;
        return inorder[i];
    }
    
    bool hasNext() {
        if(i==inorder.size()-1)return 0;
        return 1;
    }
};

//! Optimal : TC=O(N) && SC=O(H)
class BSTIterator {
public:
stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
    // Insert only left boundary 
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    int next() {
        TreeNode* root=st.top();
        int x=root->val;
        st.pop();

        root=root->right;  // ek right jaake for left boundary explore kri
        while(root){
            st.push(root);
            root=root->left;
        }
        return x;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
