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

string sub(string x, string y){
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string re;
    int c = 0, i = 0;
    for(i = 0; i < min(x.size(), y.size()); ++i){
        int a = x[i] - '0';
        int b = y[i] - '0';
        int r = a + c - b;
        c = 0;
        if(r < 0){
            c -= 1;
            r += 10;
        }
        re += to_string(r);
    }
    while(i < x.size()){
        int a = x[i] - '0';
        int r = a + c - 0;
        c = 0;
        if(r < 0){
            c -= 1;
            r += 10;
        }
        re += to_string(r);
        ++i;
    }
    while(re.back() == '0'){
        re.pop_back();
    }
    reverse(re.begin(), re.end());
    return re;
}

void solve(){
    int t;
    cin >> t;
    string s = "9876543210";
    while(t--){
        int n;
        cin >> n;
        if(n == 1) cout << '9';
        else if(n == 2) cout << "98";
        else{
            int x = 9;
            cout << "98";
            rep(i, n-2){
                cout << x;
                x += 1;
                x %= 10;
            }
        }
        cout << '\n';
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