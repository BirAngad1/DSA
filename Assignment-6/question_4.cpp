#include <bits/stdc++.h>
using namespace std;

class D {
public:
    char v; D *pr, *nx;
    D(char x) : v(x), pr(NULL), nx(NULL) {}
};

bool isPal(D *h) {
    if (!h) return 1;
    D *l = h, *r = h;
    while (r->nx) r = r->nx;
    while (l != r && l->pr != r) {
        if (l->v != r->v) return 0;
        l = l->nx; r = r->pr;
    }
    return 1;
}

int main() {
    string s; cin >> s;
    D *h = NULL, *t = NULL;
    for (char c : s) { D *p = new D(c); if (!h) { h = t = p; } else { t->nx = p; p->pr = t; t = p; } }
    cout << (isPal(h) ? "True\n" : "False\n");
    return 0;
}
