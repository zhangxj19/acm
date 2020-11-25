// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x))

using namespace std;
const int maxn = 1e3+1;
int N;

struct Node
{
    int d;
    Node *l, *r;
};

Node* create(){
    Node *root = nullptr;
    return root;
}

void insert(Node* &root, int d){
    if(root == nullptr){
        root = new Node;
        root->d = d;
        root->l = nullptr;
        root->r = nullptr;
    }
    else{
        if(d <= root->d) insert(root->l, d);
        else insert(root->r, d);
    }
}


void inorder(Node *root){
    if(root->l != nullptr) inorder(root->l);

    cout << root->d << " ";

    if(root->r != nullptr) inorder(root->r);
}


map<Node*, int> mp;
int maxdep;
void dep(Node *root, int d){
    if(root == nullptr) return ;
    else{
        mp[root] = d;
        dep(root->l, d+1);
        dep(root->r, d+1);
        maxdep = _max(maxdep, d);
    }
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin  >> N;
    Node *root = create();
    uu(i, 0, N){
        int x;
        cin >> x;
        insert(root, x);
    }
    #ifdef DEBUG
    inorder(root);
    cout <<endl;
    #endif
    dep(root, 0);

    #ifdef DEBUG
    for(auto & node_dep : mp){
        pf("(%d, %d)\n", node_dep.first->d, node_dep.second);
    }
    #endif

    int n1 = 0, n2 = 0;
    queue<Node*> Q;
    set<Node*> S;
    Q.push(root);
    S.insert(root);
    while(!Q.empty()){
        Node * n = Q.front(); Q.pop();
        #ifdef DEBUG
        pf("%d %d\n", n->d, mp[n]);
        #endif
        if(mp[n] == maxdep) n1++;
        if(mp[n] == maxdep-1) n2++;

        if(n->l != nullptr and S.find(n->l) == S.end()){
            Q.push(n->l);
            S.insert(n->l);
        }
        if(n->r != nullptr and S.find(n->r) == S.end()){
            Q.push(n->r);
            S.insert(n->r);
        }
    }
    cout << n1 << " + " << n2 << " = " << n1+n2 << endl;   
    return 0;
}