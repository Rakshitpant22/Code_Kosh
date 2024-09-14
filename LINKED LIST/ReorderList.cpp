https://leetcode.com/problems/reorder-list/?envType=problem-list-v2&envId=linked-list

//! REORDER LIST 
ex Input: head = [1,2,3,4,5]  
         Output: [1,5,2,4,3]
   Input: head = [1,2,3,4]
         Output: [1,4,2,3]   // basically 1 node from start 1 from end 

//~ approach make two linked list one from head and second from middle->next
//~ reverse the second ll (middle->next)
//~ then iteratively merge these 2 LL 

ListNode* reverse_ll(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr){
        ListNode* forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}
    void reorderList(ListNode* head) {
    //! find midlle of linked list
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode* l2=reverse_ll(slow->next);
    slow->next=NULL;

    ListNode* l1=head;
   
   //! merge 2 lists 
    while(l2){
     ListNode* node1=l1->next;
     ListNode* node2=l2->next;

     l1->next=l2;
     l2->next=node1;

     l1=node1;
     l2=node2;
     }
    }