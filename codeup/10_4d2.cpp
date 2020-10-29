// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

const int maxn = 1010, maxm = 1e4+10, INF = 0x3fffffff;
typedef pair<int, int> P;
ll n, m, s, t;

struct Edge{
    ll f, t, d;
    Edge(ll f, ll t, ll d):f(f), t(t), d(d){};
};

struct Node{
    ll d;
    vector<Edge> edge;
}node[maxn];

ll bk[maxn], d[maxn], pre[maxn];

struct cmp{
    bool operator () (const ll &i1, const ll &i2){
        if(bk[i1] != bk[i2]) return bk[i1] > bk[i2];
        else return d[i1] > d[i2];
    }
};

ll nextu(){
    ll re = -1, mindis = INF;
    uu(i, 1, n+1){
        if(d[i] < mindis and bk[i] == 0){
            mindis = d[i];
            re = i;
        }
    }
    if(re != -1) bk[re] = 1;
    return re;
}

void dijkstra(){
    memset(bk, 0, sizeof(bk));
    fill(d, d+maxn, INF);
    uu(i, 1, n+1) pre[i] = i;
    d[s] = 0;

    // priority_queue<ll, vector<ll>, cmp> pq;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(d[s], s));
    // uu(i, 1, n+1){
    while(!pq.empty()){
        // if(pq.empty()) return;
        P p = pq.top(); pq.pop();
        int from =p.second;
        // ll from = nextu();
        if(from == -1) return;
        for(const auto& edge: node[from].edge){
            ll to = edge.t, newdis = d[from] + edge.d;
            if(bk[to] == 0){
                if(newdis < d[to]){
                    d[to] = newdis;
                    
                    pre[to] = from;
                    pq.push(make_pair(d[to], to));
                }
                else if (newdis == d[to] and from < pre[to]){
                    pre[to] = from;
                }
            }

        }
    }
}

void dfs(ll idx){

    if(idx == s){
        // cout << idx << " ";
        pf("%lld ",idx);
        return ;
    }

    dfs(pre[idx]);
    // cout << idx << " ";
    printf("%lld ", idx);

    return ;
}   

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(~sf("%lld%lld%lld%lld", &n, &m, &s, &t)){
        uu(i, 1, n+1){
            node[i].edge.clear();
        }
        uu(i, 0, m){
            ll x, y, d;
            // cin >> x >> y >> d;
            scanf("%lld %lld %lld",&x,&y,&d);
            node[x].edge.push_back(Edge(x, y, d));
            node[y].edge.push_back(Edge(y, x, d));
        }

        dijkstra();

        #ifdef DEBUG
        pf("resize = %zu\n", re.size());
        for(const auto& v : re){
            for(const auto& e : v){
                pf("%d ", e);
            }
            pf("\n");
        }
        #endif
        if(d[t] == INF){
            // cout << "can't arrive" << endl;
            pf("can't arrive\n");
        }
        else{
            // cout << d[t] << endl;
            printf("%lld\n",d[t]);
            dfs(t);
            printf("\n");
            // cout << endl;
        }
    }
    

    
    return 0;
}