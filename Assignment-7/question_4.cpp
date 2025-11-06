#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int v;
    Node *next;
    Node(int x) : v(x), next(NULL) {}
};

class SLL {
public:
    Node *h = NULL;

    void push_back(int x) {
        Node *n = new Node(x);
        if (!h) { h = n; return; }
        Node *t = h;
        while (t->next) t = t->next;
        t->next = n;
    }

    void reverse() {
        Node *p = NULL, *c = h, *n = NULL;
        while (c) { n = c->next; c->next = p; p = c; c = n; }
        h = p;
    }

    void print() {
        Node *t = h;
        while (t) { cout << t->v << " "; t = t->next; }
        cout << "\n";
    }
};

int main() {
    int n; cin >> n;
    SLL a;
    while (n--) { int x; cin >> x; a.push_back(x); }
    a.reverse();
    a.print();
    return 0;
}
