#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* createNode() {
        int value;
        cout << "Enter node value (-1 for no node): ";
        cin >> value;
        if (value == -1) return nullptr;

        Node* newNode = new Node(value);
        cout << "Enter left child of " << value << ":\n";
        newNode->left = createNode();
        cout << "Enter right child of " << value << ":\n";
        newNode->right = createNode();
        return newNode;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void createTree() {
        cout << "Enter root node:\n";
        root = createNode();
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinaryTree tree;

    tree.createTree();

    cout << "Pre-order:\n";
    tree.preorder(tree.getRoot());

    cout << "\nIn-order:\n";
    tree.inorder(tree.getRoot());

    cout << "\nPost-order:\n";
    tree.postorder(tree.getRoot());

    return 0;
}
