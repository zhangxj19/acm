// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// override the () operator
// struct cmp{
//     bool operator()(const T &a, const T &b) const{
//         return ;
//     }
// };
// some useful functions:
// unique(it1, it2) upper_bound(it1, it2) lower_bound(it1, it2) equal_range(it1, it2)
// next_permutation(it1, it2)
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
#include <numeric>
#include <climits>

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

struct UF{
    vi f, sz; // father and component size
    int cnt; // set number 
    UF(int n): cnt(n), f(n), sz(n,1){
        rep(i, n){f[i] = i;}
    }

    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool unite(int x, int y){
        x=find(x), y=find(y);
        if(x==y) return false;
        else{
            if(sz[x] < sz[y]) swap(x, y);
            f[y] = x;
            sz[x] += sz[y];
            cnt--;
            return true;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << endl;}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << endl;}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}
const int maxn = 257;
const int root = 1;

struct Node{ // 1 indexed;
    int d;
    int l, r;
    int have_value;
}node[maxn];
int cnt;
int failed = false;
void newtree(){
    cnt = root;
    node[root].l = node[root].r = 0;
    node[root].have_value = false;
}

int newnode(){
    int u = ++cnt;
    node[u].l = node[u].r = 0;
    node[u].have_value = false;
    return u;
}


void add_node(int v, string s){
    int x = root;
    each(ch, s){
        if(ch == 'L'){
            if(node[x].l == 0) node[x].l = newnode();
            x = node[x].l;
        }
        else if(ch == 'R'){
            if(node[x].r == 0) node[x].r = newnode();
            x = node[x].r;
        }
    }
    if(node[x].have_value) failed = true;
    node[x].d = v;
    node[x].have_value = 1;

}

bool read_input(){
    failed = false;
    int ok = false;
    newtree();

    string s;
    while(cin >> s){
        if(s == "()") break;
        ok = true;
        int idx = s.find(',');
        int v;
        sscanf(s.substr(1, idx-1).c_str(), "%d", &v);
        string ss;
        ss = s.substr(idx+1, s.size()-1-idx);
        add_node(v, ss);
    }


    return ok;

    
}

void solve(){

    while(read_input()){
        
        queue<int> Q;
        Q.push(root);
        vi a;
        int ok = true;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            if(node[x].have_value == 0){
                ok = false;
                break;
            }
            a.push_back(node[x].d);

            if(node[x].l) Q.push(node[x].l);
            if(node[x].r) Q.push(node[x].r);
        }
        if(ok and !failed){
            print(a);
        }
        else cout << "not complete" << endl;
        
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