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
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

vector<vector<pii>> g;

void solve(){
    int n, m;
    while(cin >> n >> m){
        g.clear();
        g.resize(n);
        rep(i, m){
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;
            #ifdef DEBUG
            cout << u << " " << v << " " << c << endl;
            #endif
            g[u].push_back({v, c});
            g[v].push_back({u, c});
        }
        // from 0 to n-1;
        queue<int> que;
        que.push(n-1);
        vector<int> b(n, 0);

        b[n-1] = 1;
        vi dist(n, 0);
        dist[n-1] = 0;
        while(!que.empty()){
            int u = que.front(); que.pop();
            each(x, g[u]){
                int v = x.first;
                if(b[v] == 0){
                    b[v] = 1;
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
            }
        }

        #ifdef DEBUG
        print(dist);
        #endif

        queue<pii> nq;
        b.clear(); b.resize(n, 0);

        vi re;
        nq.push({0, 0}); // index and depth
        b[0] = 1;
        const int inf = (int) 1e9+1;
        vector<int> minc(n, inf); // minc along depth
        each(v, g[0]){   
            minc[0] = min(minc[0], v.second); // dep at 0 min color
        }
        while(!nq.empty()){
            int u = nq.front().first, d = nq.front().second; nq.pop();
            // if(u == n-1) break;

            
            each(x, g[u]){ // v are all the nodes that are depth + 1
                int v = x.first, c = x.second;
                if(c == minc[d] and b[v] == 0 and dist[v] == dist[u] - 1){
                    b[v] = 1;
                    nq.push({v, d+1});

                    // v is added to nq;
                    each(xx, g[v]){
                        int w = xx.first, c = xx.second;
                        if(dist[w] == dist[v] - 1 and b[w] == 0)
                            minc[d+1] = min(minc[d+1], c);
                    }

                }
            }
        }

        cout << dist[0] << '\n';
        // rep(i, dist[0]){
        //     if(i != 0) cout << " ";
        //     cout << minc[i];
        // }
        for(int i = 0; minc[i] != inf; ++i){
            if(i != 0) cout << " ";
            cout << minc[i];
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