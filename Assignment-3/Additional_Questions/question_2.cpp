#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    int minv=arr[0];
    for(int i=1;i<n;i++) if(arr[i]<minv) minv=arr[i];
    cout<<minv;
    return 0;
}
