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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

namespace gf{ // graph
    const ll maxn = 510;

    ll N, M, S, E;
    struct Edge{
        ll dis, cost;
        ll from, to;
        Edge(ll from, ll to, ll dis){
            this->from = from;
            this->to = to;
            this->dis = dis;
        }
    };

    struct Node{
        ll d;
        vector<Edge> edge;
    }node[maxn];

    ll bk[maxn], dis[maxn];
    vector<ll> pre[maxn];

    ll num[maxn], w[maxn];
    void init_bf(){
        fill(dis, dis+maxn, INT_MAX);
        dis[S] = 0;
        memset(num, 0, sizeof(num));
        num[S] = 1;
        memset(w, 0, sizeof(w));
        w[S] = node[S].d;
    }

    set<ll> pre_bf[maxn];
    
    bool bf(){
        init_bf();
        // N-1 round
        uu(i, 0, N-1){
            // all edges
            int islose = false;
            uu(from, 0, N){
                for(const auto & edge : node[from].edge){
                    ll to = edge.to, d = edge.dis;
                    if(dis[from] + d < dis[to]){
                        dis[to] = dis[from] + d;

                        pre_bf[to].clear();
                        pre_bf[to].insert(from);
                        islose = true;
                    }
                    else if(dis[from] + d == dis[to]){
                        pre_bf[to].insert(from);
                        islose = true;
                    }
                }
            }
            if(!islose) break;
        }

        uu(i, 0, N){
            pre[i].clear();
            for(const auto& it : pre_bf[i]){
                pre[i].push_back(it);
            }
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

    vector<vector<int>> re;
    vector<int> tmp;

    void init_dfs(){
        memset(bk, 0, sizeof(bk));
    }

    void _dfs(int idx){
        bk[idx] = 1;
        tmp.push_back(idx);
        if(pre[idx].size() == 0){
        // if(pre_bf[idx].size() == 0){
            re.push_back(tmp);
            bk[idx] = 0;
            tmp.pop_back();
            return ;
        }

        uu(i, 0, pre[idx].size()){
        // for(const auto from : pre_bf[idx]){
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

    gf::bf();
    gf::dfs(gf::E);

    cout << gf::re.size();
    cout << " ";
    int maxteam = INT_MIN;
    uu(i, 0, gf::re.size()){
        int team = gf::sumteam(gf::re[i]);
        maxteam = _max(team, maxteam);
    }
    cout << maxteam << endl;
    #ifdef DEBUG
    uu(i, 0, gf::N){
        pf("%d ", gf::dis[i]);
    }
    cout << endl;
    uu(i, 0, gf::N){
        pf("%d ", gf::num[i]);
    }
    cout << endl;
    uu(i, 0, gf::N){
        pf("%d ", gf::w[i]);
    }
    cout << endl;
    #endif

    // cout << gf::num[gf::E] << " " << gf::w[gf::E];


    
    return 0;
}