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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        if(list1==nullptr&&list2==nullptr)return nullptr;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        ListNode*ans=new ListNode();
        ListNode*curr=ans;
        while(temp1!=nullptr&&temp2!=nullptr)
        {
            ListNode*x=new ListNode();
            if(temp1->val < temp2->val)
            {x->val=temp1->val;
            curr->next=x;
            curr=x;
            temp1=temp1->next;
            }
            else
            {
                x->val=temp2->val;
            curr->next=x;
            curr=x;
            temp2=temp2->next; 
            }
        }
        while(temp1!=nullptr)
        {
             ListNode*x=new ListNode();
             x->val=temp1->val;
            curr->next=x;
            curr=x;
            temp1=temp1->next;

        }
       while(temp2!=nullptr)
        {  ListNode*x=new ListNode(); x->val=temp2->val;
            curr->next=x;
            curr=x;
            temp2=temp2->next; 

        }
return ans->next;
    }
};