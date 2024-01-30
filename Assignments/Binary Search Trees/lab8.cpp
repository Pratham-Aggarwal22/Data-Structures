#include <iostream>
using namespace std;

class Node {
public:
    Node(int data) {
        this->data = data;
        this->LeftChild = nullptr;
        this->RightChild = nullptr;
    }
    int data;
    Node* LeftChild;
    Node* RightChild;
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    Node* getRoot() {
        return this->root;
    }

    Node* InsertNode(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data); // Create a new node if the current node is null
        }

        if (data < root->data) {
            root->LeftChild = InsertNode(root->LeftChild, data); // Recursively insert to the left
        } else if (data > root->data) {
            root->RightChild = InsertNode(root->RightChild, data); // Recursively insert to the right
        }

        return root;
    }

    bool FindNode(Node* root, int data) {
        if (root == nullptr) {
            return false; // If the current node is null, the data is not found
        }

        if (data == root->data) {
            return true; // Data found at the current node
        } else if (data < root->data) {
            return FindNode(root->LeftChild, data); // Recursively search to the left
        } else {
            return FindNode(root->RightChild, data); // Recursively search to the right
        }
    }

    int Largest(Node* root) {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return -1; // Return -1 to indicate an empty tree
        }

        while (root->RightChild != nullptr) {
            root = root->RightChild; // Traverse to the rightmost node to find the largest element
        }

        return root->data;
    }

    void printTreePostOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        printTreePostOrder(root->LeftChild); // Traverse to the left subtree
        printTreePostOrder(root->RightChild); // Traverse to the right subtree
        cout << root->data << " "; // Print the current node
    }
};

int main() {
    BST tree;
    Node* root = tree.getRoot();

    // Insert elements into the tree
    root = tree.InsertNode(root, 9);
    root = tree.InsertNode(root, 12);
    root = tree.InsertNode(root, 18);
    root = tree.InsertNode(root, 4);
    root = tree.InsertNode(root, 21);
    root = tree.InsertNode(root, 10);
    root = tree.InsertNode(root, 7);
    root = tree.InsertNode(root, 8);
    root = tree.InsertNode(root, 15);
    root = tree.InsertNode(root, 70);

    cout << "Inserted elements: 9 12 18 4 21 10 7 8 15 70" << endl;
    cout << "Post-order: ";
    tree.printTreePostOrder(root);
    cout << endl;

    int largest = tree.Largest(root);
    cout << "Largest element in the list is: " << largest << endl;

    int lookup;
    cout << "Insert a number for lookup >> ";
    cin >> lookup;
    if (!tree.FindNode(root, lookup)) {
        cout << lookup << " not found" << endl;
    } else {
        cout << lookup << endl;
    }

    return 0;
}
