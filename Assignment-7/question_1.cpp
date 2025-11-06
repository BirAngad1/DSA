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

    void insBeg(int x) {
        Node *n = new Node(x);
        n->next = h;
        h = n;
    }

    void insEnd(int x) {
        Node *n = new Node(x);
        if (!h) { h = n; return; }
        Node *t = h;
        while (t->next) t = t->next;
        t->next = n;
    }

    void insAfter(int key, int x) {
        Node *t = h;
        while (t && t->v != key) t = t->next;
        if (!t) return;
        Node *n = new Node(x);
        n->next = t->next;
        t->next = n;
    }

    void insBefore(int key, int x) {
        if (!h) return;
        if (h->v == key) { insBeg(x); return; }
        Node *p = NULL, *t = h;
        while (t && t->v != key) { p = t; t = t->next; }
        if (!t) return;
        Node *n = new Node(x);
        p->next = n;
        n->next = t;
    }

    void delBeg() {
        if (!h) return;
        Node *t = h;
        h = h->next;
        delete t;
    }

    void delEnd() {
        if (!h) return;
        if (!h->next) { delete h; h = NULL; return; }
        Node *p = NULL, *t = h;
        while (t->next) { p = t; t = t->next; }
        p->next = NULL;
        delete t;
    }

    void delVal(int key) {
        if (!h) return;
        if (h->v == key) { delBeg(); return; }
        Node *p = NULL, *t = h;
        while (t && t->v != key) { p = t; t = t->next; }
        if (!t) return;
        p->next = t->next;
        delete t;
    }

    int findPos(int key) {
        int i = 1;
        Node *t = h;
        while (t) { if (t->v == key) return i; t = t->next; i++; }
        return -1;
    }

    void show() {
        Node *t = h;
        if (!t) { cout << "empty\n"; return; }
        while (t) { cout << t->v << " "; t = t->next; }
        cout << "\n";
    }
};

int main() {
    SLL a;
    while (true) {
        int ch; if (!(cin >> ch)) break;
        if (ch == 0) break;
        if (ch == 1) { int x; cin >> x; a.insBeg(x); }
        else if (ch == 2) { int x; cin >> x; a.insEnd(x); }
        else if (ch == 3) { int k, x; cin >> k >> x; a.insAfter(k, x); }
        else if (ch == 4) { int k, x; cin >> k >> x; a.insBefore(k, x); }
        else if (ch == 5) { a.delBeg(); }
        else if (ch == 6) { a.delEnd(); }
        else if (ch == 7) { int k; cin >> k; a.delVal(k); }
        else if (ch == 8) { int k; cin >> k; cout << a.findPos(k) << "\n"; }
        else if (ch == 9) { a.show(); }
    }
    return 0;
}
