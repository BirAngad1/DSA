#include <bits/stdc++.h>
using namespace std;

class P {
public:
    int c, p;
    P *next;
    P(int C, int Pwr) : c(C), p(Pwr), next(NULL) {}
};

class Poly {
public:
    P *h = NULL;

    void push_back(int c, int p) {
        P *n = new P(c, p);
        if (!h) { h = n; return; }
        P *t = h;
        while (t->next) t = t->next;
        t->next = n;
    }

    void print_pairs() {
        P *t = h;
        while (t) {
            cout << "[" << t->c << "," << t->p << "]";
            if (t->next) cout << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

P* add(P *a, P *b) {
    P d(0,0);
    P *t = &d;
    while (a && b) {
        if (a->p == b->p) {
            int s = a->c + b->c;
            if (s) { t->next = new P(s, a->p); t = t->next; }
            a = a->next; b = b->next;
        } else if (a->p > b->p) {
            t->next = new P(a->c, a->p); t = t->next; a = a->next;
        } else {
            t->next = new P(b->c, b->p); t = t->next; b = b->next;
        }
    }
    while (a) { t->next = new P(a->c, a->p); t = t->next; a = a->next; }
    while (b) { t->next = new P(b->c, b->p); t = t->next; b = b->next; }
    return d.next;
}

int main() {
    int n, m;
    cin >> n;
    Poly A, B, C;
    for (int i = 0; i < n; i++) { int c, p; cin >> c >> p; A.push_back(c, p); }
    cin >> m;
    for (int i = 0; i < m; i++) { int c, p; cin >> c >> p; B.push_back(c, p); }
    C.h = add(A.h, B.h);
    C.print_pairs();
    return 0;
}
