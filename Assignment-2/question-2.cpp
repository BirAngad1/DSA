#include<iostream>
#include<algorithm>
using namespace std;
class sorting{
public:
	void bubbleSortRecurison(int *arr, int n){
		if(n==1){
			return;
		}
		for(int i=0 ; i<n-1 ; i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
			}
		}
		bubbleSortRecurison(arr,n-1);
	}
	
void bubbleSort(int *arr, int n) {
     
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
	
	void display(int *arr , int n){
		for(int j =0; j<n ; j++){
			cout<<arr[j]<<endl;
		}
	}
};
int main(){
	sorting bubble;
	int arr[]={64,34,25,12,22,11,90};
	int n;
	n = sizeof(arr)/sizeof(arr[0]);
	bubble.bubbleSortRecurison(arr,n);
	bubble.display(arr,n);
	cout<<endl<<endl;
	bubble.bubbleSort(arr,n);
	bubble.display(arr,n);
}
