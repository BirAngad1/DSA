#include <bits/stdc++.h>
using namespace std;

class N {
public:
    int v;
    N *nx;
    N(int x) : v(x), nx(NULL) {}
};

void split(N *h, N *&a, N *&b) {
    if (!h) { a = NULL; b = NULL; return; }
    N *slow = h, *fast = h;
    while (fast->nx != h && fast->nx->nx != h) {
        slow = slow->nx;
        fast = fast->nx->nx;
    }
    if (fast->nx->nx == h) fast = fast->nx;
    a = h;
    b = slow->nx;
    fast->nx = b;
    slow->nx = a;
}

int main() {
    return 0;
}
