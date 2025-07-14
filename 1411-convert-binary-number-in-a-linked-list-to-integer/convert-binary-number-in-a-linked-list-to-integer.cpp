/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);

        int ans = 0, base = 1;
        while(temp){
            int val = temp -> val;
            ans = ans + (val * base);
            base *= 2;
            temp = temp -> next;
        }
        return ans;
    }
};