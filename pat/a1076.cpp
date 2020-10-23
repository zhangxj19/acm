// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
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

const int maxn = 1001;

int N, L, K;

struct Node{
    int d;
    vector<int> c; // followers = children
}node[maxn];



int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> L;
    uu(i, 1, N+1){
        int m;
        cin >> m;
        uu(j, 0, m){
            int x;
            cin >> x;
            node[x].c.push_back(i); 
        }
    }

    #ifdef DEBUG
    uu(i, 1, N+1){
        pf("(%d, ): ", i);
        uu(j, 0, node[i].c.size()){
            int child = node[i].c[j];
            pf("%d ", child);
        }
        cout << endl;

    }
    #endif

    cin >> K;
    uu(i, 0, K){
        int x;
        cin >> x;
        // bfs
        // unordered_set<int> S;
        int bk[maxn];
        uu(j, 1, N+1) bk[j] = 0;
        // S.clear();
        queue<pair<int, int>> Q; // node and dep
        Q.push(make_pair(x, 0));
        // S.insert(x);
        bk[x] = 1;
        int re = 0;
        while(!Q.empty()){
            pair<int, int> now = Q.front(); Q.pop();

            if(now.first != x and now.second <= L) re++;

            uu(j, 0, node[now.first].c.size()){
                int to = node[now.first].c[j];
                // if(S.find(to) == S.end()){
                if(bk[to] == 0){
                    bk[to] = 1;
                    // S.insert(to);
                    Q.push(make_pair(to, now.second+1));
                }
            }
        }
        cout << re << endl;

    }

    return 0;
}