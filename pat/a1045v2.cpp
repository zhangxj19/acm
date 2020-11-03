// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set


/*
在“最喜欢的颜色”范围内的颜色亦加入LIS数组， 需要通过rk[a[i]]判断a[i]是否是最喜欢的颜色, 否则当不喜欢的颜色数量超过喜欢颜色的数量时LIS计数
会成为不喜欢颜色的序列长度
*/
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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxn = 210, maxl = 1e4+100;
int n, m, l, rk[maxn], a[maxl], dp[maxl]; // less is better

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    fill(rk, rk+maxn, INT_MAX);
    cin >> n;
    cin >> m;
    uu(i, 0, m){
        int v;
        cin >> v;
        rk[v] = i;
    }
    cin >> l;

    uu(i, 0, l){
        cin >> a[i];
    }
    int ans = -1;
    fill(dp, dp+maxl, 1);
    uu(i, 0, l){
        uu(j, 0, i){
            if(rk[a[j]] != INT_MAX and rk[a[j]] <= rk[a[i]] and dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        ans = _max(dp[i], ans);
    }
    #ifdef DEBUG
    uu(i, 0, l){
        pf("%d ", dp[i]);
    }
    cout << endl;
    #endif
    
    cout << ans << endl;
    return 0;
}