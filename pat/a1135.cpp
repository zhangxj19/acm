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

int K, N;

vector<int> a;

struct Node{
    int d;
    Node *l, *r;
};

Node *build(int l, int r){
    if(l > r) return nullptr;
    if(l == r){
        Node *root = new Node;
        root->d = a[l];
        root->l = nullptr;
        root->r = nullptr;
        return root;
    }
    else{
        Node *root = new Node;
        root->d = a[l];
        int x = l+1;
        while(x <= r and abs(a[l]) > abs(a[x])) x++;
        
        root->l = build(l+1, x-1);
        root->r = build(x, r);

        return root;
    }
}

int no2red(Node * root){
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *x = Q.front(); Q.pop();

        if(x->d < 0){
            if(x->l != nullptr and x->l->d < 0) return false;
            if(x->r != nullptr and x->r->d < 0) return false;
        }

        if(x->l != nullptr) Q.push(x->l);
        if(x->r != nullptr) Q.push(x->r);
    }

    return true;
}


int issameblack;

int cnt_black(Node *root){ // root, 0
    if(root == nullptr) return 1;
    else{
        int l = cnt_black(root->l), r = cnt_black(root->r);
        #ifdef DEBUG
        pf("%d lh = %d, rh = %d\n", root->d, l, r );
        #endif
        if(l != r) issameblack = false;

        return l+(root->d > 0);
    }
}


void level(Node * root){
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *x = Q.front(); Q.pop();

        cout << x->d << " ";

        if(x->l != nullptr) Q.push(x->l);
        if(x->r != nullptr) Q.push(x->r);
    }
    cout << endl;
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
    cin >> K;
    while(K--){
        cin >> N;
        a.resize(N, 0);
        uu(i, 0, N) cin >> a[i];

        Node *root = build(0, N-1);
        #ifdef DEBUG
        level(root);
        #endif
        issameblack = 1;

        // The root is black.
        if(root->d < 0){
            cout << "No" << endl;
            #ifdef DEBUG
            cout << "root is not black" << endl;
            #endif
            continue;
        }
        // If a node is red, then both its children are black.
        if(!no2red(root)){
            cout << "No" << endl;
            #ifdef DEBUG
            cout << "red have red children" << endl;
            #endif
            continue;           
        }

        // Every leaf (NULL) is black.
        // For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
        cnt_black(root);
        if(!issameblack){
            cout << "No" << endl;
            #ifdef DEBUG
            cout << "black height is not same" << endl;
            #endif
            continue;          
        }

        cout << "Yes" << endl;

    }

    
    
    return 0;
}