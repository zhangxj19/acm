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

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

const int maxn = 1010, maxm = 1e4+10, INF = 1e9;
int n, m, s, t;

struct Edge{
    int f, t, d;
    Edge(int f, int t, int d):f(f), t(t), d(d){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];

int bk[maxn], d[maxn], pre[maxn];

struct cmp{
    bool operator () (const int &i1, const int &i2){
        if(bk[i1] != bk[i2]) return bk[i1] > bk[i2];
        else return d[i1] > d[i2];
    }
};

typedef pair<int, int> P;

void dijkstra(){
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(d[s], s));
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int from = p.second;
        for(const auto& edge: node[from].edge){
            int to = edge.t, newdis = d[from] + edge.d;
            if(newdis < d[to]){
                d[to] = newdis;
                pq.push(make_pair(d[to], to));
                pre[to] = from;
            }
            else if (newdis == d[to] and from < pre[to]){
                pre[to] = from;
            }
        }
    }
}



void dfs(int idx){

    if(idx == s){
        cout << idx << " ";
        return ;
    }

    dfs(pre[idx]);
    cout << idx << " ";

    return ;
}   


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n >> m >> s >> t){
        uu(i, 1, n+1) node[i].edge.clear();
        memset(bk, 0, sizeof(bk));
        fill(d, d+maxn, INF);
        d[s] = 0;
        uu(i, 1, n+1) pre[i] = i;

        uu(i, 0, m){
            int x, y, d;
            cin >> x >> y >> d;
            node[x].edge.push_back(Edge(x, y, d));
            node[y].edge.push_back(Edge(y, x, d));
        }

        dijkstra();

        if(d[t] == INF){
            cout << "can't arrive" << endl;
        }
        else{
            cout << d[t] << endl;
            dfs(t);
            cout <<endl;
        }
    }
    

    
    return 0;
}