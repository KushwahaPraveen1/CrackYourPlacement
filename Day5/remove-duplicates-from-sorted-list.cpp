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
    ListNode* deleteDuplicates(ListNode* head) {
         if (!head) return nullptr;

        set<int> st;
        ListNode* temp = head;

        while (temp != nullptr) {
            st.insert(temp->val);
            temp = temp->next;
        }

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        for (auto itr = st.begin(); itr != st.end(); itr++) {
            ListNode* newNode = new ListNode(*itr);
            if (newHead == nullptr) {
                newHead = newNode;
                tail = newHead;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return newHead;
    }
};