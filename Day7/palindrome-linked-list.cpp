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
    bool isPalindrome(ListNode* head) {
        
   ListNode *slow_ptr = head; 
    ListNode *fast_ptr = head; 
 
    if (head!=NULL) 
    { 
        while (fast_ptr != NULL && fast_ptr->next != NULL) 
        { 
            fast_ptr = fast_ptr->next->next; 
            slow_ptr = slow_ptr->next; 
        }  
    } if (head == nullptr || head->next == nullptr) 
            return head;

     
        ListNode* prev = nullptr;
        ListNode* curr = slow_ptr;

 while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr; // Move prev pointer one step ahead
            curr = nextTemp; // Move curr pointer one step ahead
        }
  ListNode* first_half = head;
        ListNode* second_half = prev;
        while (first_half != nullptr && second_half != nullptr) {
            if (first_half->val != second_half->val)
                return false;
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return true;
  }
};