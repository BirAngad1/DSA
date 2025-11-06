#include <bits/stdc++.h>
using namespace std;

struct Node{int v;Node*next;Node(int x):v(x),next(NULL){}};

void removeLoop(Node* h){
    if(!h) return;
    Node* s=h,*f=h;
    while(f&&f->next){ s=s->next; f=f->next->next; if(s==f) break; }
    if(!(f&&f->next)) return;
    s=h;
    while(s!=f){ s=s->next; f=f->next; }
    Node* x=f;
    while(x->next!=s) x=x->next;
    x->next=NULL;
}

int main(){
    return 0;
}
