#include <bits/stdc++.h>
using namespace std;

class N {
public:
    int v;
    N *nx;
    N(int x) : v(x), nx(NULL) {}
};

bool isCircular(N *h) {
    if (!h) return 0;
    N *t = h->nx;
    while (t && t != h) t = t->nx;
    return t == h;
}

int main() {
    return 0;
}
