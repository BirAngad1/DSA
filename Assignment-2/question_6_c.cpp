#include <iostream>
using namespace std;

int main() {
    int t1, r1, c1, t2, r2, c2;
    cout << "Enter rows cols and non-zero terms of first matrix: ";
    cin >> r1 >> c1 >> t1;
    int mat1[t1][3];
    cout << "Enter row col value for first matrix:" << endl;
    for (int i = 0; i < t1; i++) cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

    cout << "Enter rows cols and non-zero terms of second matrix: ";
    cin >> r2 >> c2 >> t2;
    int mat2[t2][3];
    cout << "Enter row col value for second matrix:" << endl;
    for (int i = 0; i < t2; i++) cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];

    if (c1 != r2) {
        cout << "Multiplication not possible" << endl;
        return 0;
    }

    int temp[r1][c2];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) temp[i][j] = 0;
    }

    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) {
            if (mat1[i][1] == mat2[j][0]) {
                temp[mat1[i][0]][mat2[j][1]] += mat1[i][2] * mat2[j][2];
            }
        }
    }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            if (temp[i][j] != 0) cout << i << " " << j << " " << temp[i][j] << endl;
        }
    }
    return 0;
}
