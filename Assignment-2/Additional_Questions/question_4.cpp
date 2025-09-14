#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) c0++;
        else if(arr[i]==1) c1++;
        else c2++;
    }
    for(int i=0;i<c0;i++) cout<<0<<" ";
    for(int i=0;i<c1;i++) cout<<1<<" ";
    for(int i=0;i<c2;i++) cout<<2<<" ";
    return 0;
}
