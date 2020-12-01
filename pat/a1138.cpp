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

int N;

vector<int> pre, in;


struct Node{
    int d;
    Node *l, *r;
};

Node * build(int pl, int pr, int il, int ir){
    if(pl > pr) return nullptr;
    Node *root  = new Node;
    root->d = pre[pl];
    root->l = nullptr;
    root->r = nullptr;
    if(pl == pr){
        return root;
    }
    else{
        int x = il;
        while(x <= ir and in[x] != pre[pl]) x++;

        int k = x - il;
        root->l = build(pl+1, pl+k, il, x-1);
        root->r = build(pl+k+1, pr, x+1, ir);
        return root;
    }
}


vector<int> re;

void post(Node * root){
    if(root == nullptr) return ;
    post(root->l);

    post(root->r);

    re.push_back(root->d);

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
    in.resize(N);
    uu(i, 0, N) cin >> pre[i];
    uu(i, 0, N) cin >> in[i];

    Node *root = nullptr;
    root = build(0, N-1, 0, N-1);
    post(root);

    cout << re[0] << endl;


    
    return 0;
}