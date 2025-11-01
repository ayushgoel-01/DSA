class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            int val = curr -> val;
            if(st.count(val) >= 1){
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return dummy -> next;
    }
};