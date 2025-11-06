#include <bits/stdc++.h>
using namespace std;

class D {
public:
    int v;
    D *pr, *nx;
    D(int x) : v(x), pr(NULL), nx(NULL) {}
};

void fix(D *h) {
    if (!h) return;
    if (h->nx && h->nx->pr != h) { h->nx->pr = h; return; }
    if (h->pr) { h->pr = NULL; return; }
    D *t = h->nx;
    while (t) {
        if (t->nx && t->nx->pr != t) { t->nx->pr = t; return; }
        if (t->pr && t->pr->nx != t) { t->pr->nx = t; return; }
        t = t->nx;
    }
}

int main() {
    return 0;
}
