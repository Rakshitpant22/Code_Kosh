//! reverse ll
ListNode* reverseList(ListNode* head) {

        if(!head||!head->next)return head;
        ListNode* nextnode=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return nextnode;
         // ListNode* prev=NULL;
        // ListNode* curr=head;
        // while(curr){
        //     ListNode* forw=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=forw;
        // }
        // return prev;
       
    }

//! middle of ll
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

 ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast->next){
               fast=fast->next;
            }
        }
        return slow;
    }


//! Delete the Middle Node of a Linked List
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

 ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        ListNode* slow=head;
        ListNode* fast=head; 
        ListNode* prev=head; //^ is ptr ka use krenge to remove middle (just before middle)

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        prev->next=prev->next->next;
        slow->next=NULL;
        delete slow;

        return head;
    }