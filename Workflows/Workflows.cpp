#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* current = head; // Start from the head of the list
    while (current != nullptr) {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;     // Move to the next node
    }
    cout << endl;
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Traverse and print the linked list
    cout << "Linked list: ";
    traverseLinkedList(head);

    // Free allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}