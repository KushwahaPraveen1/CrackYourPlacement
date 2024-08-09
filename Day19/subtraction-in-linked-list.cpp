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

// Function to subtract two linked lists and return the result
Node* subtractLinkedLists(Node* l1, Node* l2) {
    // Reverse both linked lists to facilitate subtraction
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    Node* result = NULL;
    Node* temp = NULL;
    Node* prev = NULL;
    
    int borrow = 0;
    
    // Subtract the digits of the two lists
    while (l1 != NULL || l2 != NULL) {
        int sub = ((l1 ? l1->data : 0) - (l2 ? l2->data : 0) - borrow);
        
        // If subtraction is less than 0, we need to borrow
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        // Create a new node for the result
        temp = new Node(sub);
        
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        
        prev = temp;
        
        // Move to the next nodes in the lists
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    // Reverse the result list back to the correct order
    result = reverse(result);
    
    // Remove leading zeros
    while (result != NULL && result->data == 0) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }
    
    // If the result is NULL after removing zeros, return a list with one node containing 0
    if (result == NULL) {
        return new Node(0);
    }
    
    return result;
}

// Function to compare two linked lists (returns 1 if l1 > l2, -1 if l1 < l2, and 0 if equal)
int compareLists(Node* l1, Node* l2) {
    int len1 = 0, len2 = 0;
    Node* temp1 = l1;
    Node* temp2 = l2;
    
    // Calculate the lengths of both lists
    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }
    
    // If lengths are different, return the comparison result based on length
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    
    // If lengths are the same, compare digit by digit
    temp1 = l1;
    temp2 = l2;
    while (temp1 && temp2) {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return 0; // Lists are equal
}

// Main function to subtract two numbers represented by linked lists
Node* subtract(Node* l1, Node* l2) {
    // Compare the two linked lists
    int cmp = compareLists(l1, l2);
    
    if (cmp == 0) {
        return new Node(0); // If both lists are equal, return 0
    } else if (cmp < 0) {
        // If l1 is smaller than l2, swap them
        swap(l1, l2);
    }
    
    return subtractLinkedLists(l1, l2);
}

// Function to print the linked list
void printList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    // Example 1: L1 = 1->0->0, L2 = 1->2
    Node* l1 = new Node(1);
    l1->next = new Node(0);
    l1->next->next = new Node(0);
    
    Node* l2 = new Node(1);
    l2->next = new Node(2);
    
    Node* result = subtract(l1, l2);
    printList(result); // Output: 88 (8->8)

    return 0;
}
