#include<iostream>
#include<algorithm>
using namespace std;
bool binary(int arr[] , int start , int end , int target){
	int mid;
	
	mid = start + (end - start)/2;
	
	if(start > end)
	return false;
	
	if(arr[mid] == target)
	return true;
	
	else{
		if(arr[mid] > target){
			return binary(arr , start , mid-1 , target);
		}
		return binary(arr , mid+1 , end , target);
	}
}
//just realized that while loop is better in real world as  
//deep recursion may cause stack overflow in big cases as we r gonna call function again and again
bool binary_loop(int arr[], int n, int target) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}

int main(){
	int n , target ;
	
	cout<<"enter the size of array"<<endl;
	cin>>n;
	
	int *arr = new int[n];
	
	cout<<"enter array"<<endl;
	
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	
	sort(arr, arr + n);
	
	cout<<"enter the target element"<<endl;
	cin>>target;
	
	if(binary(arr , 0 , n-1 , target))
	cout<<"target is present"<<endl;
	else
	cout<<"Not Found"<<endl;
	delete[] arr;
}
