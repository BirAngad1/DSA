#include <bits/stdc++.h>
using namespace std;

class D {
public:
    int v; D *pr, *nx;
    D(int x) : v(x), pr(NULL), nx(NULL) {}
};

class N {
public:
    int v; N *nx;
    N(int x) : v(x), nx(NULL) {}
};

int sizeDLL(D *h) {
    int c = 0; while (h) { c++; h = h->nx; } return c;
}

int sizeCLL(N *h) {
    if (!h) return 0; int c = 1; for (N *t = h->nx; t != h; t = t->nx) c++; return c;
}

int main() {
    int n; cin >> n;
    D *hd = NULL, *tail = NULL;
    while (n--) { int x; cin >> x; D *p = new D(x); if (!hd) { hd = tail = p; } else { tail->nx = p; p->pr = tail; tail = p; } }
    cout << "dll " << sizeDLL(hd) << "\n";
    int m; cin >> m;
    N *hc = NULL, *tc = NULL;
    while (m--) { int x; cin >> x; N *p = new N(x); if (!hc) { hc = tc = p; } else { tc->nx = p; tc = p; } }
    if (hc) { tc->nx = hc; }
    cout << "cll " << sizeCLL(hc) << "\n";
    return 0;
}
