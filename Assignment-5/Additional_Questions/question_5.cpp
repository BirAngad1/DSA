#include <bits/stdc++.h>
using namespace std;

struct Poly{int c,p;Poly*next;Poly(int C,int P):c(C),p(P),next(NULL){}};

Poly* add(Poly*a,Poly*b){
    Poly d(0,0); Poly* t=&d;
    while(a&&b){
        if(a->p==b->p){
            int s=a->c+b->c;
            if(s) t->next=new Poly(s,a->p), t=t->next;
            a=a->next; b=b->next;
        }else if(a->p>b->p){
            t->next=new Poly(a->c,a->p); t=t->next; a=a->next;
        }else{
            t->next=new Poly(b->c,b->p); t=t->next; b=b->next;
        }
    }
    while(a){ t->next=new Poly(a->c,a->p); t=t->next; a=a->next; }
    while(b){ t->next=new Poly(b->c,b->p); t=t->next; b=b->next; }
    return d.next;
}

int main(){
    return 0;
}
