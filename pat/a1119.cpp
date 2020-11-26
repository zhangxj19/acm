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


int N;
vector<int> pre, post;

struct Node{
    int d;
    Node *l, *r;
    Node(int d, Node *l=nullptr, Node *r=nullptr):d(d), l(l), r(r){};
};

int isunique = true;


Node *build(int pl, int pr, int pol, int por){

    if(pl > pr or pol > por) return nullptr;
    #ifdef DEBUG
    pf("(%d, %d), (%d, %d)\n", pl ,pr, pol , por);
    uu(i, pl, pr+1) cout << pre[i] << " ";
    cout << endl;
    uu(i, pol, por+1) cout << post[i] << " ";
    cout << endl;
    #endif
    Node* n = new Node(pre[pl]);
    if(pl == pr){        
        return n;
    }
    else{
        if(pr - pl == 1){ // 2 elements
            // n->l = build(pl+1, pl+1, pol, pol);
            n->l = nullptr;
            n->r = new Node(pre[pl+1]);
            isunique = false;           
        }
        else{
            int k = 1;
            int Rroot = post[por-1];
            // for(int i = pl+1; i <= pr; ++i){
            for(int i = pr; i > pl; --i){
                if(pre[i] == Rroot){
                    k = i - pl - 1;
                    break;
                }
            }
            n->l = build(pl+1, pl+k, pol, pol+k-1);
            n->r = build(pl+k+1, pr, pol+k, por-1);
        }
        return n;
    }
}

vector<int> re;

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->l);
    re.push_back(root->d);
    inorder(root->r);
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
    cin >> N;
    pre.resize(N);
    post.resize(N);
    uu(i, 0, N) cin >> pre[i];
    uu(i, 0, N) cin >> post[i];
    
    Node * root = build(0, N-1, 0, N-1);

    if(isunique) cout << "Yes" << endl;
    else cout << "No" << endl;

    inorder(root);

    uu(i, 0, re.size()){
        if(i == 0) cout << re[i];
        else cout << " " << re[i];
    }
    cout << endl;

    return 0;
}