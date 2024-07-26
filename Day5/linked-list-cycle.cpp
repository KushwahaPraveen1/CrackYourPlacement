/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==nullptr)
        return 0;
      while (fast != nullptr && fast->next != nullptr) 
        {
fast=fast->next->next;
slow=slow->next;
if(fast==slow)
return 1;
        }
        return 0;
    }
};