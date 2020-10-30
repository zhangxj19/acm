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
const int maxn = 1e3+1, maxm = 1e5+1, INF = 1e9;
int n, m, s, t, bk[maxn], d[maxn], cost[maxn];
vector<int> pre[maxn];

struct Edge{
    int f, t, d, p;
    Edge(int f, int t, int d, int p):f(f), t(t), d(d), p(p){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];

typedef pair<int, int> P;

void Dijkstra(){
    // init is done 
    memset(bk, 0, sizeof(bk));
    fill(cost, cost+maxn, INF);
    cost[s] = 0;
    fill(d, d+maxn, INF);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(d[s], s));
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int from = p.second;
        for(const auto & edge: node[from].edge){
            int to = edge.t, newdis = d[from] + edge.d;
            if(newdis < d[to]){
                d[to] = newdis;
                cost[to] = cost[from] + edge.p;
                pq.push(make_pair(d[to], to));

                // pre[to].clear();
                // pre[to].push_back(from);
            }
            else if(newdis == d[to]){
                cost[to] = _min(cost[from] + edge.p, cost[to]);
                // pre[to].push_back(from);
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
    while(cin >> n >> m, n & m){
        uu(i, 1, n+1) node[i].edge.clear();
        uu(i, 0, m){
            int a, b, d, p;
            cin >> a >> b >> d >> p;
            node[a].edge.push_back(Edge(a, b, d, p));
            node[b].edge.push_back(Edge(b, a, d, p));
        }
        cin >> s >> t;
        
        Dijkstra();

        #ifdef DEBUG
        uu(i, 1, n+1){
            cout << d[i] << " ";
        }
        cout << endl;
        #endif
        cout << d[t] << " " << cost[t] << endl;

        // dfs(t);

        // int mincost = INF;
        // uu(i, 0, re.size()){                
        //     int cost = sumcost(re[i]);
        //     mincost = _min(cost, mincost);
        // }
        // cout << d[t] << " " << mincost << endl; 


    }











    

    return 0;
}