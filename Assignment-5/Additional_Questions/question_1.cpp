#include <bits/stdc++.h>
using namespace std;

struct Node{int v;Node*next;Node(int x):v(x),next(NULL){}};

Node* intersect(Node*a,Node*b){
    if(!a||!b) return NULL;
    Node*p=a,*q=b;
    while(p!=q){p=p?p->next:b;q=q?q->next:a;}
    return p;
}

int main(){
    return 0;
}
