#include <bits/stdc++.h>
using namespace std;

class N {
public:
    int v;
    N *nx;
    N(int x) : v(x), nx(NULL) {}
};

class CLL {
public:
    N *h = NULL;

    void push(int x) {
        N *n = new N(x);
        if (!h) {
            h = n;
            n->nx = n;
            return;
        }
        N *t = h;
        while (t->nx != h) t = t->nx;
        t->nx = n;
        n->nx = h;
    }

    void show() {
        if (!h) {
            cout << "\n";
            return;
        }
        N *t = h;
        do {
            cout << t->v << " ";
            t = t->nx;
        } while (t != h);
        cout << h->v << "\n";
    }
};

int main() {
    return 0;
}
