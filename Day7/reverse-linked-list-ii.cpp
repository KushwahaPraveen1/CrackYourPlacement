class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre_left = dummy;
        for (int i = 1; i < left; ++i) {
            pre_left = pre_left->next;
        }
        
        ListNode* pre = pre_left->next;
        ListNode* cur = pre->next;
        for (int i = left; i < right; ++i) {
            pre->next = cur->next;
            cur->next = pre_left->next;
            pre_left->next = cur;
            cur = pre->next;
        }
        
        return dummy->next;
    }
};