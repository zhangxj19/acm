// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
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

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x))

using namespace std;
const int maxn = 1e5;
int N;

struct Edge{
    int d, f, t;
    Edge(int f, int t):f(f), t(t){
        d = 1;
    }
};
vector<Edge> edge;

struct Node{
    int d;
    vector<int> n;
}node[maxn];

void add_edge(int from, int to){
    node[from].n.push_back(edge.size());
    edge.push_back(Edge(from, to));
}


vector<int> pre[maxn];
#define pii pair<int, int> // distance and index
const int INF = 1e9;
void Dijstra(int s){
    int bk[maxn] = {0}, d[maxn];
    fill(d, d+maxn, INF);
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
       pii x = pq.top(); pq.pop();
       
       int from = x.second;
       for(auto & eid : node[from].n){
            int to = edge[eid].t, newdis = x.first + edge[eid].d;
            
            if(newdis < d[to]){

                d[to] = newdis;
                pre[to].clear();
                pre[to].push_back(from);
                pq.push(make_pair(newdis, to));
            }
            else if(newdis == d[to]){
                pre[to].push_back(from);
            }
       }
    } 
}

vector<vector<int>> re;
vector<int> tmp;
int bk[maxn];
void dfs(int x, int s){
    bk[x] = 1;
    tmp.push_back(x);

    if(x == s){
        re.push_back(tmp);

        bk[x] = 0;
        tmp.pop_back();
        return;
    }

    for(auto & from : pre[x]){
        if(bk[from] == 0) dfs(from, s);
    }

    bk[x] = 0;
    tmp.pop_back();
    return;
}

unordered_map<int, int> mp;


int line_cnt(vector<int> &v){
    int re = 1;
    for(int i = 1; i < v.size(); ++i){
        if(mp[v[i]] != mp[v[i-1]]) re++;
    }
    return re;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> N;
    uu(i, 0, N){
        int line = i+1;
        int M;
        cin >> M;
        vector<int> v;
        v.resize(M);
        uu(j, 0, M){
            cin >> v[j];
            mp[v[j]] = line;
        }
        uu(j, 1, M){
            int from = v[j-1], to = v[j];
            add_edge(from, to);
            add_edge(to, from);
        }
        
    }

    int K;
    cin >> K;
    while(K--){
        int s, e;
        cin >> s >> e;


        

        Dijstra(s);
        memset(bk, 0, sizeof(bk));
        re.clear();
        tmp.clear();
        dfs(e, s);

        int mincnt = INF;
        vector<int> minre;
        for(auto & v : re){
            int cnt = line_cnt(v);
            if(cnt < mincnt){
                mincnt = cnt;
                minre = v;
            }
        }
        reverse(minre.begin(), minre.end());

        #ifdef DEBUG
        for(auto& it: minre) cout << " " << it;
        cout << endl;
        #endif
        vector<int> 




    }
    
    return 0;
}