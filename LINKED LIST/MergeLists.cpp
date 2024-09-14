//! MERGE 2 SORTED LISTS
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode* res=NULL;
        if(l1->val>l2->val){
            res=l2;
            res->next=mergeTwoLists(l1,l2->next);
        }
        else{
            res=l1;
            res->next=mergeTwoLists(l1->next,l2);
        }
        return res;
    }

//! MERGE K SORTED LISTS
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode* res=NULL;
        if(l1->val>l2->val){
            res=l2;
            res->next=mergeTwoLists(l1,l2->next);
        }
        else{
            res=l1;
            res->next=mergeTwoLists(l1->next,l2);
        }
        return res;
    }

ListNode* merge(int start,int end,vector<ListNode*>& lists){
    if(start>end)return NULL;
    if(start==end)return lists[start];
    int mid=start+(end-start)/2;

    ListNode* l1= merge(start,mid,lists);
    ListNode* l2= merge(mid+1,end,lists);

    return mergeTwoLists(l1,l2);

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(0,lists.size()-1,lists);
    }