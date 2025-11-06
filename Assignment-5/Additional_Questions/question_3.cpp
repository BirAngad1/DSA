#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int v;
    Node *next;
    Node(int x) : v(x), next(NULL) {}
};

void removeLoop(Node *h) {
    if (!h) return;
    Node *s = h, *f = h;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) break;
    }
    if (!(f && f->next)) return;
    s = h;
    while (s != f) { s = s->next; f = f->next; }
    Node *start = s;
    Node *t = start;
    while (t->next != start) t = t->next;
    t->next = NULL;
}

int main() {
    int n;
    cin >> n;
    vector<Node*> nodes;
    Node *h = NULL, *tail = NULL;
    while (n--) {
        int x; cin >> x;
        Node *p = new Node(x);
        nodes.push_back(p);
        if (!h) { h = tail = p; }
        else { tail->next = p; tail = p; }
    }
    int pos;
    cin >> pos;
    if (pos > 0 && pos <= (int)nodes.size()) tail->next = nodes[pos - 1];
    removeLoop(h);
    Node *t = h;
    while (t) { cout << t->v << " "; t = t->next; }
    cout << "\n";
    return 0;
}
