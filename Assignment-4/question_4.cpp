#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int freq[256]={0};
    for(int i=0;i<s.size();i++){
        freq[(int)s[i]]++;
        char ans='-';
        for(int j=0;j<=i;j++){
            if(freq[(int)s[j]]==1){
                ans=s[j];
                break;
            }
        }
        if(ans=='-') cout<<"-1 ";
        else cout<<ans<<" ";
    }
    return 0;
}
