#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool repeat = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                repeat = true;
                break;
            }
        }
        if (!repeat) count++;
    }

    cout << "Number of distinct elements: " << count << endl;
    return 0;
}

