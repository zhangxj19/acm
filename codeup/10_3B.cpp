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

#define DEBUG

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

int n, m, *bk;

struct Node{
    int d;
    unordered_set<int> n; // neighbor
}*node;

void dfs(int x){
    bk[x] = 1;
    for(const auto & it: node[x].n){
        if(bk[it] == 0) dfs(it);
    }
}

int ifYes(){
    uu(i, 1, n+1){
        if(bk[i] == 0) return false;
    }
    return true;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    
    while(1){
        cin >> n >> m;
        if(n == 0) break;
        node = new Node[n+1];
        bk = new int[n+1];
        memset(bk, 0, sizeof(int) * (n+1));
        uu(i, 0, m){
            int x, y;
            cin >> x >> y;
            node[x].n.insert(y);
            node[y].n.insert(x);
        }
        dfs(1);
        if(ifYes()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

    return 0;
}