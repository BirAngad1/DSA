#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> st;
    string str;

    cout << "Enter the string" << endl;
    getline(cin >> ws, str);

    for (char c : str) st.push(c);

    cout << "Reversed String: ";
    while (!st.empty()) { 
	cout << st.top(); st.pop(); 
	}
    cout << endl;

    return 0;
}
