#include <bits/stdc++.h>
using namespace std;

int par(int x) { return __builtin_popcount((unsigned)x) & 1; }

class DN {
public:
    int v; DN *pr, *nx;
    DN(int x) : v(x), pr(NULL), nx(NULL) {}
};

class CN {
public:
    int v; CN *nx;
    CN(int x) : v(x), nx(NULL) {}
};

void cleanDLL(DN *&h) {
    DN *t = h;
    while (t) {
        DN *n = t->nx;
        if (par(t->v) == 0) {
            if (t->pr) t->pr->nx = t->nx; else h = t->nx;
            if (t->nx) t->nx->pr = t->pr;
            delete t;
        }
        t = n;
    }
}

void cleanCLL(CN *&h) {
    if (!h) return;
    CN *cur = h, *prv = NULL;
    do {
        CN *n = cur->nx;
        if (par(cur->v) == 0) {
            if (!prv) {
                if (cur->nx == cur) { delete cur; h = NULL; return; }
                CN *tail = cur; while (tail->nx != cur) tail = tail->nx;
                h = cur->nx; tail->nx = h; delete cur; cur = h; prv = NULL; continue;
            } else {
                prv->nx = cur->nx; if (cur == h) h = cur->nx; delete cur; cur = prv->nx; continue;
            }
        } else { prv = cur; cur = n; }
    } while (cur != h);
}

void showDLL(DN *h){ while(h){ cout<<h->v<<" "; h=h->nx; } cout<<"\n"; }
void showCLL(CN *h){ if(!h){ cout<<"\n"; return;} CN*t=h; do{ cout<<t->v<<" "; t=t->nx; }while(t!=h); cout<<"\n"; }

int main() {
    int n; cin >> n;
    DN *hd = NULL, *td = NULL;
    while (n--) { int x; cin >> x; DN *p = new DN(x); if (!hd) { hd = td = p; } else { td->nx = p; p->pr = td; td = p; } }
    cleanDLL(hd); showDLL(hd);
    int m; cin >> m;
    CN *hc = NULL, *tc = NULL;
    while (m--) { int x; cin >> x; CN *p = new CN(x); if (!hc) { hc = tc = p; } else { tc->nx = p; tc = p; } }
    if (hc) tc->nx = hc;
    cleanCLL(hc); showCLL(hc);
    return 0;
}
