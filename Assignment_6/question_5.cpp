#include <bits/stdc++.h>
using namespace std;

class N {
public:
    int v; N *nx;
    N(int x) : v(x), nx(NULL) {}
};

class LL {
public:
    N *h = NULL;
    void add(int x) {
        N *p = new N(x);
        if (!h) { h = p; return; }
        N *t = h; while (t->nx) t = t->nx; t->nx = p;
    }
    bool isCircular() {
        if (!h) return false;
        N *t = h->nx;
        while (t && t != h) t = t->nx;
        return t == h;
    }
};

int main() {
    int n; cin >> n;
    LL a; while (n--) { int x; cin >> x; a.add(x); }
    cout << (a.isCircular() ? "True\n" : "False\n");
    return 0;
}
