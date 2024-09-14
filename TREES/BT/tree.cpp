#include<iostream>
using namespace std;
struct Node
{
   int data;
   struct Node*left;
   struct Node*right;

   Node(int value)
   { 
    value = data;
    left=right=NULL;
   }

void preorderTraversal(Node* root) {
          if(root==NULL)
          return ;
           cout<<(root->data);
           preorder(root->left);
           preorder(root->right);
    }
};
int main()
{
    struct Node* root= new Node(4);
    root->left= new Node(7);
    root->left= new Node(17);
    cout<<node->data;

    preorderTraversal(root);
  return 0;
}