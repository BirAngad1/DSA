#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> st;
    string s;
    int flag = 0;

    cout << "Enter the expression" << endl;
    getline(cin, s);

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                flag = 1;
                break;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0 && st.empty())
        cout << "Balanced Expression" << endl;
    else
        cout << "Unbalanced Expression" << endl;

    return 0;
}
