
class Solution {
public:
 ListNode* reverseList(ListNode* l) {
         if(l==nullptr||l->next==nullptr)return l;
    ListNode* temp=l;
    ListNode* prev=nullptr;
    ListNode* front=nullptr;
    while(temp!=nullptr)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* temp1=reverseList(l1);
        ListNode* temp2=reverseList(l2);
        int num=0,carry=0;
        ListNode* ans= new ListNode();
         ListNode* dummy=ans;
        while(temp1!=nullptr&&temp2!=nullptr)
        {
            int x=temp1->val+temp2->val+carry;
            int y=x%10;
            carry=x/10;
            ListNode* temp3= new ListNode(y);
            dummy->next=temp3;
            dummy=temp3;
            temp1=temp1->next;
            temp2=temp2->next;

        }
        while(temp1!=nullptr)
        {
            int x=temp1->val+carry;
            int y=x%10;
            carry=x/10;
            ListNode* temp3= new ListNode(y);
            dummy->next=temp3;
            dummy=temp3;
            temp1=temp1->next;
        }while(temp2!=nullptr)
        {
            int x=temp2->val+carry;
            int y=x%10;
            carry=x/10;
            ListNode* temp3= new ListNode(y);
            dummy->next=temp3;
            dummy=temp3;
            temp2=temp2->next;
        }
        if(carry!=0)
        {
            ListNode* temp3= new ListNode(carry);
            dummy->next=temp3;
            dummy=temp3;
        }
        return reverseList(ans->next);
    }
};