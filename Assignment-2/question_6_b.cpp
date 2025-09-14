#include <iostream>
using namespace std;

int main() {
    int t1, t2;
    cout << "Enter number of non-zero terms in first matrix: ";
    cin >> t1;
    int mat1[t1][3];
    cout << "Enter row col value for first matrix:" << endl;
    for (int i = 0; i < t1; i++) cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

    cout << "Enter number of non-zero terms in second matrix: ";
    cin >> t2;
    int mat2[t2][3];
    cout << "Enter row col value for second matrix:" << endl;
    for (int i = 0; i < t2; i++) cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];

    int result[t1 + t2][3], k = 0;
    for (int i = 0; i < t1; i++) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        k++;
    }
    for (int i = 0; i < t2; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (result[j][0] == mat2[i][0] && result[j][1] == mat2[i][1]) {
                result[j][2] += mat2[i][2];
                found = true;
                break;
            }
        }
        if (!found) {
            result[k][0] = mat2[i][0];
            result[k][1] = mat2[i][1];
            result[k][2] = mat2[i][2];
            k++;
        }
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (result[i][0] > result[j][0] || 
               (result[i][0] == result[j][0] && result[i][1] > result[j][1])) {
                swap(result[i][0], result[j][0]);
                swap(result[i][1], result[j][1]);
                swap(result[i][2], result[j][2]);
            }
        }
    }
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < k; i++) {
        if (result[i][2] != 0)
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }
    return 0;
}
