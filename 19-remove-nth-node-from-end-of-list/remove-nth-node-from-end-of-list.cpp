class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next) return NULL;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* temp1 = dummy, *temp2 = dummy;

        for(int i=0; i<n; i++){
            temp2 = temp2 -> next;
        }

        while(temp2 && temp2 -> next){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        temp1 -> next = temp1 -> next -> next;
        return dummy -> next;
    }
};