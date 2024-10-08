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
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return head;
          
            while (head != nullptr && head->val == val) {
    head = head->next;
}
if(head==nullptr)return head;
        ListNode*prev=head; ListNode*temp=prev->next;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return head;
    }
};