//!  To insert a new node at given position in doubly linked list. 
https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list
void addNode(Node *head, int pos, int data)
{ //~ Pth node k baad krni h add 
    Node *curr=head;
    while(pos--){
        curr=curr->next;
    }
    
    if( !curr->next){ // INSERT AT THE END OF DLL
        Node *temp= new Node(data);
        curr->next=temp;
        temp->prev=curr;
    }
    else{ 
          Node *temp= new Node(data);
          Node *nextnode=curr->next;
          
          curr->next=temp;
          temp->prev=curr;
          temp->next=nextnode;
          nextnode->prev=temp;
      }
}

 //! Function to delete a node at given position.
 https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list
    
    Node* deleteNode(Node* head, int x) { // 1 BASED INDEXING
       x--;
       Node*curr= head;
       while(x--){
           curr=curr->next;
       }
       if(!curr->prev){//FIRST NODE IS TO BE DELETED
           return curr->next;
       }
       else if(!curr->next){//LAST NODE IS TO BE DELETED
          curr->prev->next=NULL;
          curr->prev=NULL;
       }
      else{
          curr->prev->next=curr->next;
          curr->next->prev=curr->prev;
          curr->next=NULL;
          curr->prev=NULL;
      }
      return head;
    }

    //! Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
       DLLNode* prevnode=NULL;
       DLLNode* curr=head;
       
       while(curr){
        DLLNode* forw= curr->next;
        curr->next=prevnode;
        curr->prev=forw;
        prevnode=curr;
        curr=forw;
       }
       return prevnode;
    }