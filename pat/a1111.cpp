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
const int maxn = 500 + 1, INF=1e9;
int N, M, S, E, d[maxn], b[maxn];
vector<int> pre[maxn];

struct Edge{
    int l, t, from, to;
    Edge(int from, int to, int l, int t):from(from), to(to), l(l), t(t){}
};
vector<Edge> edge;

struct Node{
    vector<int> e;
}node[maxn];

void addEdge(int x, int y, int l, int t){
    node[x].e.push_back(edge.size());
    edge.push_back(Edge(x, y, l, t));
}

#define pii pair<int, int>

void dijkstra(int s, int isd){

    fill(d, d+N, INF);
    d[s] = 0;


    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int from = pq.top().second; pq.pop();
        // #ifdef DEBUG
        // pf("check %d\n", from);
        // #endif
        uu(j, 0, node[from].e.size()){
            int eid = node[from].e[j], to = edge[eid].to;
            int newdis; 
            if(isd) newdis = d[from] + edge[eid].l;
            else newdis = d[from] + edge[eid].t; 
            if(newdis < d[to]){
                d[to] = newdis;
                pre[to].clear();
                pre[to].push_back(from);
                pq.push(make_pair(d[to], to));
            }
            else if(newdis == d[to]){
                pre[to].push_back(from);
            }
        }
    }
}

vector<vector<int>> re;
vector<int> tmp;
void _dfs(int x){
    b[x] = 1;

    tmp.push_back(x);

    if(x == S){
        re.push_back(tmp);

        b[x] = 0;
        tmp.pop_back();
        return;
    }

    for(int& from: pre[x]) if(b[from] == 0) _dfs(from);
        

    b[x] = 0;
    tmp.pop_back();
    return ;
}

void dfs(int x){
    memset(b, 0, sizeof(b));
    re.clear();
    tmp.clear();
    _dfs(x);
}

int sumtime(vector<int> &v){
    int re = 0;
    for(int i = v.size()-1; i > 0; --i){
        int from = v[i], to = v[i-1];
        uu(j, 0, node[from].e.size()){
            int eid = node[from].e[j];
            if(edge[eid].to == to){
                re += edge[eid].t;
                break;
            }

        }
    }
    return re;
}

int issame(vector<int> &v1, vector<int> &v2){
    if(v1.size() != v2.size()) return false;
    else{
        uu(i, 0, v1.size()){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
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
    cin >> N >> M;
    uu(i, 0, M){
        int x, y, z, l, t;
        cin >> x >> y >> z >> l >> t;
        addEdge(x, y, l, t);
        if(z == 0){
            addEdge(y, x, l, t);
        }

    }
    cin >> S >> E;

    vector<vector<int>> rel, ret;
    dijkstra(S, 1);
    dfs(E);
    rel = re;
    int mind = d[E];

    vector<int> mintre;
    int mint = INF;
    for(auto& x : rel){
        int t = sumtime(x);
        if(t < mint){
            mintre = x;
            mint = t;
        }
    }

    #ifdef DEBUG
    cout << endl;
    uu(i, 0, rel.size()){
        uu(j, 0, rel[i].size()){
            cout << rel[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(auto& x : mintre){
        cout << x << " ";
    }
    cout << endl;
    #endif

    dijkstra(S, 0);
    dfs(E);
    ret = re;

    mint = d[E];

    vector<int> minnre;
    int minn = INF;
    for(auto & x : ret){
        int n = x.size();
        if(n < minn){
            minn = n;
            minnre = x;
        }
    }

    #ifdef DEBUG
    cout << endl;
    uu(i, 0, rel.size()){
        uu(j, 0, rel[i].size())
        {
            cout << rel[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for(auto& x : minnre){
        cout << x << " ";
    }
    cout << endl;
    #endif

    if(!issame(mintre, minnre)){
        cout << "Distance = " << mind << ": ";
        for(int size = mintre.size(), i = size-1; i > -1; --i){
            if(i == size-1) cout << mintre[i];
            else cout << " -> " << mintre[i];
        }
        cout  << endl;

        cout << "Time = " << mint << ": ";
        for(int size = minnre.size(), i = size-1; i > -1; --i){
            if(i == size-1) cout << minnre[i];
            else cout << " -> " << minnre[i];
        }
        cout  << endl;
    }
    else{
        cout << "Distance = "<<mind<<"; Time = "<<mint<<": ";
        for(int size = minnre.size(), i = size-1; i > -1; --i){
            if(i == size-1) cout << minnre[i];
            else cout << " -> " << minnre[i];
        }
        cout  << endl;       
    }

    


    
    return 0;
}