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
const int maxn = 1e5 + 1;

int n, a[maxn];

void solve(int n, int isprint){
    // a[1, n]
    for(int i = 1; i + 2 <= n; i+=2){
        int t = a[i] ^ a[i+1] ^ a[i+2];
        a[i] = a[i+1] = a[i+2] = t;
        if(isprint)
        cout << i << " " << i+1 << " " << i+2 << endl;
    }

    // a[n-1] is answer

    for(int i = 1; i < n; i += 2){
        a[i] = a[i+1] = a[n];
        if(isprint)
        cout << i << " " << i+1 << " " << n << endl;
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
    cin >> n;
    uu(i, 1, n+1){
        cin >> a[i];
    }

    if(n % 2 == 1){
        cout << "YES" << endl;
        cout << n-1 << endl;
        solve(n, 1);
    }
    else{
        solve(n-1, 0);
        if(a[n] == a[n-1]){
            cout << "YES" << endl;
            cout << n-2 << endl;
            solve(n-1, 1);
        }
        else{
            cout << "NO" << endl;
        }
        
    }

    
    return 0;
}