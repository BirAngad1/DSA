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

    int delAll(int key) {
        int c = 0;
        while (h && h->v == key) { Node *t = h; h = h->next; delete t; c++; }
        if (!h) return c;
        Node *p = h, *t = h->next;
        while (t) {
            if (t->v == key) { p->next = t->next; delete t; t = p->next; c++; }
            else { p = t; t = t->next; }
        }
        return c;
    }

    void print() {
        Node *t = h;
        if (!t) { cout << "\n"; return; }
        while (t) { cout << t->v << " "; t = t->next; }
        cout << "\n";
    }
};

int main() {
    int n; cin >> n;
    SLL a;
    while (n--) { int x; cin >> x; a.push_back(x); }
    int key; cin >> key;
    int c = a.delAll(key);
    cout << c << "\n";
    a.print();
    return 0;
}
