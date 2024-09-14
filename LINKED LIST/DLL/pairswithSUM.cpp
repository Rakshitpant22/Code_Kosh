//! Find pairs with given sum in doubly linked list
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
       vector<pair<int,int>>ans;
       Node * curr=head;
       while(curr->next){
           curr=curr->next;
       }
      Node * i=head;
      Node * j=curr;
      
      while(i!=j){
          if(i->data+j->data==target){
              ans.push_back({i->data,j->data});
          }
          if(i->data+j->data>target){
              j=j->prev;
          }
          else{
             i=i->next;
          }
      }
      return ans;

    }
