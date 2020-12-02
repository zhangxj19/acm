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
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;
const int maxn = 1e4+1;

int M, N;

struct Node{
    int d;
    Node *l, *r;
};
Node * root, *an;

vector<int> pre;

Node * build(int pl, int pr){
    if(pl > pr) return nullptr;
    Node *root = new Node;
    root->d = pre[pl];
    root->l = nullptr;
    root->r = nullptr;
    if(pl == pr) return root;
    else{
        int x = pl+1;
        while(x <= pr and pre[x] < pre[pl]) x++;
        root->l = build(pl+1, x-1);
        root->r = build(x, pr);
        return root;
    }
}

Node * find(Node *x, int d){
    if(x == nullptr) return nullptr;
    else{
        if(d == x->d) return x;
        else if(d < x->d) return find(x->l, d);
        else return find(x->r, d);
    }
}

void dfs(Node* root, int x, int y){
    if(root == nullptr) return;
    int d = root->d;
    if(x == d or y == d) an = root;
    else{
        if(x < d and y < d){
            dfs(root->l, x, y);
            return;
        }
        if(x > d and y > d){
            dfs(root->r, x, y);
            return;
        }
        if(x < d and y > d){
            an = root;
            return;
        }
        if(x > d and y < d){
            an = root;
            return;
        }
    }
}

void ancester(Node *x, Node *y){
    dfs(root, x->d, y->d);
}

#ifdef DEBUG
void level(Node *root){
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *x = Q.front(); Q.pop();

        cout << x->d << " ";

        if(x->l) Q.push(x->l);
        if(x->r) Q.push(x->r);
    }
    cout << endl;
}
#endif

void solve(){
    cin >> M >> N;
    pre.resize(N);
    uu(i, 0, N) cin >> pre[i];

    root = build(0, N-1);
    #ifdef DEBUG2
    level(root);
    #endif


    while(M--){
        int x, y;
        cin >> x >> y;
        Node *rx, *ry;
        rx = find(root, x);
        ry = find(root, y);
        if(rx == nullptr and ry == nullptr){
            cout << "ERROR: " << x << " and " << y << " are not found." << endl;
        }
        else if(rx == nullptr and ry != nullptr){
            cout << "ERROR: " << x << " is not found." << endl;
        }
        else if(rx != nullptr and ry == nullptr){
            cout << "ERROR: " << y << " is not found." << endl;
        }
        else{
            ancester(rx, ry);
            if(an == rx){
                cout << x << " is an ancestor of " << y << "." << endl;
            }
            else if(an == ry){
                cout << y << " is an ancestor of " << x << "." << endl;
            }
            else{
                cout << "LCA of " << x << " and " << y << " is " << an->d << "." << endl;
            }
        }
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
    solve();
    
    return 0;
}