#include <bits/stdc++.h>
using namespace std;

struct D {
    int v;
    D *pr, *nx;
    D(int x) : v(x), pr(NULL), nx(NULL) {}
};

struct C {
    int v;
    C *nx;
    C(int x) : v(x), nx(NULL) {}
};

struct DLL {
    D *h = NULL;

    void insBeg(int x) {
        D *n = new D(x);
        if (!h) { h = n; return; }
        n->nx = h;
        h->pr = n;
        h = n;
    }

    void insEnd(int x) {
        D *n = new D(x);
        if (!h) { h = n; return; }
        D *t = h;
        while (t->nx) t = t->nx;
        t->nx = n;
        n->pr = t;
    }

    void insAfter(int k, int x) {
        D *t = h;
        while (t && t->v != k) t = t->nx;
        if (!t) return;
        D *n = new D(x);
        n->nx = t->nx;
        n->pr = t;
        if (t->nx) t->nx->pr = n;
        t->nx = n;
    }

    void insBefore(int k, int x) {
        D *t = h;
        while (t && t->v != k) t = t->nx;
        if (!t) return;
        D *n = new D(x);
        n->nx = t;
        n->pr = t->pr;
        if (t->pr) t->pr->nx = n;
        else h = n;
        t->pr = n;
    }

    void delVal(int k) {
        D *t = h;
        while (t && t->v != k) t = t->nx;
        if (!t) return;
        if (t->pr) t->pr->nx = t->nx;
        else h = t->nx;
        if (t->nx) t->nx->pr = t->pr;
        delete t;
    }

    int find(int k) {
        int p = 1;
        D *t = h;
        while (t) {
            if (t->v == k) return p;
            t = t->nx;
            p++;
        }
        return -1;
    }

    void show() {
        D *t = h;
        if (!t) { cout << "empty\n"; return; }
        while (t) { cout << t->v << " "; t = t->nx; }
        cout << "\n";
    }
};

struct CLL {
    C *h = NULL;

    void insBeg(int x) {
        C *n = new C(x);
        if (!h) { h = n; n->nx = n; return; }
        C *t = h;
        while (t->nx != h) t = t->nx;
        n->nx = h;
        t->nx = n;
        h = n;
    }

    void insEnd(int x) {
        C *n = new C(x);
        if (!h) { h = n; n->nx = n; return; }
        C *t = h;
        while (t->nx != h) t = t->nx;
        t->nx = n;
        n->nx = h;
    }

    void insAfter(int k, int x) {
        if (!h) return;
        C *t = h;
        do {
            if (t->v == k) {
                C *n = new C(x);
                n->nx = t->nx;
                t->nx = n;
                return;
            }
            t = t->nx;
        } while (t != h);
    }

    void insBefore(int k, int x) {
        if (!h) return;
        if (h->v == k) { insBeg(x); return; }
        C *t = h;
        do {
            if (t->nx->v == k) {
                C *n = new C(x);
                n->nx = t->nx;
                t->nx = n;
                return;
            }
            t = t->nx;
        } while (t != h);
    }

    void delVal(int k) {
        if (!h) return;
        C *t = h, *p = NULL;
        do {
            if (t->v == k) {
                if (p == NULL) {
                    if (h->nx == h) { delete h; h = NULL; return; }
                    C *tail = h;
                    while (tail->nx != h) tail = tail->nx;
                    h = h->nx;
                    tail->nx = h;
                    delete t;
                    return;
                } else {
                    p->nx = t->nx;
                    if (t == h) h = t->nx;
                    delete t;
                    return;
                }
            }
            p = t;
            t = t->nx;
        } while (t != h);
    }

    int find(int k) {
        if (!h) return -1;
        int p = 1;
        C *t = h;
        do {
            if (t->v == k) return p;
            t = t->nx;
            p++;
        } while (t != h);
        return -1;
    }

    void show() {
        if (!h) { cout << "empty\n"; return; }
        C *t = h;
        do {
            cout << t->v << " ";
            t = t->nx;
        } while (t != h);
        cout << "\n";
    }
};

int main() {
    int type;
    cin >> type;
    DLL A;
    CLL B;
    while (true) {
        int ch;
        if (!(cin >> ch)) break;
        if (ch == 0) break;
        if (ch == 1) { int x; cin >> x; type == 1 ? A.insBeg(x) : B.insBeg(x); }
        else if (ch == 2) { int x; cin >> x; type == 1 ? A.insEnd(x) : B.insEnd(x); }
        else if (ch == 3) { int k, x; cin >> k >> x; type == 1 ? A.insAfter(k, x) : B.insAfter(k, x); }
        else if (ch == 4) { int k, x; cin >> k >> x; type == 1 ? A.insBefore(k, x) : B.insBefore(k, x); }
        else if (ch == 5) { int k; cin >> k; type == 1 ? A.delVal(k) : B.delVal(k); }
        else if (ch == 6) { int k; cin >> k; cout << (type == 1 ? A.find(k) : B.find(k)) << "\n"; }
        else if (ch == 7) { type == 1 ? A.show() : B.show(); }
    }
    return 0;
}
