#include <bits/stdc++.h>
using namespace std;

class X {
public:
    int v;
    X *l, *r, *u, *d;
    X(int x) : v(x), l(NULL), r(NULL), u(NULL), d(NULL) {}
};

vector<vector<X*>> build(const vector<vector<int>> &a) {
    int n = a.size();
    if (!n) return {};
    int m = a[0].size();
    vector<vector<X*>> g(n, vector<X*>(m, NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = new X(a[i][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m) { g[i][j]->r = g[i][j + 1]; g[i][j + 1]->l = g[i][j]; }
            if (i + 1 < n) { g[i][j]->d = g[i + 1][j]; g[i + 1][j]->u = g[i][j]; }
        }
    }
    return g;
}

int main() {
    return 0;
}
