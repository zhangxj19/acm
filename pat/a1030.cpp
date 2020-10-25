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

#define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool equ(double a, double b){
    return fabs(a-b) < eps;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

const int maxn = 500;
int N, M, S, D;

struct Edge{
    int dis, cost;
    int from, to;
    Edge(int from, int to, int dis, int cost):from(from), to(to), dis(dis), cost(cost){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];


int bk[maxn], d[maxn];
vector<int> pre[maxn];

int nextu(){
    // if re == -1 then no u find
    int re = -1, mind = INT_MAX;
    uu(i, 0, N){
        if(bk[i] == 0 and d[i] < mind){
            mind = d[i];
            re = i;
        }
    }
    bk[re] = 1;
    return re;
}

void init(){
    memset(bk, 0, sizeof(bk));
   uu(i, 0, N) d[i] = INT_MAX;
   d[S] = 0;
    // pre don't need to init;
}

void Dijkstra(){
    init();
    uu(i, 0, N){
        int u = nextu();
        uu(j, 0, node[u].edge.size()){
            int to = node[u].edge[j].to, dis = node[u].edge[j].dis;
            int newdis = d[u] + dis;
            if(newdis < d[to]){
                d[to] = newdis;
                pre[to].clear();
                pre[to].push_back(u);
            }
            else if(newdis == d[to]){
                pre[to].push_back(u);
            }
        }
    }
}

vector<vector<int>> re;
vector<int> tmp;

void dfs(int idx){
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
        dfs(from);
    }

    bk[idx] = 0;
    tmp.pop_back();
}

int sumcost(vector<int> &v){
    int re = 0;
    uu(i, 0, v.size()-1){
        int from = v[i], to = v[i+1];
        uu(j, 0, node[from].edge.size()){
            if(to == node[from].edge[j].to){
                re += node[from].edge[j].cost;
                break;
            }
        }
    }
    return re;
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> M >> S >> D;

    uu(i, 0, M){
        int x, y, dis, cost;
        cin >> x >> y >> dis >> cost;
        node[x].edge.push_back(Edge(x, y, dis, cost));
        node[y].edge.push_back(Edge(y, x, dis, cost));
    }

    Dijkstra();

    memset(bk, 0, sizeof(bk));

    dfs(D);

    int mincost = INT_MAX;
    vector<int> minpath;
    uu(i, 0, re.size()){
        int cost = sumcost(re[i]);
        if(cost < mincost){
            mincost = cost;
            minpath = re[i];
        }
    }

    dd(i, minpath.size()-1, -1){
        cout << minpath[i] << " ";
    }
    cout << d[D] << " ";
    cout << mincost << endl;


    return 0;
}