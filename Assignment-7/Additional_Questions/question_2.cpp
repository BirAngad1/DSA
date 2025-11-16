#include <iostream>
#include <vector>
using namespace std;

void countingSortDigit(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    for(int x : arr) {
        int digit = (x / exp) % 10;
        count[digit]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    if(arr.empty()) return;

    int maxVal = arr[0];
    for(int x : arr) {
        if(x > maxVal) maxVal = x;
    }

    for(int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortDigit(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    cout << "Sorted Array: ";
    for(int x : arr) cout << x << " ";
}
