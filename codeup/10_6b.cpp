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
const int maxn = 501;
int n, m, mp[maxn][maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n >> m, !(n == 0 and m == 0)){
        int ind[maxn];
        memset(ind, 0, sizeof(ind));
        memset(mp, 0, sizeof(int) * maxn * maxn);
        uu(i, 0, m){
            int x, y;
            cin >> x >> y;
            mp[x][y] = 1;
            ind[y]++;
        }

        // 
        priority_queue<int, vector<int>, greater<int>> Q;
        vector<int> re;
        uu(i, 1, n+1) if(!ind[i]) Q.push(i);
        while(!Q.empty()){
            int from = Q.top(); Q.pop();
            re.push_back(from);

            uu(to, 1, n+1){
                if(mp[from][to] == 1){
                    ind[to]--;
                    if(!ind[to]) Q.push(to);
                }
            }
        }

        uu(i, 0, re.size()){
            if(i == 0) cout << re[i];
            else cout << " " << re[i];
        }
        cout << endl;
        
    }
    
    return 0;
}