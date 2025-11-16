#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};



Node* build(int* a, int n)
{
    if (n == 0 || a[0] == -1)
    {
        return nullptr;
    }

    Node* root = new Node(a[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n)
    {
        Node* cur = q.front();
        q.pop();

        if (i < n && a[i] != -1)
        {
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;

        if (i < n && a[i] != -1)
        {
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}



void rightView(Node* root)
{
    if (root == nullptr)
    {
        cout << "\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    bool first = true;

    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            Node* cur = q.front();
            q.pop();

            if (i == sz - 1)
            {
                if (!first)
                {
                    cout << " ";
                }

                cout << cur->val;
                first = false;
            }

            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }

            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
    }

    cout << "\n";
}



int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int* a = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Node* root = build(a, n);

        rightView(root);

        delete[] a;
    }

    return 0;
}
