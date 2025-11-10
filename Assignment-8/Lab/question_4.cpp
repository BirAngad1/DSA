#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node* root;

    Node* createNode()
    {
        int value;
        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
        {
            return nullptr;
        }

        Node* newNode = new Node(value);

        cout << "Enter left child of " << value << ":\n";
        newNode->left = createNode();

        cout << "Enter right child of " << value << ":\n";
        newNode->right = createNode();

        return newNode;
    }

    bool isBSTcheck(Node* node, Node* minNode, Node* maxNode)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (minNode != nullptr && node->data <= minNode->data)
        {
            return false;
        }

        if (maxNode != nullptr && node->data >= maxNode->data)
        {
            return false;
        }

        bool leftOK = isBSTcheck(node->left, minNode, node);
        bool rightOK = isBSTcheck(node->right, node, maxNode);

        return leftOK && rightOK;
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void createTree()
    {
        cout << "Enter root node:\n";
        root = createNode();
    }

    void inorder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    bool isBST()
    {
        return isBSTcheck(root, nullptr, nullptr);
    }

    Node* getRoot()
    {
        return root;
    }
};

int main()
{
    BinaryTree tree;

    tree.createTree();

    cout << "\nIn-order traversal:\n";
    tree.inorder(tree.getRoot());
    cout << "\n";

    if (tree.isBST())
    {
        cout << "The given binary tree IS a BST\n";
    }
    else
    {
        cout << "The given binary tree is NOT a BST\n";
    }

    return 0;
}
