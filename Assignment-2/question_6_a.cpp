#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Enter number of non-zero terms: ";
    cin >> t;

    int mat[t][3];
    cout << "Enter row and column value Triplet form:"<<endl;
    for (int i = 0; i < t; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    int trans[t][3];
    int k = 0;
    for (int i = 0; i < t; i++) {
        trans[k][0] = mat[i][1];
        trans[k][1] = mat[i][0];
        trans[k][2] = mat[i][2];
        k++;
    }

    cout << "Transpose Matrix Triplet Form:"<<endl;
    for (int i = 0; i < k; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    return 0;
}
