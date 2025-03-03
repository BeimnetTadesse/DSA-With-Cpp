#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function prototypes
Node* createNode(int value);
Node* insertBST(Node* root, int value);
Node* deleteNode(Node* root, int value);
void preorderTraversal(Node* root);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);
int findMin(Node* root);
int findMax(Node* root);
int findHeight(Node* root);
bool search(Node* root, int value);
int findLevel(Node* root, int value, int level);

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the BST
Node* insertBST(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Preorder traversal
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Postorder traversal
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Find the minimum value
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Find the maximum value
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

// Find the height of the BST
int findHeight(Node* root) {
    if (root == nullptr) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// Function to find the level of a node
int findLevel(Node* root, int value, int level) {
    if (root == nullptr) return -1; // Node not found
    if (root->data == value) return level;

    // Search in the left subtree
    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1) return leftLevel;

    // Search in the right subtree
    return findLevel(root->right, value, level + 1);
}

// Main function
int main() {
    Node* root = nullptr;
    int choice, value, level;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Find Minimum\n";
        cout << "7. Find Maximum\n";
        cout << "8. Find Height\n";
        cout << "9. Search\n";
        cout << "10. Find Level of a Node\n";
        cout << "11. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertBST(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Minimum value in BST: " << findMin(root) << endl;
                break;
            case 7:
                cout << "Maximum value in BST: " << findMax(root) << endl;
                break;
            case 8:
                cout << "Height of BST: " << findHeight(root) << endl;
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(root, value) ? "Found" : "Not Found") << endl;
                break;
            case 10:
                cout << "Enter value to find its level: ";
                cin >> value;
                level = findLevel(root, value, 0);
                if (level == -1) {
                    cout << "Node not found!" << endl;
                } else {
                    cout << "The level of node " << value << " is: " << level << endl;
                }
                break;
            case 11:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
