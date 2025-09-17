#include <iostream>

// Define a TreeNode structure for a binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Helper function to create a new tree node
TreeNode* createTreeNode(int data) {
    // In modern C++, `new` throws `std::bad_alloc` on failure.
    // A try-catch block in the calling code is the idiomatic way to handle allocation failures.
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to perform inorder traversal of a binary tree
// In-order traversal visits nodes in the order: Left, Root, Right
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);      // Traverse the left subtree
    std::cout << root->data << " ";    // Visit the root node
    inorderTraversal(root->right);     // Traverse the right subtree
}

// Function to perform postorder traversal of a binary tree
// Post-order traversal visits nodes in the order: Left, Right, Root
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);    // Traverse the left subtree
    postorderTraversal(root->right);   // Traverse the right subtree
    std::cout << root->data << " ";    // Visit the root node
}

/*
 * --- Example Usage ---
 * Note: A project can only have one 'main' function.
 * To use this code, you can integrate the tree creation and traversal
 * logic into the main function in 'Workflows.cpp'.
 *
 * #include "BinaryTree.h" // (if you create a header)
 *
 * int main() {
 *     // ... existing code ...
 *
 *     // Construct a sample binary tree
 *     //        4
 *     //       / \
 *     //      2   5
 *     //     / \
 *     //    1   3
 *     TreeNode* root = createTreeNode(4);
 *     root->left = createTreeNode(2);
 *     root->right = createTreeNode(5);
 *     root->left->left = createTreeNode(1);
 *     root->left->right = createTreeNode(3);
 *
 *     std::cout << "Inorder traversal of the binary tree: ";
 *     inorderTraversal(root);
 *     std::cout << std::endl;
 *
 *     std::cout << "Postorder traversal of the binary tree: ";
 *     postorderTraversal(root);
 *     std::cout << std::endl;
 *
 *     // Remember to free the allocated memory for the tree.
 *     // A post-order traversal is a good pattern for deletion.
 *
 *     return 0;
 * }
*/
