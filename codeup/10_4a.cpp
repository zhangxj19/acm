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

const int maxn = 50, INF = 1e9;
int n, s;

struct Edge{
    int f, t, d;
    Edge(int f, int t, int d):f(f), t(t), d(d){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];

int bk[maxn], d[maxn];

void init(){
    memset(bk, 0, sizeof(bk));
    fill(d, d+maxn, INF);
    d[s] = 0;
}

struct cmp{
    bool operator () (const int &i1, const int &i2){
        if(bk[i1] != bk[i2]) return bk[i1] > bk[i2];
        else return d[i1] > d[i2];
    }
};

void Dijkstra(){
    init();
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(s);
    uu(i, 0, n){
        int from = pq.top(); pq.pop(); bk[from] = 1;
        for(const auto & edge : node[from].edge){
            int to = edge.t, newdis = d[from] + edge.d;
            if(newdis < d[to]){
                d[to] = newdis;
                pq.push(to);
            }
        }
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> n >> s;
    uu(from, 0, n){
        uu(to, 0, n){
            int d;
            cin >> d;
            if(d > 0) node[from].edge.push_back(Edge(from, to, d));
        }
    }

    Dijkstra();
    uu(i, 0, n){
        if(i != s){
            if(d[i] == INF){
                cout << -1 << " ";
            }
            else{
                cout << d[i] << " ";
            }
        }
    }
    cout << endl;
    
    return 0;
}