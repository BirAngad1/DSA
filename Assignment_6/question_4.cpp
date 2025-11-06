#include <bits/stdc++.h>
using namespace std;

class D {
public:
    char v;
    D *pr, *nx;
    D(char x) : v(x), pr(NULL), nx(NULL) {}
};

bool isPal(D *h) {
    if (!h) return 1;
    D *l = h;
    D *r = h;
    while (r->nx) r = r->nx;
    while (l != r && l->pr != r) {
        if (l->v != r->v) return 0;
        l = l->nx;
        r = r->pr;
    }
    return 1;
}

int main() {
    return 0;
}
