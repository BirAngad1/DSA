#include <bits/stdc++.h>
using namespace std;

struct Node{int v;Node*next;Node(int x):v(x),next(NULL){}};

Node* rotateLeft(Node*h,int k){
    if(!h||!h->next||k==0) return h;
    int n=1; Node* t=h;
    while(t->next){ t=t->next; n++; }
    k%=n; if(k==0) return h;
    t->next=h;
    Node* p=h; for(int i=1;i<k;i++) p=p->next;
    Node* nh=p->next; p->next=NULL;
    return nh;
}

int main(){
    return 0;
}
