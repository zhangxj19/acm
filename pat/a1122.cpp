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
const int maxn = 2*1e2+1;
int N, M, K;

int mp[maxn][maxn];
vector<int> circle;

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
    uu(i, 0, M){
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        mp[y][x] = 1;
    }

    cin >> K;
    while(K--){
        int n;
        cin >> n;
        circle.clear();
        uu(i, 0, n){
            int x;
            cin >> x;
            circle.push_back(x);
        }

        // test
        if(n != N+1){ // rule 1
            cout << "NO" << endl;
            continue;
        }
        else if(circle[0] != circle[n-1]){ // rule 2
            cout << "NO" << endl;
            continue;
        }

        // rule3
        // rule4
        set<int> S;
        S.insert(circle[0]);
        int is_circle = true;
        for(int i = 1; i < n; ++i){
            S.insert(circle[i]);
            if(!mp[circle[i]][circle[i-1]]){
                 is_circle = false;
                 break;
            }
        }
        if(is_circle and S.size() == N) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    
    return 0;
}