#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int A[100], B[100], top=-1, idx=0;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++){
        top++;
        B[top]=A[i];
        while(top>=0 && (idx==0 || B[top]>=B[idx-1])){
            B[idx]=B[top];
            top--;
            idx++;
        }
    }
    int ok=1;
    for(int i=1;i<idx;i++){
        if(B[i]<B[i-1]) ok=0;
    }
    if(ok) cout<<"YES"; else cout<<"NO";
    return 0;
}
