//!  Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;

        int carry=0;
        while(carry || l1 || l2){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* newnode= new ListNode(sum%10);
            carry=sum/10;
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }


//! ADD 1 TO END OF LL 
Node* reverse(Node* head){
         Node* prev=NULL;
         Node* curr=head;
         while(curr){
         Node* forw=curr->next;
         curr->next=prev;
         prev=curr;
         curr=forw;
         }
         return prev;
     }

    Node* addOne(Node* head) {

    Node* l1=reverse(head);
    Node*curr=l1;
    Node*prev=NULL;

    int carry=1;//intially carry =1 for 1 to add
    
    while(curr){
       int sum = curr->data+ carry;
       curr->data= sum%10;
       carry=sum/10;
       prev=curr;
       curr=curr->next;
    }
    if(carry){
        prev->next=new Node(carry);
    }
     return reverse(l1);
    }