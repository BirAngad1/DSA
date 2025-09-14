#include <iostream>
using namespace std;

class TriDiagonalMatrix {
    int n;
    int *arr; 
public:
    void input() {
        cout << "Enter size of matrix: ";
        cin >> n;
        arr = new int[3*n - 2];
        cout << "Enter elements in lower, main and upper diagonals:"<<endl;
        for (int i = 0; i < 3*n - 2; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Your Tri-diagonal Matrix Is:"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i-j == 1) 
                    cout << arr[i-1] << " ";
                else if (i-j == 0) 
                    cout << arr[n-1+i] << " ";
                else if (j-i == 1) 
                    cout << arr[2*n-1+i] << " ";
                else
                    cout << "0 ";
            }
            cout <<endl;
        }
    }
};
int main(){
	TriDiagonalMatrix t1;
	t1.input();
	t1.display();
	return 0;
}
