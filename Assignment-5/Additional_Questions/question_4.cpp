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

    void print() {
        Node *t = h;
        while (t) { cout << t->v << " "; t = t->next; }
        cout << "\n";
    }
};

Node* rotateLeft(Node *h, int k) {
    if (!h || !h->next || k == 0) return h;
    int n = 1;
    Node *t = h;
    while (t->next) { t = t->next; n++; }
    k %= n;
    if (k == 0) return h;
    t->next = h;
    Node *p = h;
    for (int i = 1; i < k; i++) p = p->next;
    Node *nh = p->next;
    p->next = NULL;
    return nh;
}

int main() {
    int n, k;
    cin >> n;
    SL A;
    while (n--) { int x; cin >> x; A.push_back(x); }
    cin >> k;
    A.h = rotateLeft(A.h, k);
    A.print();
    return 0;
}
