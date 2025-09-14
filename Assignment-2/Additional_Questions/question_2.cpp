#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n=s.length();
    int ok=0;
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string a=s.substr(0,i);
            string b=s.substr(i,j-i);
            string c=s.substr(j);
            if((a.find(b)!=string::npos)||(b.find(a)!=string::npos)||(c.find(a)!=string::npos)||(c.find(b)!=string::npos)||(a.find(c)!=string::npos)||(b.find(c)!=string::npos)){
                ok=1;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout<<"YES"; else cout<<"NO";
    return 0;
}
