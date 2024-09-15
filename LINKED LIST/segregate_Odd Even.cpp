//^ SORT 0,1,2'S IN LL

//! Brute force
 int cnt0=0,cnt1=0,cnt2=0;
      Node*curr=head;
      
      while(curr){
          if(curr->data==0)cnt0++;
          else if(curr->data==1)cnt1++;
          else cnt2++;
          curr=curr->next;
      }
      
         curr=head;
      
          while(cnt0--){
              curr->data=0;
              curr=curr->next;
          } 
          while(cnt1--){
              curr->data=1;
              curr=curr->next;
          }
           while(cnt2--){
              curr->data=2;
              curr=curr->next;
          }
     
      return head;

//! BY CHANGING LINKS 
 Node* segregate(Node* head) {
      Node*dummy0=new Node(-1);
      Node*zero=dummy0;
        
      Node*dummy1=new Node(-1);
      Node*one=dummy1;
      
      Node*dummy2=new Node(-1);
      Node*two=dummy2;
      
       Node*curr=head;
       while(curr){
           if(curr->data==0){
               zero->next=curr;
               zero=zero->next;
           }
           else if(curr->data==1){
               one->next=curr;
               one=one->next;
           }
           else{
               two->next=curr;
               two=two->next;
           }
           curr=curr->next;
       }
       
       zero->next = dummy1->next? dummy1->next: dummy2->next;
       one->next  = dummy2->next;
       two->next  = NULL;
       
       return dummy0->next;
      
    }

//! segregate odd even ll based on index of ll -- > concept same as sort 0,1,2 by changing links
 ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy_odd=new ListNode(0);
        ListNode* odd=dummy_odd;

        ListNode* dummy_even=new ListNode(0);
        ListNode* even=dummy_even;

        int cnt=1;
        ListNode* curr=head;
        while(curr){
            if(cnt%2){//odd 
                odd->next=curr;
                odd=odd->next;
            }
            else {
                even->next=curr;
                even=even->next;
            }
            curr=curr->next;
            cnt++;
        }

        odd->next=dummy_even->next;
        even->next=NULL;

        return dummy_odd->next;
    }

