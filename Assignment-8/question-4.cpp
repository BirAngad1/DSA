#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr){}
};

Node* build(const vector<int>& a){
    if(a.empty() || a[0] == -1) return nullptr;

    Node* r = new Node(a[0]);
    queue<Node*> q;
    q.push(r);

    int i = 1;
    while(!q.empty() && i < (int)a.size()){
        Node* cur = q.front();
        q.pop();

        if(i < (int)a.size() && a[i] != -1){
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;

        if(i < (int)a.size() && a[i] != -1){
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return r;
}

vector<int> rightView(Node* root){
    vector<int> res;
    if(!root) return res;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            Node* n = q.front();
            q.pop();

            if(i == sz - 1) res.push_back(n->val);

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        Node* root = build(a);

        vector<int> ans = rightView(root);

        for(int i = 0; i < ans.size(); i++){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}

