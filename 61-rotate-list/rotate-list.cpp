class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head, *next = NULL;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

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

        ListNode* nh = reverse(head);
        ListNode* tmp = nh;

        int cnt = 1;
        while(cnt < k){
            tmp = tmp -> next;
            cnt++;
        }

        ListNode* nh2 = NULL;
        if(tmp -> next) nh2 = tmp -> next;

        tmp -> next = NULL;

        ListNode* head1 = reverse(nh);
        ListNode* head2 = reverse(nh2);

        tmp = head1;
        while(tmp -> next){
            tmp = tmp -> next;
        }
        tmp -> next = head2;
        return head1;
    }
};