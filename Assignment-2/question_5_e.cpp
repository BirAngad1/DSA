#include <iostream>
using namespace std;

class SymmetricMatrix {
    int n;
    int *arr; 
public:
    void read() {
        cout << "Enter size of matrix: ";
        cin >> n;
        arr = new int[n*(n+1)/2];
        cout << "Enter lower triangular elements row-wise:"<<endl;
        for (int i = 0; i < n*(n+1)/2; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Your Symmetric Matrix Is:"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index;
                if (i >= j) 
                    index = (i*(i+1))/2 + j;  
                else 
                    index = (j*(j+1))/2 + i; 
                cout << arr[index] << " ";
            }
            cout <<endl;
        }
    }
};

int main() {
    SymmetricMatrix m;
    m.read();
    m.display();
    return 0;
}
