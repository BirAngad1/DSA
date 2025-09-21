#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    int count = 0;

    while (count < n) {
        string s = q.front();
        q.pop();
        cout << s;
        count++;
        if (count < n) cout << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
    return 0;
}
