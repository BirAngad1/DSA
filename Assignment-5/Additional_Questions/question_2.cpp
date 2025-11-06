#include <bits/stdc++.h>
using namespace std;

struct Node{int v;Node*next;Node(int x):v(x),next(NULL){}};

Node* revK(Node*h,int k){
    if(!h||k<=1) return h;
    Node* c=h; for(int i=0;i<k;i++){ if(!c) return h; c=c->next; }
    Node* p=NULL; Node* q=h; int i=0;
    while(q&&i<k){ Node* t=q->next; q->next=p; p=q; q=t; i++; }
    h->next=revK(q,k);
    return p;
}

int main(){
    return 0;
}
