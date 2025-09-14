#include <iostream>
using namespace std;

class Stack {
    int *arr, top, size;
public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
	 delete[] arr;
	  }
	  
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed: " << x << endl << endl;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl << endl;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == size - 1;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl << endl;
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl << endl;
            return;
        }
        cout << "Top: " << arr[top] << endl << endl;
    }
};

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;
    cout << endl;
    Stack s(n);
    int choice, val;
    do {
    	cout<<"Which function do u want to perform"<<endl;
        cout << "1.Push  2.Pop  3.isEmpty  4.isFull  5.Display  6.Peek  7.Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Yes" : "No") << endl << endl; break;
            case 4: cout << (s.isFull() ? "Yes" : "No") << endl << endl; break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
        }
    } while (choice != 7);
    return 0;
}
