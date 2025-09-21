#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> students(n), sandwiches(n);
    int c0 = 0, c1 = 0;

    for (int i = 0; i < n; i++) {
        cin >> students[i];
        if (students[i] == 0) c0++;
        else c1++;
    }
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    int taken = 0;
    for (int i = 0; i < n; i++) {
        if (sandwiches[i] == 0) {
            if (c0 > 0) {
                c0--; taken++;
            } else break;
        } else {
            if (c1 > 0) {
                c1--; taken++;
            } else break;
        }
    }

    cout << (n - taken);
    return 0;
}
