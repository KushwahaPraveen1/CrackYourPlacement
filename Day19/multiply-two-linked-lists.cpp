#include <iostream>
using namespace std;

#define MOD 1000000007

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to convert linked list to its integer representation
long long linkedListToNumber(Node* head) {
    long long number = 0;
    while (head != NULL) {
        number = (number * 10 + head->data) % MOD;
        head = head->next;
    }
    return number;
}

// Function to multiply two linked lists
long long multiplyTwoLists(Node* l1, Node* l2) {
    // Get the numbers represented by the linked lists
    long long num1 = linkedListToNumber(l1);
    long long num2 = linkedListToNumber(l2);
    
    // Multiply the two numbers and take modulo
    return (num1 * num2) % MOD;
}

// Main function for testing
int main() {
    // Example 1
    Node* l1 = new Node(3);
    l1->next = new Node(2);
    
    Node* l2 = new Node(2);
    
    cout << multiplyTwoLists(l1, l2) << endl; // Output: 64
    
    // Example 2
    Node* l3 = new Node(1);
    l3->next = new Node(0);
    l3->next->next = new Node(0);
    
    Node* l4 = new Node(1);
    l4->next = new Node(0);
    
    cout << multiplyTwoLists(l3, l4) << endl; // Output: 1000
    
    return 0;
}
