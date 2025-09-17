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

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    // If the node to delete is the head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    // If the node was found, delete it
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void addNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to add three nodes at a time
void addThreeNodes(Node*& head, int val1, int val2, int val3) {
    // Create the three new nodes
    Node* node1 = createNode(val1);
    Node* node2 = createNode(val2);
    Node* node3 = createNode(val3);

    // Link them together
    node1->next = node2;
    node2->next = node3;

    // If the list is empty, the first new node becomes the head
    if (head == nullptr) {
        head = node1;
        return;
    }

    // Find the end of the list
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Append the new chain of nodes
    current->next = node1;
}

int main() {
    Node* head = nullptr; // Start with an empty list

    // Add three nodes at once
    cout << "Adding 10, 11, 12..." << std::endl;
    addThreeNodes(head, 10, 11, 12);

    cout << "List after adding three nodes: ";
    traverseLinkedList(head);

    // Free allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr; // Good practice to avoid dangling pointers
    cout << head->data << endl;
    return 0;
}