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
const int maxn = 1e4+1;
int N, a[maxn], Q, n;

int f(int x){
    if(x == a[x]) return x;
    else{
        int F = f(a[x]);
        a[x] = F;
        return F;
    }
}

void Union(int x, int y){
    int F1 = f(x), F2 = f(y);
    if(F1 != F2){
        a[F2] = F1;
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
    cin >> N;
    uu(i, 0, maxn) a[i] = i;
    uu(i, 0, N){
        int k, x;
        cin >> k;
        cin >> x;        
        n = _max(n, x);
        uu(j, 0, k-1){
            int y;
            cin >> y;
            Union(x, y);
            n = _max(n, y);
        }        
    }
    #ifdef DEBUG2
    uu(x, 1, n+1){
        pf("(%d, %d)\n", x, f(x));
    }
    #endif
    set<int> S;
    uu(x, 1, n+1){
        int F = f(x);
        S.insert(F);
    }   
    cout << S.size() << " " << n << endl;
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x  >> y;
        if(f(x) == f(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}