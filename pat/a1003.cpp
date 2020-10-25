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

// #define DEBUG

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
int N, M, C1, C2, r[maxn]; //rescue

struct Edge{
    int from, to, w;
    Edge(int from, int to, int w):from(from), to(to), w(w){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];

int bk[maxn], d[maxn], t[maxn];

int nextu(){
    // if re == -1, no candidate any more
    int mind = INT_MAX, re = -1;
    uu(i, 0, N){
        if(bk[i] == 0 and d[i] < mind){
            mind = d[i];
            re = i;
        }
    }
    bk[re] = 1;
    return re;
}

int nums[maxn];

void Dijkstra(){
    uu(i, 0, N){
        bk[i] = 0;
        d[i] = INT_MAX;
        t[i] = 0;
        nums[i] = 0;
    }
    d[C1] = 0;
    t[C1] = r[C1];
    nums[C1] = 1;


    uu(i, 0, N){
        int u = nextu();
        uu(j, 0, node[u].edge.size()){
            int to = node[u].edge[j].to, w = node[u].edge[j].w;
            int dis = d[u] + w;
            if(dis <= d[to]){
                d[to] = dis;
                t[to] = _max(t[to], r[to] + t[u]);
                nums[to] += nums[u];
            }
            // if(dis < d[to]){
            //     d[to] = dis;
            //     t[to] = r[to] + t[u];
            //     nums[to] = nums[u];
            // }
            // else if(dis == d[to]){
            //     t[to] = _max(t[to], r[to] + t[u]);
            //     nums[to] += nums[u];
            // }
        }
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> M >> C1 >> C2;
    uu(i, 0, N){
        cin >> r[i];
    }
    uu(i, 0, M){
        int x, y, l;
        cin >> x >> y >> l;
        node[x].edge.push_back(Edge(x, y, l));
        node[y].edge.push_back(Edge(y, x, l));
    }


    Dijkstra();
    #ifdef DEBUG
    uu(i, 0, N){
        cout << d[i] << " ";
    }
    cout << endl;
    #endif
    cout << nums[C2] << " " << t[C2] << endl;

    return 0;
}