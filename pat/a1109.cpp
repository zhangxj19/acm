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
#define lowbit(x) (x&(-x));

using namespace std;
const int maxn = 1e4+1;

int N, K, n, r;
struct Node{
    string name;
    int h;
}node[maxn];

bool cmp(Node &n1, Node &n2){
    if(n1.h != n2.h) return n1.h > n2.h;
    else return n1.name < n2.name;
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

    cin >> N >> K;

    uu(i, 0 , N){
        cin >> node[i].name >> node[i].h;
    }

    sort(node, node+N, cmp);

    n = N / K;
    r = N % K;

    // K rows, n people per row, n+r people at last row;

    vector<vector<string>> ans(K);

    // last row;
    // int mid = (n+r) / 2 + 1, d = -1; // direction
    ans[0].push_back(node[0].name);
    for(int i = 1; i < n+r; ++i){
        // int offset = 
        if(i % 2 == 1){
            ans[0].insert(ans[0].begin(), node[i].name);
        }
        else{
            ans[0].push_back(node[i].name);
        }
    }

    // next rows
    int p = n+r;
    for(int i = 1; i < K; ++i){
        ans[i].push_back(node[p++].name);
        for(int j = 1; j < n; ++j){
            if(j % 2 == 1) ans[i].insert(ans[i].begin(), node[p++].name);
            else ans[i].push_back(node[p++].name);
        }
    }

    uu(i, 0, K){
        uu(j, 0, ans[i].size()){
            if(j == 0) cout << ans[i][j];
            else cout << " " << ans[i][j];
        }
        cout << endl;
    }



    


    return 0;
}