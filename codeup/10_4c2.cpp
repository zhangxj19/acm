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

const int maxn = 1e2 + 1, maxm =  5*1e2+1, INF = 1e9, P = 1e5;

int n , m;

struct Edge{
    int f, t, d;
    Edge(int f, int t, int d):f(f), t(t), d(d){}
};
vector<Edge> edge;

struct Node
{
    int d;
    vector<int> edge;
}node[maxn];

void addedge(int from, int to, int d){
    node[from].edge.push_back(edge.size());
    edge.push_back(Edge(from, to, d));
}

int f[maxn];

int findf(int x){
    if(f[x] == x) return x;
    else {
        int F = findf(f[x]);
        f[x] = F;
        return F;
    }
}

void Union(int x, int y){
    int fx = findf(x), fy = findf(y);
    if(fx != fy){
        f[y] =fx;
    }
}

int _pow(int k){
    int re = 1;
    uu(i, 0, k) re = (re * 2) % P;
    return re;
}

int bk[maxn], d[maxn];
typedef pair<int, int> pii;
void dij(){
    // memset(bk, 0, sizeof(bk));
    fill(d, d+maxn, INF);
    d[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(d[0], 0));

    while(!pq.empty()){
    // uu(i, 0, n){
        pii p = pq.top(); pq.pop();
        int from = p.second;
        // int from=-1, mind = INF;
        // uu(i, 0, n) if(d[i] < mind and bk[i] == 0) mind = d[from=i];
        // if(from == -1) break;
        // bk[from] = 1;

        for(const auto & id : node[from].edge){
            int to = edge[id].t, newdis = d[from] + edge[id].d;
            #ifdef DEBUG
            pf("f=%d, t=%d\nd[from]=%d\nedge.d=%d\nnewdis=%d\n", from, to, d[from], edge[id].d, newdis);
            #endif
            if(newdis < d[to]){
                d[to] = newdis;
                pq.push(make_pair(d[to], to));
            }
        }
    }

}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n >> m){

        // init for union 
        edge.clear();
        uu(i, 0, n){
            f[i] = i;            
            node[i].edge.clear();
        }

        uu(i, 0, m){
            int x, y;
            cin >> x >> y;
            int fx = findf(x), fy = findf(y);
            if(fx != fy){
                addedge(x, y, _pow(i));
                addedge(y, x, _pow(i));
                Union(x, y);
            }
            else{
                continue;
            }
        }

        dij();
        #ifdef DEBUG
        cout << "dis" << endl;
        uu(i, 0, n){
            cout << d[i] << endl;
        }
        #endif
        uu(i, 1, n){
            if(d[i] == INF) cout << -1 << endl;
            else cout << d[i]%P << endl;
        }
    }
    
    return 0;
}