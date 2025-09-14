#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int q1[100],q2[100],t1=0,t2=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q2[t2++]=x;
        while(t1>0){
            q2[t2++]=q1[0];
            for(int j=1;j<t1;j++) q1[j-1]=q1[j];
            t1--;
        }
        for(int j=0;j<t2;j++) q1[j]=q2[j];
        t1=t2;
        t2=0;
    }
    for(int i=0;i<t1;i++) cout<<q1[i]<<" ";
    return 0;
}
