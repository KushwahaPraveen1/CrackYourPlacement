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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
       
         ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1 != nullptr && p2 != nullptr) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }
};