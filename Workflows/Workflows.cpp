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


int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Traverse and print the linked list
    cout << "Linked list: ";
    traverseLinkedList(head);

    

    // Delete node with value 2
    deleteNode(head, 2);

    // Traverse and print the linked list after deletion
    cout << "After deleting 2: ";
    traverseLinkedList(head);

    // Free allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    // Delete node with value 2
    deleteNode(head, 2);

    // Traverse and print the linked list after deletion
    cout << "After deleting 2: ";
    // This is the code
   // Add node with value 4 at the end
    addNode(head, 4);

    // Traverse and print the linked list after adding 4
    cout << "After adding 4: ";
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