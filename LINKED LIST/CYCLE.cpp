//! DETECT CYCLE STARTING POINT 
ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return NULL;

        ListNode *slow=head;
        ListNode *fast=head->next;
        
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
            if(slow==fast){ //CYCLE DETECTED - BREAK LOOP
                break;
            }
            if(fast->next)fast=fast->next;
        }

     //if cycle is detected
        if(slow==fast){
    //move one pointer to start and move both ptrs 1 step unitl they again meet
           slow=head; 
           while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
           }
           return slow;
        }
        return NULL;
}

//! COUNT LENGTH OF LOOP / CYCLE IN LL
 int countNodesinLoop(Node *head) {
     if(!head|| !head->next)return 0;

        Node *slow=head;
        Node *fast=head->next;
        
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
            if(slow==fast){ //CYCLE DETECTED - BREAK LOOP
                break;
            }
            if(fast->next)fast=fast->next;
        }
     //if cycle is detected
      Node *start=NULL;
        if(slow==fast){
    //move one pointer to start and move both ptrs 1 step unitl they again meet
           slow=head; 
           while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
           }
           start= slow;
        }
        if(start==NULL)return 0;
        
        int cnt=1;
        Node *curr=start->next;
        while(curr!=start){
            curr=curr->next;
            cnt++;
        }
        return cnt;
    }

//! FIND DUPLICATE NUMBER
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

https://leetcode.com/problems/find-the-duplicate-number/
 int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        slow=nums[slow];
        fast=nums[nums[fast]];

        while(fast!=slow){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }