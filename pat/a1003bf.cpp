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

namespace gf{ // graph
    const int maxn = 500;
    int N, M, S, E;
    struct Edge{
        int dis, cost;
        int from, to;
        Edge(int from, int to, int dis=0, int cost=0):from(from), to(to), dis(dis), cost(cost){};
    };

    struct Node{
        int d;
        vector<Edge> edge;
    }node[maxn];

    int bk[maxn], dis[maxn];
    vector<int> pre[maxn];

    int nextu(){
        // if re == -1 then no u find
        int re = -1, mind = INT_MAX;
        uu(i, 0, N){
            if(bk[i] == 0 and dis[i] < mind){
                mind = dis[i];
                re = i;
            }
        }
        bk[re] = 1;
        return re;
    }

    void init_Dijkstra(){
        //init bk
        memset(bk, 0, sizeof(bk));
        // init dis, dis[0:end] = INT_MAXN, dis[S] = 0
        uu(i, 0, N) dis[i] = INT_MAX;
        // pre don't need to init;
        dis[S] = 0;
    }

    void Dijkstra(){
        init_Dijkstra();
        uu(i, 0, N){
            int u = nextu();
            uu(j, 0, node[u].edge.size()){
                int to = node[u].edge[j].to;
                int newdis = dis[u] + node[u].edge[j].dis;
                if(newdis < dis[to]){
                    dis[to] = newdis;
                    pre[to].clear();
                    pre[to].push_back(u);
                }
                else if(newdis == dis[to]){
                    pre[to].push_back(u);
                }
            }
        }
    }
    vector<vector<int>> re;
    vector<int> tmp;

    void init_dfs(){
        memset(bk, 0, sizeof(bk));
    }

    void _dfs(int idx){
        bk[idx] = 1;
        tmp.push_back(idx);
        if(pre[idx].size() == 0){
            re.push_back(tmp);
            bk[idx] = 0;
            tmp.pop_back();
            return ;
        }

        uu(i, 0, pre[idx].size()){
            int from = pre[idx][i];
            _dfs(from);
        }

        bk[idx] = 0;
        tmp.pop_back();
    }

    void dfs(int idx){
        init_dfs();
        _dfs(idx);
    }  


    int sumteam(vector<int> &v){
        int re = 0;
        uu(i, 0, v.size()){
            re += node[v[i]].d;
        }
        return re;
    }
}

const int maxn= 500;


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

    gf::Dijkstra();

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