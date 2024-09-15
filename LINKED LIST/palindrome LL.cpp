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
    bool isPalindrome(ListNode* head) {
        if(!head->next)return true;
        if(!head)return false;

        // first find the midle of linked list 
        // here we have to find(length/2) middle /first middle 
        // then reverse ll from (slow->next)
        // put 1 ptr at start/head and second at slow->next/middle next
        // if(ptr1!=ptr2) not palindrome else ptr1++,ptr2++

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev_list=reverse_ll(slow->next);
        
        slow=head;
        fast=rev_list;
        
        while(slow && fast){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }