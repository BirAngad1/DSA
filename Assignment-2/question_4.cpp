#include <iostream>
using namespace std;

class Strings {
private:
    char ch1[100], ch2[100];
public:
    void concat() {
        int i = 0, j = 0;
        cout << "Enter first string: ";
        cin.ignore();
        cin.getline(ch1, 100);
        cout << "Enter second string: ";
        cin.getline(ch2, 100);
        while (ch1[i] != '\0') i++;
        while (ch2[j] != '\0') {
            ch1[i] = ch2[j];
            i++; j++;
        }
        ch1[i] = '\0';
        cout << "Concatenated string: " << ch1 << endl;
    }

    void reverse() {
        char ch[100];
        int j = 0;
        cout << "Enter string: ";
        cin.ignore();
        cin.getline(ch, 100);
        while (ch[j] != '\0') j++;
        for (int k = j - 1; k >= 0; k--) cout << ch[k];
        cout << endl;
    }

    void removevowel() {
        char ch[100];
        cout << "Enter string: ";
        cin.ignore();
        cin.getline(ch, 100);
        for (int i = 0; ch[i] != '\0'; i++) {
            char c = ch[i];
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                c=='A'||c=='E'||c=='I'||c=='O'||c=='U') continue;
            cout << c;
        }
        cout << endl;
    }

    void sortStrings() {
        int n;
        cout << "Enter number of strings: ";
        cin >> n;
        cin.ignore();
        char arr[50][100];
        cout << "Enter strings:" << endl;
        for (int i = 0; i < n; i++) cin.getline(arr[i], 100);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = 0;
                while (arr[i][k] == arr[j][k] && arr[i][k] != '\0' && arr[j][k] != '\0') k++;
                if (arr[i][k] > arr[j][k]) {
                    char temp[100];
                    int t = 0;
                    while (arr[i][t] != '\0') { temp[t] = arr[i][t]; t++; }
                    temp[t] = '\0';
                    int p = 0;
                    while (arr[j][p] != '\0') { arr[i][p] = arr[j][p]; p++; }
                    arr[i][p] = '\0';
                    int q = 0;
                    while (temp[q] != '\0') { arr[j][q] = temp[q]; q++; }
                    arr[j][q] = '\0';
                }
            }
        }
        cout << "Sorted strings:" << endl;
        for (int i = 0; i < n; i++) cout << arr[i] << endl;
    }

    void toLowerCase() {
        char ch[100];
        cout << "Enter string: ";
        cin.ignore();
        cin.getline(ch, 100);
        for (int i = 0; ch[i] != '\0'; i++) {
            if (ch[i] >= 'A' && ch[i] <= 'Z') ch[i] = ch[i] + 32;
        }
        cout << "Lowercase string: " << ch << endl;
    }
};

int main() {
    int a;
    Strings s1;
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
        case 2: s1.reverse(); break;
        case 3: s1.removevowel(); break;
        case 4: s1.sortStrings(); break;
        case 5: s1.toLowerCase(); break;
        default: cout << "Invalid choice" << endl;
    }
    return 0;
}
