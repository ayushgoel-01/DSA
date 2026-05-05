class Solution {
private:
    int getLen(ListNode* head){
        int ans = 0;
        ListNode* ptr = head;
        while(ptr){
            ans++;
            ptr = ptr -> next;
        }
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        int len = getLen(head);
        k = k % len;
        if(k == 0) return head;

        ListNode* head2 = head;
        int cnt = 0;
        while(head2 && cnt < len-k-1){
            cnt++;
            head2 = head2 -> next;
        }

        if(head2 -> next == NULL) return head;
        

        ListNode* newHead = head2 -> next;
        head2 -> next = NULL;

        ListNode* temp = newHead;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = head;
        return newHead;
    }
};