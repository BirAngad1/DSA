#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n; i++) {
        int size = n - i;
        int mn = INT_MAX;
        for (int j = 0; j < size; j++) {
            int v = q.front(); q.pop();
            if (v < mn) mn = v;
            q.push(v);
        }
        bool taken = false;
        for (int j = 0; j < size; j++) {
            int v = q.front(); q.pop();
            if (v == mn && !taken) {
                taken = true;
            } else {
                q.push(v);
            }
        }
        q.push(mn);
    }

    for (int i = 0; i < n; i++) {
        cout << q.front();
        q.pop();
        if (i < n - 1) cout << " ";
    }
    return 0;
}
