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

    void init_bf(){
        fill(dis, dis+maxn, INT_MAX);
        dis[S] = 0;
    }

    bool bf(){ // bellman-ford
        init_bf();
        // N-1 round
        uu(i, 0, N-1){
            // all edges
            int islose = false;
            uu(from, 0, N){
                for(const auto & edge : node[from].edge){
                    ll to = edge.to, newdis = dis[from] + edge.dis;
                    if(newdis < dis[to]){
                        dis[to] = newdis;
                        pre[to].clear();
                        pre[to].insert(from);
                        islose = true;
                    }
                    else if(newdis == dis[to]){
                        pre[to].insert(from);
                        islose = true;
                    }
                }
            }
            if(!islose) break;
        }

        uu(i, 0, N){
            uu(j, 0, node[i].edge.size()){
                ll from = node[i].edge[j].from, to = node[i].edge[j].to, d = node[i].edge[j].dis;
                ll newdis = dis[from] + d;
                if(newdis < dis[to]){
                    return false; // negative cycle from S
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
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    
    return 0;
}