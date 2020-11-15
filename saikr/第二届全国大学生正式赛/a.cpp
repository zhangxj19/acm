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
const ll P = 1e9+7;

ll T, n, k;

int f(int n){
    if(n == 1) return 1;
    else{
        int ans = 0;
        uu(i, 1, n){
            ans += (gcd(i, n-i) == 1);
            ans %= P;
        }
        return ans;
    }
}

int g(int n){
    int ans = 0;
    uu(d, 1, n+1){
        if(n % d == 0){
            ans += f(n / d);
            ans %= P;
        }
    }
    return ans;
}

int G(int k, int n){
    if(k == 1) return f(g(n));
    else{
        if( k > 1 and k % 2 == 0){
            return g(G(k-1, n));
        }
        else if(k > 1 and k%2== 1){
            return f(G(k-1, n));
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
    cin >> T;
    while(T--){
        cin >> n >> k;
        cout << G(k, n) << endl;

    }
    return 0;
}