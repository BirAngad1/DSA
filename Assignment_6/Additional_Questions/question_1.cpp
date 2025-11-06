#include <bits/stdc++.h>
using namespace std;

class N {
public:
    int v; N *nx;
    N(int x) : v(x), nx(NULL) {}
};

void split(N *h, N *&a, N *&b) {
    if (!h) { a = NULL; b = NULL; return; }
    N *s = h, *f = h;
    while (f->nx != h && f->nx->nx != h) { s = s->nx; f = f->nx->nx; }
    if (f->nx->nx == h) f = f->nx;
    a = h; b = s->nx;
    f->nx = b; s->nx = a;
}

void print(N *h) { if (!h) { cout << "\n"; return; } N *t = h; do { cout << t->v << " "; t = t->nx; } while (t != h); cout << "\n"; }

int main() {
    int n; cin >> n;
    N *h = NULL, *t = NULL;
    while (n--) { int x; cin >> x; N *p = new N(x); if (!h) { h = t = p; } else { t->nx = p; t = p; } }
    if (h) t->nx = h;
    N *a, *b; split(h, a, b);
    print(a); print(b);
    return 0;
}
