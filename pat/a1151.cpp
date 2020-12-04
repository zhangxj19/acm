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


int M, N;

struct Node{
    int d;
    Node *l, *r;
};
Node *root;
vector<int> in, pre;
unordered_map<int, int> position; // value to position of inorder

Node *build(int il, int ir, int pl, int pr){
    if(il > ir) return nullptr;
    Node * root = new Node;
    root->d = pre[pl];
    root->l = nullptr;
    root->r = nullptr;
    if(il == ir) return root;
    else{
        int x = il, k;
        while(x <= ir and in[x] != pre[pl]) x++;
        k = x - il;
        root->l = build(il, x-1, pl+1, pl+k);
        root->r = build(x+1, ir, pl+k+1, pr);
        return root;
    }
}


Node *find(Node* root, int x){

    if(root == nullptr) return nullptr;
    else{
        if(root->d == x){
            return root;
        }
        else{
            int pox = position[x], por = position[root->d];
            int lx = pox < por, rx = pox > por;
            if(lx) return find(root->l, x);
            else return find(root->r, x);
            // Node * n = find(root->l, x);
            // if(n != nullptr){

            //     return n;
            // }
            // n = find(root->r, x);
            // return n;
        }
    }
}

Node *an;

Node *LCA(Node *root, Node *x, Node *y){
    if(root == x or root == y){
        an = root;
        return an;
    }
    else{
        
        // Node *lx = find(root->l, x->d);
        // Node *rx = find(root->r, x->d);
        // Node *ly = find(root->l, y->d);
        // Node *ry = find(root->r, y->d);
        int pox = position[x->d], poy = position[y->d], por = position[root->d];
        int lx = pox < por, ly = poy < por;
        int rx = pox > por, ry = poy > por;

        if(lx and ly){
            LCA(root->l, x, y);
        }
        else if(rx and ry){
            LCA(root->r, x, y);
        }
        else if((lx and ry) or (ly and rx)){
            an = root;
        }
        // int lx, rx, ly, ry;
        // lx = (mp.find(root->l->d) == mp.end()) ? -1 : mp[]

        return an;
    }
}



void solve(){
    cin >> M >> N;
    in.resize(N);
    pre.resize(N);

    uu(i, 0, N){
        cin >> in[i];  
        position[in[i]] = i;
    }
    uu(i, 0, N) cin >> pre[i];
    root = build(0, N-1, 0, N-1);

    #ifdef DEBUG
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *x = Q.front(); Q.pop();
        cout << x->d << " ";

        if(x->l != nullptr) Q.push(x->l);
        if(x->r != nullptr) Q.push(x->r);
    }
    cout << endl;
    #endif

    while(M--){
        int x, y;
        cin >> x >> y;
        Node *nx = find(root, x), *ny = find(root, y);
        if(nx == nullptr and ny == nullptr){
            cout << "ERROR: " << x << " and " << y << " are not found." << endl;
        }
        else if(nx == nullptr and ny != nullptr){
            cout << "ERROR: " << x << " is not found." << endl;
        }
        else if(nx != nullptr and ny == nullptr){
            cout << "ERROR: " << y << " is not found." << endl;
        }
        else{
            LCA(root, nx, ny);
            if(an == nx){
                cout << x << " is an ancestor of " << y << "." << endl;
            }
            else if(an == ny){
                cout << y << " is an ancestor of " << x << "." << endl;
            }
            else{
                cout << "LCA of "<< x << " and " << y << " is " << an->d << "." << endl;
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