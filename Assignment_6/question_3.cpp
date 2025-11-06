#include <bits/stdc++.h>
using namespace std;

class D {
public:
    int v;
    D *pr, *nx;
    D(int x) : v(x), pr(NULL), nx(NULL) {}
};

class N {
public:
    int v;
    N *nx;
    N(int x) : v(x), nx(NULL) {}
};

int sizeDLL(D *h) {
    int c = 0;
    while (h) {
        c++;
        h = h->nx;
    }
    return c;
}

int sizeCLL(N *h) {
    if (!h) return 0;
    int c = 1;
    for (N *t = h->nx; t != h; t = t->nx) c++;
    return c;
}

int main() {
    return 0;
}
