#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int q[100];
    for(int i=0;i<n;i++) cin>>q[i];
    int mid=n/2;
    for(int i=0;i<mid;i++){
        cout<<q[i]<<" "<<q[mid+i]<<" ";
    }
    if(n%2==1) cout<<q[n-1];
    return 0;
}
