//! REMOVE DUPLICATES FROM A SORTED DOUBLY LINKED LIST
 Node * removeDuplicates(struct Node *head)
    {
    if (!head || !head->next) return head; 
     
    Node* temp = head;
    Node* curr = head->next;

    while (curr) {
        if (curr->data == temp->data) {
            while (curr && curr->data == temp->data) {
                curr = curr->next;  
            }
            temp->next = curr;
            if (curr) {  // if curr!=NULL
                curr->prev = temp;
            }
        } 
        else {
            temp = curr;
            curr = curr->next;
        }
    }

    return head; 
    }
//! DELETE ALL OCCOURENCES OF X IN LL
Node * deleteAllOccurrences(Node* head, int x) {
    
    if(!head ||!head->next && head->data==x)return NULL;

     Node* dummy=new Node(-1);
        dummy->next=head;
        Node* temp= dummy;
        head->prev=temp;
        
        Node*curr=head;
        while(curr){
            if(curr->data==x){
                while(curr && curr->data==x){
                    curr=curr->next;
                }
                temp->next=curr;
                if(curr)curr->prev=temp;
            }
            else{
                temp=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
}