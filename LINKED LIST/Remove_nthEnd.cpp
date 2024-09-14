https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
Given the head of a linked list, remove the nth node from the end of the list and return its head.

//! APPROACH 1 OR  Dummy node approach 

// Find len of ll and traverse ptr upto <(len-n-1) position and make curr->next=curr->next->next;

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n==1)return NULL;
        int len=1;
        ListNode* curr=head;
        while(curr->next){
            len++;
            curr=curr->next;
        }
        
        // Special case: if removing the first node (n == len) BCS  i<len-n-1 k lie i<0 hoga is case ko alag s handle kraa
        // ^ is hum dummy node bnake handle kr skte hai and last m dummy->next return krado but it takes 1 node memory
        if(n==len){
            return head->next;
        }
    
        curr=head;
        for(int i=0;i<len-n-1;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;

        return head;
    }

//! APPROACH 2
ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp=new ListNode(0);
       temp->next=head;
      
        ListNode* slow=temp;
        ListNode* fast=temp;
  
  //PEHLE HI FAST KO N TIMES AAGE BDHA DO AND if(fast->next==NULL) then slow->next ko udana hai
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

       while(fast->next!=NULL){
           fast=fast->next;
           slow=slow->next;
       }
       slow->next=slow->next->next;
       return temp->next;
    }

