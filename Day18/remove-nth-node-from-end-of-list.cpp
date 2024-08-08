class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Calculate the length of the list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find the (length-n)th node
        if (length == n) {
            // If removing the head node
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Find the node before the node to be removed
        temp = head;
        for (int i = 1; i < length - n; ++i) {
            temp = temp->next;
        }

        // Remove the nth node from the end
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
