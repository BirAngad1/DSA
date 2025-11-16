#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int v)
    {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* root = nullptr;

void insertNode(int val)
{
    Node* n = new Node(val);

    if (root == nullptr)
    {
        root = n;
        cout << "Inserted " << val << "\n";
        return;
    }

    Node* cur = root;
    Node* parent = nullptr;

    while (cur != nullptr)
    {
        parent = cur;

        if (val == cur->data)
        {
            cout << "Duplicate " << val << " ignored\n";
            delete n;
            return;
        }
        else if (val < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    if (val < parent->data)
    {
        parent->left = n;
    }
    else
    {
        parent->right = n;
    }

    cout << "Inserted " << val << "\n";
}

Node* deleteNode(Node* node, int val, bool &ok)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (val < node->data)
    {
        node->left = deleteNode(node->left, val, ok);
    }
    else if (val > node->data)
    {
        node->right = deleteNode(node->right, val, ok);
    }
    else
    {
        ok = true;

        if (node->left == nullptr)
        {
            Node* r = node->right;
            delete node;
            return r;
        }
        else if (node->right == nullptr)
        {
            Node* l = node->left;
            delete node;
            return l;
        }
        else
        {
            Node* succParent = node;
            Node* succ = node->right;

            while (succ->left != nullptr)
            {
                succParent = succ;
                succ = succ->left;
            }

            node->data = succ->data;

            if (succParent->left == succ)
            {
                succParent->left = succ->right;
            }
            else
            {
                succParent->right = succ->right;
            }

            delete succ;
        }
    }

    return node;
}

void eraseValue(int val)
{
    bool ok = false;
    root = deleteNode(root, val, ok);

    if (ok)
    {
        cout << "Deleted " << val << "\n";
    }
    else
    {
        cout << val << " not found\n";
    }
}

int maxDepth(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int a = maxDepth(node->left);
    int b = maxDepth(node->right);

    if (a > b)
    {
        return 1 + a;
    }
    else
    {
        return 1 + b;
    }
}

int minDepth(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        return 1;
    }

    if (node->left == nullptr)
    {
        return 1 + minDepth(node->right);
    }

    if (node->right == nullptr)
    {
        return 1 + minDepth(node->left);
    }

    int a = minDepth(node->left);
    int b = minDepth(node->right);

    if (a < b)
    {
        return 1 + a;
    }
    else
    {
        return 1 + b;
    }
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

int main()
{
    int ch;
    int x;

    while (true)
    {
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Maximum depth\n";
        cout << "4. Minimum depth\n";
        cout << "5. In-order traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> ch))
        {
            return 0;
        }

        if (ch == 1)
        {
            cout << "Enter value: ";
            cin >> x;
            insertNode(x);
        }
        else if (ch == 2)
        {
            cout << "Enter value: ";
            cin >> x;
            eraseValue(x);
        }
        else if (ch == 3)
        {
            cout << "Maximum depth = " << maxDepth(root) << "\n";
        }
        else if (ch == 4)
        {
            cout << "Minimum depth = " << minDepth(root) << "\n";
        }
        else if (ch == 5)
        {
            if (root == nullptr)
            {
                cout << "Tree is empty\n";
            }
            else
            {
                cout << "In-order: ";
                inorder(root);
                cout << "\n";
            }
        }
        else if (ch == 6)
        {
            cout << "ending\n";
            break;
        }
        else
        {
            cout << "wrong choice\n";
        }
    }

    return 0;
}
