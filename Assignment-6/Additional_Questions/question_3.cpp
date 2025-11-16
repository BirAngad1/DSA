#include <bits/stdc++.h>
using namespace std;

class D {
public:
    int v; D *pr, *nx;
    D(int x) : v(x), pr(NULL), nx(NULL) {}
};

D* revK(D *h, int k) {
    if (!h || k <= 1) return h;
    int c = 0; for (D *t = h; t && c < k; t = t->nx, c++); if (c < k) return h;
    D *prev = NULL, *node = h; c = 0;
    while (node && c < k) {
        D *n = node->nx;
        node->nx = prev;
        if (prev) prev->pr = node;
        node->pr = n;
        prev = node;
        node = n;
        c++;
    }
    if (node) {
        D *t = revK(node, k);
        h->nx = t;
        if (t) t->pr = h;
    }
    prev->pr = NULL;
    return prev;
}

void show(D *h){ while(h){ cout<<h->v<<" "; h=h->nx; } cout<<"\n"; }

int main() {
    int n; cin >> n;
    D *h = NULL, *t = NULL;
    while (n--) { int x; cin >> x; D *p = new D(x); if (!h) { h = t = p; } else { t->nx = p; p->pr = t; t = p; } }
    int k; cin >> k;
    h = revK(h, k);
    show(h);
    return 0;
}
