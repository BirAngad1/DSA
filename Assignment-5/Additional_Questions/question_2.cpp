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

Node* revK(Node *head, int k) {
    Node *chk = head;
    for (int i = 0; i < k; i++) { if (!chk) return head; chk = chk->next; }
    Node *cur = head, *prev = NULL, *nxt = NULL;
    int c = 0;
    while (cur && c < k) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        c++;
    }
    if (nxt) head->next = revK(nxt, k);
    return prev;
}

int main() {
    int n, k;
    cin >> n;
    SL A;
    while (n--) { int x; cin >> x; A.push_back(x); }
    cin >> k;
    A.h = revK(A.h, k);
    A.print();
    return 0;
}
