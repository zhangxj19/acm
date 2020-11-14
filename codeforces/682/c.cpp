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

// #define DEBUG
// #define LOCAL

using namespace std;
const int maxn = 101, maxm = 101;
int t, n, m, a[maxn][maxm], bk[maxn][maxn];

int dr[4][2] = {
    {-1, 0},
    {+1, 0},
    {0, +1},
    {0, -1},
};

int atbound(int i , int j){
    return (0 <= i and i < n and 0 <= j and j < m);
}

int bad(int i , int j, int value){
    for(int d = 0; d < 4; d++){
        int x=  i + dr[d][0], y = j + dr[d][1];
        if(atbound(x, y) and a[x][y] == value) return 1;
    }
    return 0;
}

int biggest(int i , int j, int value){
    for(int d = 0; d < 4; d++){
        int x=  i + dr[d][0], y = j + dr[d][1];
        if(atbound(x, y) and a[x][y] > value) return 0;
    }
    return 1;
}

bool isfind;

void dfs(int i, int j){
    if(isfind) return;

    bk[i][j] = 1;

    if(i == n-1 and j == m-1 and !bad(i, j, a[i][j])){
        isfind = 1;

        bk[i][j] = 0;
        return ;
    }

    if(!bad(i, j, a[i][j])){
        for(int d = 0; d < 4; d++){
            int x = i+dr[d][0], y = j+dr[d][1];
            if(atbound(x, y) and bk[x][y] == 0){
                dfs(x, y);
            }
        }       
    }
    else{
        a[i][j]++;
        for(int d = 0; d < 4; d++){
            int x = i+dr[d][0], y = j+dr[d][1];
            if(atbound(x, y) and bk[x][y] == 0){
                dfs(x, y);
            }
        }
        // a[i][j]--;
        // for(int d = 0; d < 4; d++){
        //     int x = i+dr[d][0], y = j+dr[d][1];
        //     if(atbound(x, y) and bk[x][y] == 0){
        //         dfs(x, y);
        //     }
        // }        
    }

    bk[i][j] = 0;
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
    cin >> t;
    while(t--){
        memset(bk, 0, sizeof(bk));
        isfind = false;
        cin >> n >> m;
        uu(i, 0, n){
            uu(j, 0, m){
                cin >> a[i][j];
            }
        }
        // dfs(0, 0);

        #ifdef DEBUG
        cout << isfind << endl;
        #endif
        uu(i, 0, n){
            uu(j, 0, m){
                if(bad(i, j, a[i][j])){
                    a[i][j]++;
                    continue;
                }

                if(biggest(i, j, a[i][j])){
                    a[i][j]++;
                    continue;
                }

                if(!bad(i, j, a[i][j]+1)){
                    a[i][j]++;
                    continue;
                }
                
            }
        }

        uu(i, 0, n){
            uu(j, 0, m){
                if(j == 0) cout << a[i][j];
                else cout << " " << a[i][j];
            }
            cout << endl;
        }
    }

    
    
    return 0;
}