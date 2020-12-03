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
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;
const int maxn = 201;
int N, M, K, mp[maxn][maxn];

// struct Edge{
//     int d;
//     int f, t;
//     Edge(int f, int t, int d):f(f), t(t), d(d){}
// };
// vector<Edge> edge;

// struct Node{
//     int d;
//     vector<int> n;
// };
// vector<Node> node;

// void add_edge(int x, int y, int d){
//     node[x].n.push_back(edge.size());
//     edge.push_back(Edge(x, y, d));
// }


void solve(){
    cin >> N >> M;
    // node.clear();
    // node.resize(N+1);
    // edge.clear();

    uu(i, 0, M){
        int x, y, d;
        cin >> x >> y >> d;
        // add_edge(x, y, d);
        mp[x][y] = d;
        mp[y][x] = d;
        // mp[y][x] = d;
    }    
    cin >> K;
    int re = INT_MAX, reid;
    uu(i, 1, K+1){
        int n;
        vector<int> a;
        cin >> n;
        a.resize(n);
        
        set<int> S;
        uu(j, 0, n){
            cin >> a[j];
            S.insert(a[j]);
        }
        int dis = 0, cycle = true, simple = true, reachable = true;
        uu(j, 1, n){
            int from = a[j-1], to = a[j];
            if(mp[from][to] == 0){
                cycle = false;
                reachable = false;
            }
            else dis += mp[from][to];
        }
        if(a[0] != a[a.size()-1]) cycle = false;
        if(S.size() != N) simple = false;
        if(a.size() < N-1) cycle = false;
        if(S.size() < N) cycle = false;
        if(a.size() > N+1) simple = false;
        if(cycle){
            if(dis < re){
                re = dis;
                reid = i;
            }
        }
        if(reachable)
            cout << "Path " << i << ": " << dis << " "; 
        else
            cout << "Path " << i << ": " << "NA" << " "; 
        if(!cycle){
            cout << "(Not a TS cycle)" << endl;
        }
        else if(cycle and !simple){
            cout << "(TS cycle)" << endl;
        }
        else{
            cout << "(TS simple cycle)" << endl;
        }

    }
    cout << "Shortest Dist("<< reid << ") = "  << re << endl;
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
    solve();
    
    return 0;
}