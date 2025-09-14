#include <iostream>
using namespace std;

class Array {
    int* arr;
    int size;
    int length;

public:
    Array() {
        arr = nullptr;
        size = 0;
        length = 0;
    }

    void create() {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
        }
        cout << "Enter size of array: ";
        cin >> size;
        arr = new int[size];
        cout << "Enter number of elements: ";
        cin >> length;
        if (length > size) length = size;
        cout << "Enter elements: ";
        for (int i = 0; i < length; i++) cin >> arr[i];
    }

    void display() {
        if (arr == nullptr) {
            cout << "Please create the array first\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < length; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    void insert() {
        if (arr == nullptr) {
            cout << "Please create the array first\n";
            return;
        }
        if (length == size) {
            cout << "Array is full\n";
            return;
        }
        int index, element;
        cout << "Enter position (0-based index): ";
        cin >> index;
        if (index < 0 || index > length) {
            cout << "Invalid index\n";
            return;
        }
        cout << "Enter element to insert: ";
        cin >> element;
        for (int i = length; i > index; i--) arr[i] = arr[i - 1];
        arr[index] = element;
        length++;
    }

    void remove() {
        if (arr == nullptr) {
            cout << "Please create the array first\n";
            return;
        }
        if (length == 0) {
            cout << "Array is empty\n";
            return;
        }
        int index;
        cout << "Enter position (0-based index) to delete: ";
        cin >> index;
        if (index < 0 || index >= length) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = index; i < length - 1; i++) arr[i] = arr[i + 1];
        length--;
    }

    void search() {
        if (arr == nullptr) {
            cout << "Please create the array first\n";
            return;
        }
        int key;
        cout << "Enter element to search: ";
        cin >> key;
        for (int i = 0; i < length; i++) {
            if (arr[i] == key) {
                cout << "Element found at index " << i << "\n";
                return;
            }
        }
        cout << "Element not found\n";
    }

    ~Array() {
        delete[] arr;
    }
};

int main() {
    Array a;
    int choice;
    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: a.create(); break;
            case 2: a.display(); break;
            case 3: a.insert(); break;
            case 4: a.remove(); break;
            case 5: a.search(); break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
