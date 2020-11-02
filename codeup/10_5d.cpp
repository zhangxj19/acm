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

const int maxn = 101, INF = 1e9;

int n, mp[maxn][maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n, n){
        uu(i, 1, n+1){
            fill(mp[i], mp[i] + maxn, INF);
        }
        
        uu(i, 0, n*(n-1)/2){
            int x, y, d, st;
            cin >> x >> y >> d >> st;
            if(st){
                mp[x][y] = mp[y][x] = 0;
            }
            else{
                mp[x][y] = mp[y][x] = d;
            }
        }

        int bk[maxn], d[maxn];
        memset(bk, 0, sizeof(bk));
        fill(d, d + maxn, INF);
        d[1] = 0;
        int re = 0;
        uu(i, 0, n){
            int from = -1, mind = INF;
            uu(j, 1, n+1) if(d[j] < mind and bk[j] == 0) mind = d[from = j];
            if(from == -1) break;
            bk[from] = 1;
            re += d[from];
            uu(to, 1, n+1){ // update the mindis path to the current set S
                if(bk[to] == 0 and mp[from][to] < d[to]){
                    d[to] = mp[from][to];
                }
            }
        }

        cout << re << endl;

    }
    
    return 0;
}