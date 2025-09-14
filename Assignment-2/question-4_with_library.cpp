#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class string_library {
    private:
        string str1, str2;

    public:
        void concat() {
            cout << "Enter first string: ";
            cin.ignore();
            getline(cin, str1);
            cout << "Enter second string: ";
            getline(cin, str2);
            str1 = str1 + str2;
            cout << "Concatenated string: " << str1 << endl;
        }

        void reverseString() {
            cout << "Enter the string: ";
            cin.ignore();
            getline(cin, str1);
            reverse(str1.begin(), str1.end());
            cout << "Reversed string: " << str1 << endl;
        }

        void removevowel() {
            char ch[100];
            cout << "Enter the string: ";
            cin.ignore();
            cin.getline(ch, 100);
            for (int i = 0; ch[i] != '\0'; i++) {
                if (string("aeiouAEIOU").find(ch[i]) != string::npos) continue;
                cout << ch[i];
            }
            cout << endl;
        }

        void sortStrings() {
            int n;
            cout << "Enter number of strings: ";
            cin >> n;
            cin.ignore();
            vector<string> arr(n);
            cout << "Enter strings:" << endl;
            for (int i = 0; i < n; i++) getline(cin, arr[i]);
            sort(arr.begin(), arr.end());
            cout << "Sorted strings:" << endl;
            for (int i = 0; i < n; i++) cout << arr[i] << endl;
        }

        void toLowerCase() {
            cout << "Enter string: ";
            cin.ignore();
            getline(cin, str1);
            for (int i = 0; i < str1.size(); i++) {
                if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] = str1[i] + 32;
            }
            cout << "Lowercase string: " << str1 << endl;
        }
};

int main() {
    int a;
    string_library s1;
    cout << "What operation do you want to perform:" << endl;
    cout << "1 --> Concatenate one string to another string." << endl;
    cout << "2 --> Reverse a string." << endl;
    cout << "3 --> Delete all the vowels from the string." << endl;
    cout << "4 --> Sort the strings in alphabetical order." << endl;
    cout << "5 --> Convert string from uppercase to lowercase." << endl;
    cout << "Enter your choice: ";
    cin >> a;

    switch (a) {
        case 1: s1.concat(); break;
        case 2: s1.reverseString(); break;
        case 3: s1.removevowel(); break;
        case 4: s1.sortStrings(); break;
        case 5: s1.toLowerCase(); break;
        default: cout << "Invalid choice" << endl;
    }
    return 0;
}
