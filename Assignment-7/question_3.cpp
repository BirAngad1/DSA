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

    int middle() {
        if (!h) return -1;
        Node *s = h, *f = h;
        while (f && f->next) { s = s->next; f = f->next->next; }
        return s->v;
    }
};

int main() {
    int n; cin >> n;
    SLL a;
    while (n--) { int x; cin >> x; a.push_back(x); }
    cout << a.middle() << "\n";
    return 0;
}
