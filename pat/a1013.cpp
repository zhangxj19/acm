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
const int maxn = 1000;

int N, M, K;

struct Node{
    int d;
    vector<int> n; // neighbor
}node[maxn];

int bk[maxn];

void dfs(int x){
    bk[x] = 1;
    uu(i, 0, node[x].n.size()){
        int to = node[x].n[i];
        if(bk[to] == 0) dfs(to);
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> M >> K;
    uu(i, 0, M){
        int x, y;
        cin >> x >> y;
        node[x].n.push_back(y);
        node[y].n.push_back(x);
    }
    #ifdef DEBUG
    uu(i, 1, N+1){
        pf("%d: ", i);
        uu(j, 0, node[i].n.size()){
            pf("%d ", node[i].n[j]);
        }
        cout << endl;
    }
    #endif
    uu(i, 0, K){
        memset(bk, 0, sizeof(bk));
        int x;
        cin >> x;
        bk[x] = 1;
        int re = 0;
        uu(j, 1, N+1){
            if(bk[j] == 0){
                dfs(j);
                re++;
            }
        }
        cout << re - 1 << endl;
    }

    return 0;
}