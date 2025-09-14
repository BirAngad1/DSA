#include <iostream>
using namespace std;

void reverseMatrix(int **mat, int n, int m) {
    cout << "Reversed Matrix:\n";
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int **mat, int n, int m) {
    cout << "Transposed Matrix:\n";
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    int **mat = new int*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[m];
    }

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int choice;
    cout << "Choose operation:\n";
    cout << "1. Reverse Matrix (Q4a)\n";
    cout << "2. Transpose Matrix (Q4c)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        reverseMatrix(mat, n, m);
    } else if (choice == 2) {
        transposeMatrix(mat, n, m);
    } else {
        cout << "Invalid choice!\n";
    }

    for (int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;

    return 0;
}
