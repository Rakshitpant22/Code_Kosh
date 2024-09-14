//BRUTE FORCE -> O(n^2);

int height(Node *root){
      if(!root)return 0;
      int l= height(root->left);
      int r= height(root->right);
      return 1+l+r;
  }
  bool valid (Node *root,Node *mini,Node *maxi){
      if(!root)return 1;
      
      if(mini && mini->data>= root->data)return 0;
      if(maxi && maxi->data<= root->data)return 0;
      
      return valid (root->left,mini,root) && valid (root->right,root,maxi);
  }
  
  void solve(Node *root,int &ans){
      if(!root)return ;
    	if(valid(root,NULL,NULL)){
    	    ans=max(ans,height(root));
    	}
    	solve(root->left,ans);
    	solve(root->right,ans);
  }
    int largestBst(Node *root)
    { 
    	int ans=1;
    	solve(root,ans);
    	return ans;
    }

//! Optimised approach

int MAX=INT_MAX;
int MIN=INT_MIN;

class Solution{
public:
class helper{
public:
    int maxi;
    int mini;
    bool isbst;
    int size;
    helper(int mi, int ma, bool isBST, int sz) : mini(mi), maxi(ma), isbst(isBST), size(sz) {}
};

helper solve(Node *root,int &ans){
    if(!root)return {MAX,MIN,true,0};
    
    helper left = solve(root->left,ans);
    helper right= solve(root->right,ans);
    
    helper curr(MAX, MIN, false, left.size + right.size + 1);
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);

    if(left.isbst && right.isbst && root->data > left.maxi && root->data < right.mini) {
            curr.isbst = true;
            ans = max(ans, curr.size);
    }

        return curr;
    
}
    int largestBst(Node *root)
    {   int ans=0;
    	helper res=solve(root,ans);
    	return ans;
    	
    }
};