#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;

    int count[3] = {0, 0, 0};
    ListNode* temp = head;

    while (temp != nullptr) {
        count[temp->val]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;

    while (temp != nullptr) {
        if (count[i] == 0) {
            i++;
        } else {
            temp->val = i;
            count[i]--;
            temp = temp->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next = new ListNode(1);

    head = sortList(head);

    printList(head);

    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
