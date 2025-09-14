#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int m = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[m++] = arr[i];
        }
    }

    cout << "Your new array is" <<  endl;
    
    for (int i = 0; i < m; i++) {
        cout << arr[i] << endl;
    }
    cout << "\n";

    delete[] arr;
    return 0;
}
