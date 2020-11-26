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
const int maxn = 1e5+1;
int N;
vector<int> a;

bool cmp(const int& i1, const int& i2){
    return i1 > i2;
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
    cin >> N;
    a.resize(N);
    uu(i, 0, N) cin >> a[i];
    // sort(a.begin(), a.end(), greater<int>());
    sort(a.begin(), a.end());

    #ifdef DEBUG
    uu(i, 0, N) pf("(%d, %d) ", a[i], i);
    cout << endl;
    #endif
    int ans = N;
    while(ans){
        if(a[N - ans] > ans) break;
        else ans--;
    }
    cout << ans << endl;

    // bf
    // int ans = 0;
    // uu(x, 0, N+1){
    //     auto idx = lower_bound(a.begin(), a.end(), x, cmp);
    //     int dis = idx - a.begin();
    //     if(x >= dis) ans = _max(ans, dis);
    // }
    // uu(i, 1, N){
    //     if(a[i] != a[i-1]){
    //         if(a[i] >= i) ans = _max(ans, i);
    //     }
    // }
    // cout << ans << endl;

    
    return 0;
}