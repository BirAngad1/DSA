#include <bits/stdc++.h>
using namespace std;

class D {
public:
    int v; D *pr, *nx;
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

void show(D *h){ while(h){ cout<<h->v<<" "; h=h->nx; } cout<<"\n"; }

int main() {
    D *a = new D(1);
    D *b = new D(2);
    D *c = new D(3);
    a->nx = b; b->pr = a; b->nx = c; c->pr = b;
    c->pr = NULL;
    fix(a);
    show(a);
    return 0;
}
