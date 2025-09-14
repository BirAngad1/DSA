#include <iostream>
using namespace std;

class UpperTriangularMatrix {
    int n;
    int *arr; 
public:
    void input() {
        cout << "Enter size of matrix: ";
        cin >> n;
        arr = new int[n*(n+1)/2];
        cout << "Enter upper triangular elements:"<<endl;
        for (int i = 0; i < n*(n+1)/2; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << " your Upper Triangular Matrix Is:"<<endl;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j)
                    cout << arr[k++] << " ";
                else
                    cout << "0 ";
            }
            cout <<endl;
        }
    }
};
int main(){
	UpperTriangularMatrix u1;
	u1.input();
	u1.display();
	return 0;
}
