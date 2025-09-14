#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string output = "";

    for (char c : s) {
        if (isalnum(c)) {
            output += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        output += st.top();
        st.pop();
    }

    return output;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    getline(cin, exp);

    cout << "Postfix expression: " << infixToPostfix(exp) << endl << endl;

    return 0;
}
