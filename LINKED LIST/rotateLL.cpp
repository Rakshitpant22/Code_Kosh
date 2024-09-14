//! Given the head of a linked list, rotate the list to the right by k places.
ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)return head;
        ListNode* curr= head;
        int len=1;
        while(curr->next){
            curr=curr->next;
            len++;
        }
        curr->next=head;
        
        k=k%len;
        for(int i=0;i<len-k;i++){
            curr=curr->next;
        }

        head=curr->next;
        curr->next=NULL;

        return head;

    }