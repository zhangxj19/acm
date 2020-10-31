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

const int maxn = 110, P = 1e5, maxm = 510;
string INF, zero;
int N, M;

struct Edge{
    int f, t;
    string d;
    Edge(int f, int t, string d):f(f), t(t), d(d){};
};

vector<Edge> edge;

struct Node{
    int d;
    vector<int> edge;
}node[maxn];

void addedge(int from, int to, string d){
    node[from].edge.push_back(edge.size());
    edge.push_back(Edge(from, to ,d));
}

int bk[maxn];
string d[maxn];

void init(){
    memset(bk, 0, sizeof(bk));
    INF.clear();
    zero.clear();
    uu(i, 0 ,maxm){
        INF += "1";
        zero += "0";
    }
    uu(i, 1, maxn){
        d[i] = INF;
    }
    d[0] = zero;
    edge.clear();
    uu(i, 0, N){
        node[i].edge.clear();
    }   
}

string add(const string &s1, const string &s2){
    string re;
    uu(i, 0, maxm){
        if(s1[i] == '1' or s2[i] == '1'){
            re += "1";
        }
        else{
            re += "0";
        }
    }
    return re;
}

typedef pair<string, int> PR;

void Dijkstra(int s){
    priority_queue<PR, vector<PR>, greater<PR>> pq;
    pq.push(make_pair(d[s], s));
    while(!pq.empty()){
        PR p = pq.top(); pq.pop();
        int from = p.second;
        for(const auto & id : node[from].edge){
            int to = edge[id].t;
            string newdis = add(d[from], edge[id].d);
            #ifdef DEBUG
            pf("f=%d, t=%d\nd[from]=%s\nedge.d=%s\nnewdis=%s\n", from, to, d[from].c_str(), edge[id].d.c_str(), newdis.c_str());
            #endif
            if(newdis < d[to]){
                d[to] = newdis;
                pq.push(make_pair(d[to], to));
            }
        }
    }
}


ll _pow(int k){
    ll re = 1;
    uu(i, 0, k){
        re = (re << 1) % P;
    }
    return re;
}

ll _value(const string &d){
    ll re = 0;
    uu(k, 0, maxm){
        int i = maxm-1-k;
        if(d[i] == '1'){
            re += _pow(k);
            re %= P;
        }
    }
    return re;
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> N >> M){
        init();
        uu(k, 0, M){
            int x, y;
            cin >> x >> y;
            string tmp = zero;

            tmp.replace(tmp.begin()+maxm-1-k, tmp.begin()+maxm-k, "1");
            #ifdef DEBUG
            cout << tmp << endl;
            #endif
            addedge(x, y, tmp);
            addedge(y, x, tmp);
        }
        #ifdef DEBUG
        uu(i, 0, N){
            pf("%d: ", i);
            for(const auto& edge: node[i].edge){
                pf("%d ", edge.t);
            }
            cout <<endl;
        }
        #endif

        Dijkstra(0);

        #ifdef DEBUG
        cout << "dis" << endl;
        uu(i, 0, N){
            cout << d[i] << endl;
        }
        #endif

        uu(i, 1, N){
            if(d[i] == INF) cout << -1 << endl;
            else cout << _value(d[i]) << endl;
        }
    
    
    }
    return 0;
}