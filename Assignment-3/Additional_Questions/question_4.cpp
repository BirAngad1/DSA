#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int t[100], ans[100];
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++){
        int d=0;
        for(int j=i+1;j<n;j++){
            if(t[j]>t[i]){
                d=j-i;
                break;
            }
        }
        ans[i]=d;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
