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

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

namespace gf{
    const ll maxn = 500;
    ll N, M, S, E;
    struct Edge{
        ll dis, cost;
        ll from, to;
        Edge(ll from, ll to, ll dis=0, ll cost=0):from(from), to(to), dis(dis), cost(cost){};
    };

    struct Node{
        ll d;
        vector<Edge> edge;
    }node[maxn];

    ll bk[maxn], dis[maxn];
    set<ll> pre[maxn];
    queue<int> Q; // queue of node
    ll bk_time[maxn]; // times of node in Q

    void init(){
        fill(dis, dis+maxn, INT_MAX);
        dis[S] = 0;
        memset(bk, 0, sizeof(bk));
        memset(bk_time, 0, sizeof(bk_time));
        while(!Q.empty()) Q.pop();
    }

    bool spfa(){ // bellman-ford
        init();
        // N-1 round
        Q.push(S);
        bk[S] = 1;
        bk_time[S]++;
        while(!Q.empty()){
            int from = Q.front(); Q.pop();
            bk[from] = 0;

            for(const auto & edge : node[from].edge){
                ll to = edge.to, newdis = dis[from] + edge.dis;
                if(newdis < dis[to]){
                    dis[to] = newdis;
                    pre[to].clear();
                    pre[to].insert(from);
                    if(bk[to] == 0){
                        bk[to] = 1;
                        bk_time[to]++;
                        if(bk_time[to] > N-1) return false; // have negative cycle from S
                        Q.push(to);
                    }
                }
                else if(newdis == dis[to]){
                    pre[to].insert(from);
                }
            }
        }
        return true;
    }


    vector<vector<ll>> re; // routes from S to E
    vector<ll> tmp;

    void init_dfs(){
        memset(bk, 0, sizeof(bk));
    }

    void _dfs(ll idx){
        bk[idx] = 1;
        tmp.push_back(idx);
        if(pre[idx].size() == 0){
            re.push_back(tmp);
            bk[idx] = 0;
            tmp.pop_back();
            return ;
        }

        for(const auto& from : pre[idx]){
            _dfs(from);
        }

        bk[idx] = 0;
        tmp.pop_back();
    }

    void dfs(ll idx){
        // find routes from S to E store in re
        init_dfs();
        _dfs(idx);
    }  

    ll sumteam(vector<ll> &v){
        ll re = 0;
        uu(i, 0, v.size()){
            re += node[v[i]].d;
        }
        return re;
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> gf::N >> gf::M >> gf::S >> gf::E;
    uu(i, 0, gf::N){
        cin >> gf::node[i].d;
    }  

    uu(i, 0, gf::M){
        int x, y, l;
        cin >> x >> y >> l;
        gf::node[x].edge.push_back(gf::Edge(x, y, l));
        gf::node[y].edge.push_back(gf::Edge(y, x, l));
    }

    gf::spfa();
    gf::dfs(gf::E);

    cout << gf::re.size();
    cout << " ";
    int maxteam = INT_MIN;
    uu(i, 0, gf::re.size()){
        int team = gf::sumteam(gf::re[i]);
        maxteam = _max(team, maxteam);
    }
    cout << maxteam << endl;
    
    return 0;
}