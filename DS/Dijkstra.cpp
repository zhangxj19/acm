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

using namespace std;

namespace gf{
    const int maxn = 510;

    int N, M, S, E;
    struct Edge{
        int dis, cost;
        int from, to;
        Edge(int from, int to, int dis){
            this->from = from;
            this->to = to;
            this->dis = dis;
        }
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

        void init(){
            memset(bk, 0, sizeof(bk));
            fill(dis, dis+maxn, INT_MAX);
            dis[S] = 0;
        }

        void Dijkstra(){
            init();
            uu(i, 0, N){
                int from = nextu();
                uu(j, 0, node[from].edge.size()){
                    int to = node[from].edge[j].to;
                    int newdis = dis[from] + node[from].edge[j].dis;
                    if(newdis < dis[to]){
                        dis[to] = newdis;
                        pre[to].clear();
                        pre[to].push_back(from);
                    }
                    else if(newdis == dis[to]){
                        pre[to].push_back(from);
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
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);

    return 0;
}