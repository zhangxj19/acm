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

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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
#define vi vector<int>
#define pii pair<int, int>

using namespace std;
const int INF = 1e9;
const int maxn = 15;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int A[maxn][maxn], B[maxn][maxn];
int n;

int check(int s){
    memset(B, 0, sizeof(B));
    rep(c, n){
        if(s & (1 << c)) B[0][c] = 1;
        else if(A[0][c] == 1) return INF; // A[0][c] = 1 and B[0][c] = 0
    }

    repu(r, 1, n){
        rep(c, n){
            int sum = 0;
            if(r-2 >= 0) sum += B[r-2][c];
            if(c-1 >= 0) sum += B[r-1][c-1];
            if(c+1 < n) sum += B[r-1][c+1];
            B[r][c] = sum % 2;
            if(A[r][c] == 1 and B[r][c] == 0) return INF;
        }
    }
    int cnt = 0;
    rep(r, n){
        rep(c, n){
            if(A[r][c] != B[r][c]) cnt++;
        }
    }
    return cnt;

}

void solve(){
    int T;
    cin >> T;
    repu(kcase, 1, T+1){
        cin >> n;
        rep(i, n){
            rep(j, n){
                cin >> A[i][j];
            }
        }
        int re = INF;
        rep(s, (1<<n)){
            int cnt = check(s);
            re = min(re, cnt);
        }
        cout << "Case " << kcase << ": ";
        if(re == INF){
            cout << -1 << endl;
        }
        else{
            cout << re << endl;
        }
    }
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