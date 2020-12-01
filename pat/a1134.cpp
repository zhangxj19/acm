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
const int maxn = 1e4+1;

int N, M, K;
// vector<vector<int>> mp;
struct Node{
    vector<int> n;
}node[maxn];
vector<int> d;

int all_zero(vector<int> & v){
    for(auto & it: v){
        if(it != 0) return false;
    }
    return true;
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
    d.resize(N);
    // mp.resize(N, vector<int>(N, 0));
    uu(i, 0, M){
        int x, y;
        cin >> x >> y;
        // mp[x][y] = 1;
        // mp[y][x] = 1;
        node[x].n.push_back(y);
        node[y].n.push_back(x);
        d[x]++;
        d[y]++;
    }

    cin >> K;
    while(K--){
        int n;
        cin >> n;
        vector<int> v;
        v.resize(n);
        uu(i, 0, n){
            cin >> v[i];
        }

        vector<int> tmp_d(d);
    
        for(auto& from: v){
  
            for(auto & to : node[from].n){
                if(tmp_d[to] > 0){
                    tmp_d[from]--;
                    tmp_d[to]--;
                }
            }
         
        }

        if(all_zero(tmp_d)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }


    return 0;
}