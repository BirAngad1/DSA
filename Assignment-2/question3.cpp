#include<iostream>
using namespace std;
class missingElement{
	public :
		int Linear(int arr[], int n) {
            for (int i = 0; i < n - 1; i++) {
              if (arr[i] != i + 1) {
              return i + 1;
            }
        }
        return n; 
       }
       
       int Binary(int arr[], int n) {
          int start = 0, end = n - 2; 
           while (start <= end) {
              int mid = start + (end - start) / 2;
               if (arr[mid] == mid + 1) {
                 start = mid + 1;
               }
		       else {
                end = mid - 1;
              }
            }
            return start + 1;
        }
};
int main(){
	int arr[] = {1,2,3,4,6,7,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	missingElement mis;
	cout<<mis.Linear(arr,n)<<endl;
	cout<<mis.Binary(arr,n)<<endl;
	return 0;
}
