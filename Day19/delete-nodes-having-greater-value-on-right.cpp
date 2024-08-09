#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Function to remove nodes having greater value on the right
Node* compute(Node* head) {
    // Step 1: Reverse the linked list
    head = reverse(head);
    
    // Step 2: Traverse the reversed list and remove nodes
    Node* maxNode = head;
    Node* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->next->data < maxNode->data) {
            // Remove the next node
            current->next = current->next->next;
        } else {
            // Update maxNode and move to the next node
            current = current->next;
            maxNode = current;
        }
    }
    
    // Step 3: Reverse the list again to restore original order
    head = reverse(head);
    
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    // Example 1
    Node* head1 = new Node(12);
    head1->next = new Node(15);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(11);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(2);
    head1->next->next->next->next->next->next->next = new Node(3);
    
    head1 = compute(head1);
    printList(head1); // Output: 15 11 6 3

    // Example 2
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);
    head2->next->next->next->next = new Node(50);
    head2->next->next->next->next->next = new Node(60);
    
    head2 = compute(head2);
    printList(head2); // Output: 60

    return 0;
}
    