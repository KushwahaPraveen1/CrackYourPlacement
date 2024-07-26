/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            if (tempA == nullptr)
                tempA = headA;
            else
                tempA = tempA->next; 
            if (tempB == nullptr)
                tempB = headB;
            else
                tempB = tempB->next;
        }
        return tempA;
    }
};