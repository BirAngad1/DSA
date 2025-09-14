#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[100], ans[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        int x=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                x=arr[j];
                break;
            }
        }
        ans[i]=x;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
