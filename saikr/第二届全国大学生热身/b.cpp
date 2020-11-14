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
const int maxn = 2010;

ll n, m , k, a[maxn];

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
    cin >> n >> m >> k;
    uu(i, 0, n){
        cin >> a[i];
    }
    vector<ll> remain;
    ll ans = 0, strike = 0;
    for(ll i = 0; i < n; i += k){
        // a[i, i+k)
        if(strike >= m) break;
        else strike++;
        ll maxe = 0, maxi = i;
        for(ll j = i; j < i + k and j < n; ++j) if(a[j] > maxe) maxe = a[maxi=j];
        ans += maxe;
        
        for(ll j = i; j < i + k and j < n; ++j) if(j != maxi) remain.push_back(a[j]);
    }

    ll remaine = m - (ll)ceil((n+0.0)/k);
    // ll remaine = m - (n%k == 0 ? n/k : n/k+1);
    sort(remain.begin(), remain.end(), greater<ll>());

    for(ll i = 0; i < remaine; ++i){
        ans += remain[i];
    }

    cout << ans << endl;

    return 0;
}