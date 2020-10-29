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

int bk[maxn], d[maxn];
vector<int> pre[maxn];

struct cmp{
    bool operator () (const int &i1, const int &i2){
        if(bk[i1] != bk[i2]) return bk[i1] > bk[i2];
        else return d[i1] > d[i2];
    }
};

void dijkstra(){
    memset(bk, 0, sizeof(bk));
    fill(d, d+maxn, INF);
    d[s] = 0;
    uu(i, 0, maxn) pre[i].clear();

    priority_queue<int, vector<int>, cmp> pq;
    pq.push(s);
    uu(i, 0, n){
        if(pq.empty()) return;
        int from = pq.top(); pq.pop(); bk[from] = 1;
        for(const auto& edge: node[from].edge){
            int to = edge.t, newdis = d[from] + edge.d;
            if(newdis < d[to]){
                d[to] = newdis;
                pq.push(to);
                pre[to].clear();
                pre[to].push_back(from);
            }
            else if (newdis == d[to]){
                pre[to].push_back(from);
            }
        }
    }
}

vector<vector<int>> re;
vector<int> tmp;

void init_dfs(){
    re.clear();
    tmp.clear();
    memset(bk, 0, sizeof(bk));
}


void _dfs(int idx){
    bk[idx] = 1;
    tmp.push_back(idx);

    if(idx == s){
        re.push_back(tmp);

        bk[idx] = 0;
        tmp.pop_back();
        return ;
    }

    uu(i, 0, pre[idx].size()){
        int to = pre[idx][i];
        if(bk[to] == 0) _dfs(to);
    }


    bk[idx] = 0;
    tmp.pop_back();
    return ;
}   

void dfs(int idx){
    init_dfs();
    _dfs(idx);
}

bool cmp(const vector<int> &v1, const vector<int> &v2){
    uu(i, 0, v1.size()){
        if(v1[i] != v2[i]) return v1[i] > v2[i];
    }
    return false;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n >> m >> s >> t){
        uu(i, 0, m){
            int x, y, d;
            cin >> x >> y >> d;
            node[x].edge.push_back(Edge(x, y, d));
            node[y].edge.push_back(Edge(y, x, d));
        }

        dijkstra();
        dfs(t);

        #ifdef DEBUG
        pf("resize = %zu\n", re.size());
        for(const auto& v : re){
            for(const auto& e : v){
                pf("%d ", e);
            }
            pf("\n");
        }
        #endif
        if(re.size() == 0){
            cout << "can't arrive" << endl;
        }
        else{
            sort(re.begin(), re.end(), cmp);
            cout << d[t] << endl;
            dd(i, re[0].size()-1, -1){
                if(i == 0) cout << re[0][i];
                else cout << re[0][i] << " ";
            }
            cout <<endl;
        }
    }
    

    
    return 0;
}