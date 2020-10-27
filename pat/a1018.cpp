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

namespace gf{
    const int maxn = 501, INF = 1e9;
    int N, M, S, E, cmax, Sp;
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
    set<int> pre[maxn];
    queue<int> Q; // queue of node
    int bk_time[maxn]; // times of node in Q

    void init(){
        fill(dis, dis+maxn, INF);
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
                int to = edge.to, newdis = dis[from] + edge.dis;
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


    vector<vector<int>> re; // routes from S to E
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

        for(const auto& from : pre[idx]){
            _dfs(from);
        }

        bk[idx] = 0;
        tmp.pop_back();
    }

    void dfs(int idx){
        // find routes from S to E store in re
        init_dfs();
        _dfs(idx);
    }  

    void arange(const vector<int> &v, int& send, int& take){
        int num = 0;
        send =  take = 0;
        dd(i, v.size()-2, -1){
            #ifdef DEBUG
            pf("check at station %lld\n", v[i]);
            #endif
            int bikes = node[v[i]].d, surplus = bikes - cmax/2;
            if(surplus >= 0) num += surplus;
            else{
                surplus = -surplus; // 
                if(num >= surplus) num -= surplus;
                else{
                    send += (surplus - num);
                    num = 0;
                }
            }
        }
        take = num;
    }
}

struct Path{
    vector<int> path;
    int send, take;
};
vector<Path> path;

bool cmp(const Path& p1, const Path& p2){
    if(p1.send != p2.send) return p1.send < p2.send;
    else return p1.take < p2.take;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> gf::cmax >> gf::N >> gf::Sp >> gf::M;
    gf::S = 0;
    gf::E = gf::Sp;

    uu(i, 1, gf::N+1){
        cin >> gf::node[i].d;
    }

    uu(i, 0, gf::M){
        int x, y, d;
        cin >> x >> y >> d;
        gf::node[x].edge.push_back(gf::Edge(x, y, d));
        gf::node[y].edge.push_back(gf::Edge(y, x, d));
    }
    
    gf::spfa();
    gf::dfs(gf::E);

    #ifdef DEBUG
    pf("dis array:\n");
    uu(i, 0, gf::N){
        cout << gf::dis[i] << " ";
    }
    cout << endl;
    pf("re size = %lu\n", gf::re.size());
    uu(i, 0, gf::re.size()){
        dd(j, gf::re[i].size()-1, -1){
            cout << gf::re[i][j] << " ";
        }
        cout << endl;
    }
    #endif

    uu(i, 0, gf::re.size()){
        int _send, _take;
        gf::arange(gf::re[i], _send, _take);
        Path p;
        p.path = gf::re[i];
        p.send = _send;
        p.take = _take;
        path.push_back(p);
    }

    sort(path.begin(), path.end(), cmp);

    cout << path[0].send << " ";
    dd(i, path[0].path.size()-1, -1){
        if(i == 0) cout << path[0].path[i];
        else cout << path[0].path[i] << "->";
    }
    // cout << " " << mintake;
    cout << " " << path[0].take;







    
    return 0;
}   