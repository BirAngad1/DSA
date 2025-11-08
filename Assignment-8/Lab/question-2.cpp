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

class BST 
{
public:
    Node* root;

    BST() 
    {
        root = nullptr;
    }

    void insert(int value) 
    {
        Node* newNode = new Node(value);

        if (root == nullptr) 
        {
            root = newNode;
            return;
        }

        Node* temp = root;

        while (true) 
        {
            if (value < temp->data) 
            {
                if (temp->left == nullptr) 
                {
                    temp->left = newNode;
                    break;
                } 
                else 
                {
                    temp = temp->left;
                }
            } 
            else 
            {
                if (temp->right == nullptr) 
                {
                    temp->right = newNode;
                    break;
                } 
                else 
                {
                    temp = temp->right;
                }
            }
        }
    }

    bool searchRecursive(Node* node, int key) 
    {
        if (node == nullptr) 
        {
            return false;
        }

        if (node->data == key) 
        {
            return true;
        }

        if (key < node->data) 
        {
            return searchRecursive(node->left, key);
        } 
        else 
        {
            return searchRecursive(node->right, key);
        }
    }

    bool searchIterative(int key) 
    {
        Node* temp = root;

        while (temp != nullptr) 
        {
            if (temp->data == key) 
            {
                return true;
            }

            if (key < temp->data) 
            {
                temp = temp->left;
            } 
            else 
            {
                temp = temp->right;
            }
        }

        return false;
    }

    int findMaximum() 
    {
        if (root == nullptr) 
        {
            cout << "Tree is empty.\n";
            return -1;
        }

        Node* temp = root;

        while (temp->right != nullptr) 
        {
            temp = temp->right;
        }

        return temp->data;
    }

    int findMinimum() 
    {
        if (root == nullptr) 
        {
            cout << "Tree is empty.\n";
            return -1;
        }

        Node* temp = root;

        while (temp->left != nullptr) 
        {
            temp = temp->left;
        }

        return temp->data;
    }

    Node* findNode(int key) 
    {
        Node* temp = root;

        while (temp != nullptr) 
        {
            if (key == temp->data) 
            {
                return temp;
            } 
            else if (key < temp->data) 
            {
                temp = temp->left;
            } 
            else 
            {
                temp = temp->right;
            }
        }

        return nullptr;
    }

    Node* findSuccessor(int key) 
    {
        Node* current = findNode(key);
        if (current == nullptr) return nullptr;

        if (current->right != nullptr) 
        {
            Node* temp = current->right;
            while (temp->left != nullptr) 
            {
                temp = temp->left;
            }
            return temp;
        } 
        else 
        {
            Node* succ = nullptr;
            Node* ancestor = root;
            while (ancestor != current) 
            {
                if (current->data < ancestor->data) 
                {
                    succ = ancestor;
                    ancestor = ancestor->left;
                } 
                else 
                {
                    ancestor = ancestor->right;
                }
            }
            return succ;
        }
    }

    Node* findPredecessor(int key) 
    {
        Node* current = findNode(key);
        if (current == nullptr) return nullptr;

        if (current->left != nullptr) 
        {
            Node* temp = current->left;
            while (temp->right != nullptr) 
            {
                temp = temp->right;
            }
            return temp;
        } 
        else 
        {
        	
            Node* pred = nullptr;
            Node* ancestor = root;
            while (ancestor != current) 
            {
                if (current->data > ancestor->data) 
                {
                    pred = ancestor;
                    ancestor = ancestor->right;
                } 
                else 
                {
                    ancestor = ancestor->left;
                }
            }
            return pred;
        }
    }
};

int main() 
{
    BST tree;
    int choice, value, key;
    Node* tempNode;

    while (true) 
    {
        cout << "Functions are:\n";
        cout << "1. Insert node\n";
        cout << "2. Search using Recursion\n";
        cout << "3. Search using Iterations\n";
        cout << "4. maximum element\n";
        cout << "5. minimum element\n";
        cout << "6. in-order successor\n";
        cout << "7. in-order predecessor\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter node value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                if (tree.searchRecursive(tree.root, key)) 
                {
                    cout << key << " found (Recursive)\n";
                } 
                else 
                {
                    cout << key << " not found (Recursive)\n";
                }
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> key;
                if (tree.searchIterative(key)) 
                {
                    cout << key << " found (Iterative)\n";
                } 
                else 
                {
                    cout << key << " not found (Iterative)\n";
                }
                break;

            case 4:
                value = tree.findMaximum();
                if (value != -1) 
                {
                    cout << "Maximum element: " << value << "\n";
                }
                break;

            case 5:
                value = tree.findMinimum();
                if (value != -1) 
                {
                    cout << "Minimum element: " << value << "\n";
                }
                break;

            case 6:
                cout << "Enter node value to find successor: ";
                cin >> key;
                tempNode = tree.findSuccessor(key);
                if (tempNode != nullptr) 
                {
                    cout << "In-order successor of " << key << " is " << tempNode->data << "\n";
                } 
                else 
                {
                    cout << "No successor found for " << key << "\n";
                }
                break;

            case 7:
                cout << "Enter node value to find predecessor: ";
                cin >> key;
                tempNode = tree.findPredecessor(key);
                if (tempNode != nullptr) 
                {
                    cout << "In-order predecessor of " << key << " is " << tempNode->data << "\n";
                } 
                else 
                {
                    cout << "No predecessor found for " << key << "\n";
                }
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
