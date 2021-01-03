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
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << endl;}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << endl;}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

struct Edge{
    int from, to, t;
    Edge(int from, int to, int t):from(from), to(to), t(t){}
};
vector<Edge> edge;

struct Node{
    vector<int> edgeid;
};
vector<Node> node;

void add_edge(int from, int to, int t){
    node[from].edgeid.push_back(edge.size());
    edge.push_back(Edge(from, to ,t));
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    rep(i, m){
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        // g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
        // add_edge(u, v, t);
    }

    const int inf = (int) 1e9;
    // priority_queue<pii, vector<pii>, greater<pii>> pq; // distance and index
    
    vector<vector<int>> dist(n, {inf, inf});
    // dist[0][0] = dist[0][1] = 0;
    dist[n-1][0] = dist[n-1][1] = 0;

    // pq.emplace(0, 0);    
    set<pii> s;
    // s.emplace(0, 0); // distance and index;
    s.emplace(0, n-1);

    // s中放入抵达x点的最大距离(两种颜色取最大值)
    // 从s中取出距离最小的点x; 
    // 从x点出发抵达y点,x到y可能有不同的颜色,抵达后刷新以不同颜色
    // 抵达y点的距离,s中持续放入抵达y点的最大距离.
    // dijkstra结束后查看以不同颜色抵达城市最大距离,
    // 若0色抵达大给其涂0,反之涂1色.
    // Q:为什么需要反向dijkstra?
    // A:原题中是从x出发到y,x和路径颜色一致.反向以后从x出发到y,
    //   y和路径颜色一致, 根据抵达y的不同颜色方案选出最大值可以给y
    //   染色.
    while(!s.empty()){
        int d = s.begin()->first;  // 维持d为抵达i城最大路径(白黑两种情况)
                                    // d == max(dist[i][0], dist[i][1])
        int i = s.begin()->second;
        s.erase(s.begin());
        each(p, g[i]){
            int j = p.first;
            int t = p.second;
            if(d + 1 < dist[j][t]){ // 以颜色t到达j点可以松弛
                auto it = s.find(make_pair(max(dist[j][0], dist[j][1]), j)); // 删除j点最大值
                if(it != s.end()) s.erase(it);
                dist[j][t] = d + 1;
                s.emplace(max(dist[j][0], dist[j][1]), j); // s中放入抵达j点的最大距离
            }
        }
    }
    // int d = max(dist[n-1][0], dist[n-1][1]);
    int d = max(dist[0][0], dist[0][1]);
    cout << (d == inf ? -1 : d) << '\n';
    rep(i, n){
        cout << (dist[i][0] > dist[i][1] ? '0' : '1');
    }
    cout << '\n';



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