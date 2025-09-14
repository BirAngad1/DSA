#include <iostream>
using namespace std;

class LowerTriangularMatrix {
    int n;
    int *arr; 
public:
    void input() {
        cout << "Enter size of matrix: ";
        cin >> n;
        arr = new int[n*(n+1)/2];
        cout << "Enter lower triangular elements "<<endl;
        for (int i = 0; i < n*(n+1)/2; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Your Lower Triangular Matrix Is:"<<endl;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j)
                    cout << arr[k++] << " ";
                else
                    cout << "0 ";
            }
            cout <<endl;
        }
    }
};
int main(){
	LowerTriangularMatrix l1;
	l1.input();
	l1.display();
	return 0;
}
