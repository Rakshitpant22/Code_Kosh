#include <iostream>
using namespace std;
void insertionsort(int arr[], int n)
{
    int i, j, k;
    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
}
int main()
{ 
    int arr[] = {6, 20, 12, 2, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);
    printarray(arr, n);
    return 0;
}


void rec(treenode* root){
 if(!root)return ;
 if(!root->left && !root->right){
    root->left =new treenode(root->val);
    root->right=new treenode(root->val);
    return;
 }
  rec(root->left);
  rec(root->right);
}