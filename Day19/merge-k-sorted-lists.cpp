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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(auto it:lists){
            ListNode* temp=it;
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* ans=new ListNode(0);
        ListNode* temp1=ans;  
        for(int i=0;i<arr.size();i++){
            ListNode* temp2=new ListNode(arr[i]);
            temp1->next = temp2;  
            temp1=temp1->next;  
        }
        return ans->next;  
    }
};