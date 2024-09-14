//! make bst from sorted List 
class Solution {
public:
// intuition -> we find middle of ll which is pointed by slow ptr;
// left subtree contains all nodes to left of slow and right subtree conatains   slow->next;
// for left subtree slow-1 ptr will be left for this we need pt which is one step behind slow pointer since fr each subproblem slow becomes root node;

 TreeNode* solve(ListNode* head){
   if(!head)return NULL;
   if(!head->next)return new TreeNode(head->val);

   ListNode* slow=head;
   ListNode* fast=head;
   ListNode* slow_prev=NULL;

   while(fast->next){
    slow_prev=slow;
    slow=slow->next;
    fast=fast->next;
       if(fast->next){
       fast= fast->next;
       }
   }

    TreeNode* root= new TreeNode(slow->val);
    slow_prev->next=NULL;

    root->left=solve(head);
    root->right=solve(slow->next);

    return root;
   
 }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};

//! make bst from sorted array 
TreeNode* solve(int start,int end,vector<int>& nums){
        if(start>end)return NULL;
        int mid= (start+end)/2;
        TreeNode* root= new TreeNode(nums[mid]);

        root->left= solve(start,mid-1,nums);
        root->right=solve(mid+1,end,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }