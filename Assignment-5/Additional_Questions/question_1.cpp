#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int v;
    Node *next;
    Node(int x) : v(x), next(NULL) {}
};

class SL {
public:
    Node *h = NULL;

    void push_back(int x) {
        Node *n = new Node(x);
        if (!h) { h = n; return; }
        Node *t = h;
        while (t->next) t = t->next;
        t->next = n;
    }
};

Node* intersect(Node *a, Node *b) {
    if (!a || !b) return NULL;
    Node *p = a, *q = b;
    while (p != q) {
        p = p ? p->next : b;
        q = q ? q->next : a;
    }
    return p;
}

int main() {
    SL A, B;
    A.push_back(4);
    A.push_back(1);
    B.push_back(5);
    B.push_back(6);
    B.push_back(1);
    Node *c1 = new Node(8);
    Node *c2 = new Node(5);
    A.h->next->next = c1;
    B.h->next->next->next = c1;
    c1->next = c2;
    Node *ans = intersect(A.h, B.h);
    if (ans) cout << ans->v << "\n";
    else cout << "NULL\n";
    return 0;
}
