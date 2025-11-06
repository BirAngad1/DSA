#include <bits/stdc++.h>
using namespace std;

int parity(int x) {
    return __builtin_popcount((unsigned)x) & 1;
}

class DNode {
public:
    int v;
    DNode *pr, *nx;
    DNode(int x) : v(x), pr(NULL), nx(NULL) {}
};

void cleanDLL(DNode *&h) {
    DNode *t = h;
    while (t) {
        DNode *n = t->nx;
        if (parity(t->v) == 0) {
            if (t->pr) t->pr->nx = t->nx;
            else h = t->nx;
            if (t->nx) t->nx->pr = t->pr;
            delete t;
        }
        t = n;
    }
}

class CNode {
public:
    int v;
    CNode *nx;
    CNode(int x) : v(x), nx(NULL) {}
};

void cleanCLL(CNode *&h) {
    if (!h) return;
    CNode *cur = h, *pr = NULL;
    do {
        CNode *n = cur->nx;
        if (parity(cur->v) == 0) {
            if (pr == NULL) {
                if (cur->nx == cur) { delete cur; h = NULL; return; }
                CNode *tail = cur;
                while (tail->nx != cur) tail = tail->nx;
                h = cur->nx;
                tail->nx = h;
                delete cur;
                cur = h;
                pr = NULL;
                continue;
            } else {
                pr->nx = cur->nx;
                if (cur == h) h = cur->nx;
                delete cur;
                cur = pr->nx;
                continue;
            }
        } else {
            pr = cur;
            cur = n;
        }
    } while (cur != h);
}

int main() {
    return 0;
}
