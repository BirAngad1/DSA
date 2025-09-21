#include <iostream>
#include <queue>
#include <stack>
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

    stack<int> st;
    int need = 1;

    while (!q.empty() || !st.empty()) {
        if (!q.empty() && q.front() == need) {
            q.pop();
            need++;
        } else if (!st.empty() && st.top() == need) {
            st.pop();
            need++;
        } else if (!q.empty()) {
            st.push(q.front());
            q.pop();
        } else {
            break;
        }
    }

    if (need == n + 1) cout << "Yes";
    else cout << "No";

    return 0;
}
