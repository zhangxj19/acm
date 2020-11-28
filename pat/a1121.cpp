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

int N, M;

map<int, int> mp;
set<int> S;

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
    // cin >> N;
    sf("%d", &N);
    while(N--){
        int x, y;
        // cin >> x >> y;
        sf("%d%d", &x, &y);
        mp[x] = y;
        mp[y] = x;
    }
    // cin >> M;
    sf("%d", &M);
    vector<int> ans;
    while(M--){
        int x;
        // cin >> x;
        sf("%d", &x);
        S.insert(x);
    }

    for(auto& g : S){
        int p = mp[g];
        if(S.find(p) == S.end()) ans.push_back(g);
    }
    sort(ans.begin(), ans.end());
    // cout << ans.size() << endl;
    pf("%lu\n", ans.size());
    for(auto it = ans.begin(); it != ans.end(); ++it){
        // cout << setw(5) << setfill('0');
        // if(it == ans.begin()) cout << *it;
        // else cout  << " " << *it;
        if(it == ans.begin()) pf("%05d", *it);
        else pf(" %05d", *it);
    }
    // cout << endl;
    if(ans.size()) pf("\n");

    
    return 0;
}