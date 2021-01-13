// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// 5) use cout << '\n'; instead of cout << endl; (cout << endl is really slow)
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

int lowerbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;
        if(a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i != 0) cout << " "; cout << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p != begin) cout << " "; cout << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}


struct Node{
    int c; // -1: gray 
    vector<Node*> ch;
};
vvi a;

int color(int x, int y, int n){
    // -1: gray, 0: white, 1: black
    int c = a[x][y];
    repu(i, x, x + n){
        repu(j, y, y+n){
            if(a[i][j] != c) return -1;
        }
    }
    return c;
}

Node* build_tree(int x, int y, int n){
    Node *re = new Node;
    if(n == 1){
        re->c = a[x][y];
        return re;
    }
    else{
        auto gen = [&](int x, int y, int n){
            int c;
            Node *child;
            c = color(x, y, n);
            if(c == -1){    
                child = build_tree(x, y, n);
                child->c = c;
            }
            else{
                child = new Node;
                child->c = c;
            }
            re->ch.push_back(child);
        };
        int c = color(x, y, n);
        re->c = c;
        if(c == -1){
            gen(x, y, n/2);
            gen(x, y+n/2, n/2);
            gen(x+n/2, y, n/2);
            gen(x+n/2, y+n/2, n/2);
        }
        return re;
    }
}

vector<string> res;

void dfs(Node* root, string x){
    if(root->c == -1){
        rep(i, 4){
            dfs(root->ch[i], x + to_string(i + 1));
        }
    }
    else if(root->c == 1){
        res.push_back(x);
    }
}


void img2tree(int n){
    a.clear();
    a.resize(n);
    cin.ignore(100, '\n');
    rep(i, n){
        string x;
        cin >> x;
        each(ch, x){
            a[i].push_back(ch - '0');
        }
    }
    Node * root = build_tree(0, 0, n);
    res.clear();
    dfs(root, "");
    vi re;
    each(x, res){
        int v = 0;
        for(int i = x.size() - 1; i > -1; --i){
            v *= 5;
            v += x[i] - '0';
        }
        re.push_back(v);
    }
    sort(re.begin(), re.end());
    if(re.size()){
        rep(i, re.size()){
            if(i % 12 == 0 and i != 0) cout << "\n";
            if((i) % 12 != 0) cout << " ";
            cout << re[i];   
        }
        cout << "\n";
    }
    cout << "Total number of black nodes = " << re.size() << "\n";
}

void paint(int x, int y, int n, string& base5, int d){
    if(d == base5.size()){
        repu(i, x, x + n){
            repu(j, y, y+n){
                a[i][j] = 1;
            }
        }
    }
    else{
        char ch = base5[d];
        if(ch == '1') paint(x, y, n/2, base5, d + 1);
        if(ch == '2') paint(x, y+n/2, n/2, base5, d + 1);
        if(ch == '3') paint(x+n/2, y, n/2, base5, d + 1);
        if(ch == '4') paint(x+n/2, y+n/2, n/2, base5, d + 1);
    }
}

void tree2img(int n){
    a.clear();
    a.resize(n, vi(n, 0));
    int x;
    while(cin >> x, x != -1){
        if(x==0){
            rep(i, n){
                rep(j, n){
                    a[i][j] = 1;
                }
            }
            continue;
        }
        string base5 = "";
        while(x){
            base5 += x % 5 + '0';
            x /= 5;
        }
        paint(0, 0, n, base5, 0);
    }
    rep(i, n){
        rep(j, n){
            cout << (a[i][j] == 1 ? "*" : ".");
        }
        cout << '\n';
    }
}


void solve(){
    int n;
    int kcase = 0;
    while(cin >> n, n){
        if(kcase != 0) cout << "\n";
        cout << "Image " << ++kcase << "\n";
        if(n > 0){
            img2tree(n);
        }
        else{
            tree2img(abs(n));
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