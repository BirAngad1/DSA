#include <iostream>
using namespace std;

class DiagonalMatrix {
    int n;
    int *arr; 
public:
    void input() {
        cout << "Enter size of matrix: ";
        cin >> n;
        arr = new int[n];
        cout << "Enter elements in diagonal part:"<<endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Your Diagonal Matrix Is:"<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    cout << arr[i] << " ";
                else
                    cout << "0 ";
            }
            cout <<endl;
        }
    }
};
int main(){
	DiagonalMatrix d1;
	d1.input();
	d1.display();
	return 0;
}
