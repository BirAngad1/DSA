#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    while(i<n){
        if(arr[i]==2){
            for(int j=n-1;j>i;j--) arr[j]=arr[j-1];
            if(i+1<n) arr[i+1]=2;
            i+=2;
        } else i++;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
