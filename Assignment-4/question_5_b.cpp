#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int q[100],t=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q[t++]=x;
        for(int j=0;j<t-1;j++){
            int y=q[0];
            for(int k=1;k<t;k++) q[k-1]=q[k];
            q[t-1]=y;
        }
    }
    for(int i=0;i<t;i++) cout<<q[i]<<" ";
    return 0;
}
